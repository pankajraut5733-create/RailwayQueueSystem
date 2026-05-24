/* ============================================================
 *  EMERGENCY PRIORITY MODULE
 *  Handles VIP and emergency passenger booking
 * ============================================================ */
#include "emergency.h"
#include "train.h"
#include "waiting_list.h"
#include "queue.h"

/* ============================================================
 *  STACK FUNCTIONS
 * ============================================================ */
/* Initialize Emergency Stack */
void initStack(struct Stack *s) {

    s->top = -1;
}

int isStackEmpty(struct Stack *s) {

    return (s->top == -1);
}

int isStackFull(struct Stack *s) {

    return (s->top == MAX_STACK - 1);
}
/* Push Emergency Passenger */
int push(struct Stack *s, struct Passenger p) {

    if (isStackFull(s))
        return 0;

    s->top++;

    s->data[s->top] = p;

    return 1;
}
/* Serve Highest Priority Passenger */
struct Passenger pop(struct Stack *s) {

    struct Passenger empty;

    strcpy(empty.name, "NONE");

    empty.id = -1;

    if (isStackEmpty(s))
        return empty;

    struct Passenger p = s->data[s->top];

    s->top--;

    return p;
}

void displayStack(struct Stack *s) {

    if (isStackEmpty(s)) {

        printf("\n  [!] No emergency passengers in priority stack.\n");
        return;
    }

    printf("\n  +----------+----------------------+-----+----------------+\n");

    printf("  | Priority |  Name                | Age |  Destination   |\n");

    printf("  +----------+----------------------+-----+----------------+\n");

    int i;

    for (i = s->top; i >= 0; i--) {

        printf("  | %-8d | %-20s | %-3d | %-14s |\n",
               s->top - i + 1,
               s->data[i].name,
               s->data[i].age,
               s->data[i].destination);
    }

    printf("  +----------+----------------------+-----+----------------+\n");

    printf("  Total emergency passengers: %d\n",
           s->top + 1);
    printf("  Emergency stack capacity left: %d\n",
       MAX_STACK - (s->top + 1));
}

/* ============================================================
 *  ADD EMERGENCY PASSENGER
 * ============================================================ */

void addEmergencyPassenger(struct Stack *s) {

    printf("\n  ============================\n");

    printf("  EMERGENCY / PRIORITY BOOKING\n");

    printf("  ============================\n");

    printf("  Type: 1=Senior Citizen  2=Medical Emergency  3=VIP\n");

    printf("  Choice: ");

    int type;

    scanf("%d", &type);

    struct Passenger p =
        collectPassengerDetails();

    p.isEmergency = 1;

    if (push(s, p) == 0) {

        printf("\n  [!] Emergency stack full.\n");
    }

    else {

        printf("\n  [+] Emergency passenger added.\n");

        printf("  Passenger ID : P%d\n", p.id);
    }
}

/* ============================================================
 *  SERVE EMERGENCY PASSENGER
 * ============================================================ */

void serveEmergencyPassenger(struct Stack *s) {

    printf("\n  ============================\n");

    printf("  SERVE EMERGENCY PASSENGER\n");

    printf("  ============================\n");

    if (isStackEmpty(s)) {

        printf("\n  [!] No emergency passengers.\n");

        return;
    }

    struct Passenger p = pop(s);

    int idx = findTrain(p.trainNumber);

    if (idx == -1 ||
        trains[idx].availableSeats <= 0) {

        printf("\n  [!] No seats available.\n");

        addToWaitingList(p);

        return;
    }

    trains[idx].availableSeats--;

    printf("\n  ============================================\n");

    printf("      EMERGENCY TICKET CONFIRMED\n");

    printf("  ============================================\n");

    printf("  Passenger ID   : P%d\n", p.id);

    printf("  Name           : %s\n", p.name);

    printf("  Age            : %d\n", p.age);

    printf("  Train          : %d (%s)\n",
           trains[idx].trainId,
           trains[idx].trainName);

    printf("  From           : %s\n",
           trains[idx].source);

    printf("  To             : %s\n",
           p.destination);

    printf("  Ticket Price   : Rs %.2f\n",
           trains[idx].ticketPrice);

    printf("  Seats Left     : %d\n",
           trains[idx].availableSeats);

    printf("  ============================================\n");

    printf("  [SUCCESS] Emergency ticket booked!\n");
}
