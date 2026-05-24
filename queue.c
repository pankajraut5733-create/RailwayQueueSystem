#include "queue.h"
#include "train.h"
#include "waiting_list.h"
#include "emergency.h"
#include "file_handling.h"

/* ============================================================
 *  QUEUE FUNCTIONS
 * ============================================================ */

void initQueue(struct Queue *q) {

    q->front = 0;
    q->rear  = -1;
    q->size  = 0;
}

int isQueueEmpty(struct Queue *q) {

    return (q->size == 0);
}

int isQueueFull(struct Queue *q) {

    return (q->size == MAX_QUEUE);
}

int enqueue(struct Queue *q, struct Passenger p) {

    if (isQueueFull(q))
        return 0;

    q->rear = (q->rear + 1) % MAX_QUEUE;

    q->data[q->rear] = p;

    q->size++;

    return 1;
}

struct Passenger dequeue(struct Queue *q) {

    struct Passenger empty;

    strcpy(empty.name, "NONE");

    empty.id = -1;

    if (isQueueEmpty(q))
        return empty;

    struct Passenger p = q->data[q->front];

    q->front = (q->front + 1) % MAX_QUEUE;

    q->size--;

    return p;
}

void displayQueue(struct Queue *q) {

    if (isQueueEmpty(q)) {

        printf("\n  [!] Booking queue is empty.\n");

        return;
    }

    printf("\n  +-------+----------------------+-----+----------------+-------+\n");

    printf("  |  No.  |  Name                | Age |  Destination   | Train |\n");

    printf("  +-------+----------------------+-----+----------------+-------+\n");

    int i, pos;

    for (i = 0; i < q->size; i++) {

        pos = (q->front + i) % MAX_QUEUE;

        printf("  | %-5d | %-20s | %-3d | %-14s | %-5d |\n",
               i + 1,
               q->data[pos].name,
               q->data[pos].age,
               q->data[pos].destination,
               q->data[pos].trainNumber);
    }

    printf("  +-------+----------------------+-----+----------------+-------+\n");

    printf("  Total passengers in queue: %d\n", q->size);
}

/* ============================================================
 *  PASSENGER INPUT
 * ============================================================ */

struct Passenger collectPassengerDetails() {

    struct Passenger p;

    int choice;

    p.id = passengerIDCounter++;

    printf("\n  Enter Passenger Name       : ");

    scanf(" ");

    fgets(p.name, MAX_NAME, stdin);

    p.name[strcspn(p.name, "\n")] = '\0';

    printf("  Enter Age                  : ");

    scanf("%d", &p.age);

    printf("  Enter Gender (M/F/O)       : ");

    scanf(" %c", &p.gender);

    printf("  Enter Train Number         : ");

    scanf("%d", &p.trainNumber);

    printf("  Enter Destination          : ");

    scanf(" ");

    fgets(p.destination, MAX_DEST, stdin);

    p.destination[strcspn(p.destination, "\n")] = '\0';

    printf("  Seat Preference:\n");

    printf("    1. Window\n");

    printf("    2. Aisle\n");

    printf("    3. Any\n");

    printf("  Choice: ");

    scanf("%d", &choice);

    if (choice == 1)
        strcpy(p.seatPref, "WINDOW");

    else if (choice == 2)
        strcpy(p.seatPref, "AISLE");

    else
        strcpy(p.seatPref, "ANY");

    p.isEmergency = 0;

    return p;
}

/* ============================================================
 *  ADD PASSENGER
 * ============================================================ */

void addPassenger(struct Queue *q, struct Stack *s) {

    printf("\n  ============================\n");

    printf("  ADD PASSENGER\n");

    printf("  ============================\n");

    struct Passenger p = collectPassengerDetails();

    int idx = findTrain(p.trainNumber);

    if (idx == -1) {

        printf("\n  [!] Train %d not found.\n",
               p.trainNumber);

        return;
    }

    /* Senior citizen auto priority */

    if (p.age >= 60) {

        p.isEmergency = 1;

        printf("\n  [*] Senior citizen detected.\n");

        if (push(s, p) == 0) {

            printf("  [!] Priority stack full.\n");

            if (enqueue(q, p) == 0)
                addToWaitingList(p);
        }

        return;
    }

    /* Normal booking */

    if (trains[idx].availableSeats > 0) {

        if (enqueue(q, p) == 1) {

            printf("\n  [+] Passenger registered.\n");

            printf("  Passenger ID : P%d\n", p.id);
        }

        else {

            addToWaitingList(p);
        }
    }

    else {

        printf("\n  [!] No seats available.\n");

        addToWaitingList(p);
    }
}

/* ============================================================
 *  BOOK TICKET
 * ============================================================ */

void bookTicket(struct Queue *q) {

    printf("\n  ============================\n");

    printf("  BOOK TICKET\n");

    printf("  ============================\n");

    if (isQueueEmpty(q)) {

        printf("\n  [!] No passengers in queue.\n");

        return;
    }

    struct Passenger p = dequeue(q);

    int idx = findTrain(p.trainNumber);

    if (idx == -1 || trains[idx].availableSeats <= 0) {

        printf("\n  [!] No seats available.\n");

        addToWaitingList(p);

        return;
    }

    trains[idx].availableSeats--;

    printf("\n  ============================================\n");

    printf("        TICKET BOOKING CONFIRMATION\n");

    printf("  ============================================\n");

    printf("  Passenger ID   : P%d\n", p.id);

    printf("  Name           : %s\n", p.name);

    printf("  Age            : %d\n", p.age);

    printf("  Gender         : %c\n", p.gender);

    printf("  Train          : %d (%s)\n",
           trains[idx].trainId,
           trains[idx].trainName);

    printf("  From           : %s\n",
           trains[idx].source);

    printf("  To             : %s\n",
           p.destination);

    printf("  Seat Pref      : %s\n",
           p.seatPref);

    printf("  Ticket Price   : Rs %.2f\n",
           trains[idx].ticketPrice);

    printf("  Seats Left     : %d\n",
           trains[idx].availableSeats);

    printf("  ============================================\n");

    printf("  [SUCCESS] Ticket booked successfully!\n");

    /* SAVE TO CSV FILE */

    savePassengerToFile(p);
}

/* ============================================================
 *  CANCEL TICKET
 * ============================================================ */

void cancelTicket(struct Queue *q) {

    printf("\n  ============================\n");

    printf("  CANCEL TICKET\n");

    printf("  ============================\n");

    if (isQueueEmpty(q)) {

        printf("\n  [!] Queue is empty.\n");

        return;
    }

    char cancelName[MAX_NAME];

    printf("  Enter passenger name to cancel: ");

    scanf(" ");

    fgets(cancelName, MAX_NAME, stdin);

    cancelName[strcspn(cancelName, "\n")] = '\0';

    struct Queue tempQ;

    initQueue(&tempQ);

    int found = 0;

    int trainIdx = -1;

    int i, pos;

    for (i = 0; i < q->size; i++) {

        pos = (q->front + i) % MAX_QUEUE;

        if (!found &&
            strcmp(q->data[pos].name, cancelName) == 0) {

            found = 1;

            trainIdx =
                findTrain(q->data[pos].trainNumber);
        }

        else {

            enqueue(&tempQ, q->data[pos]);
        }
    }

    if (!found) {

        printf("\n  [!] Passenger not found.\n");

        return;
    }

    *q = tempQ;

    if (trainIdx != -1)
        trains[trainIdx].availableSeats++;

    printf("\n  [+] Ticket cancelled successfully.\n");

    if (waitingHead != NULL) {

        struct Passenger next =
            removeFromWaitingList();

        if (enqueue(q, next) == 1) {

            printf("  [+] Passenger promoted from waiting list.\n");
        }
    }
}