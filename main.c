/* ============================================================
 *  MAIN MODULE
 *  Controls the Railway Queueing System
 * ============================================================ */
#include "common.h"
#include "queue.h"
#include "emergency.h"
#include "waiting_list.h"
#include "train.h"

int passengerIDCounter = 1000;

/* ============================================================
 *  DISPLAY MENU
 * ============================================================ */

/* Display Main Menu */
void displayMenu() {

    printf("\n");

    printf("  =====================================================\n");

    printf("         RAILWAY QUEUEING SYSTEM — MAIN MENU\n");

    printf("  =====================================================\n");

    printf("   1. Add Passenger (Normal)\n");

    printf("   2. Book Ticket (Serve Queue)\n");

    printf("   3. View Booking Queue\n");

    printf("   4. View Waiting List\n");

    printf("   5. Add Emergency / Priority Passenger\n");

    printf("   6. Serve Emergency Passenger\n");

    printf("   7. View Emergency Priority List\n");

    printf("   8. Cancel Ticket\n");

    printf("   9. Display Train Details\n");

    printf("   0. Exit\n");

    printf("  =====================================================\n");

    printf("   Enter your choice: ");
}

/* ============================================================
 *  MAIN FUNCTION
 * ============================================================ */

/* Main Driver Function */
int main() {

    struct Queue bookingQueue;

    struct Stack emergencyStack;

    initQueue(&bookingQueue);

    initStack(&emergencyStack);

    initTrains();

    printf("\n");

    printf("  =====================================================\n");

    printf("       WELCOME TO RAILWAY QUEUEING SYSTEM\n");

    printf("       B.Tech CSE Mini Project | C Language\n");

    printf("  =====================================================\n");

    int choice;

    do {

        displayMenu();

        scanf("%d", &choice);

        switch(choice) {

            case 1:
                addPassenger(&bookingQueue,
                             &emergencyStack);
                break;

            case 2:
                bookTicket(&bookingQueue);
                break;

            case 3:
                displayQueue(&bookingQueue);
                break;

            case 4:
                displayWaitingList();
                break;

            case 5:
                addEmergencyPassenger(&emergencyStack);
                break;

            case 6:
                serveEmergencyPassenger(&emergencyStack);
                break;

            case 7:
                displayStack(&emergencyStack);
                break;

            case 8:
                cancelTicket(&bookingQueue);
                break;

            case 9:
                displayTrains();
                break;

            case 0:
                printf("\nThank You\n");
                break;

            default:
                printf("\nInvalid Choice\n");
        }

    } while(choice != 0);

    /* Free waiting list memory */

    struct WaitingNode *temp;

    while(waitingHead != NULL) {

        temp = waitingHead;

        waitingHead = waitingHead->next;

        free(temp);
    }

    return 0;
}
