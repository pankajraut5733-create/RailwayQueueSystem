#include "waiting_list.h"

/* ============================================================
 *  GLOBAL WAITING LIST VARIABLES
 * ============================================================ */

struct WaitingNode *waitingHead = NULL;

int waitingCount = 0;

/* ============================================================
 *  ADD TO WAITING LIST
 * ============================================================ */

void addToWaitingList(struct Passenger p) {

    struct WaitingNode *newNode;

    newNode =
        (struct WaitingNode *)
        malloc(sizeof(struct WaitingNode));

    if (newNode == NULL) {

        printf("\n  [!] Memory allocation failed.\n");

        return;
    }

    newNode->data = p;

    newNode->next = NULL;

    /* First node */

    if (waitingHead == NULL) {

        waitingHead = newNode;
    }

    else {

        struct WaitingNode *temp =
            waitingHead;

        while (temp->next != NULL) {

            temp = temp->next;
        }

        temp->next = newNode;
    }

    waitingCount++;

    printf("\n  [+] '%s' added to Waiting List.\n",
           p.name);

    printf("  Waiting Position : %d\n",
           waitingCount);
}

/* ============================================================
 *  REMOVE FROM WAITING LIST
 * ============================================================ */

struct Passenger removeFromWaitingList() {

    struct Passenger empty;

    strcpy(empty.name, "NONE");

    empty.id = -1;

    if (waitingHead == NULL)
        return empty;

    struct WaitingNode *temp =
        waitingHead;

    struct Passenger p =
        temp->data;

    waitingHead =
        waitingHead->next;

    free(temp);

    waitingCount--;

    return p;
}

/* ============================================================
 *  DISPLAY WAITING LIST
 * ============================================================ */

void displayWaitingList() {

    if (waitingHead == NULL) {

        printf("\n  [!] Waiting list is empty.\n");

        return;
    }

    printf("\n  +-----+----------------------+-----+----------------+\n");

    printf("  | Pos |  Name                | Age |  Destination   |\n");

    printf("  +-----+----------------------+-----+----------------+\n");

    struct WaitingNode *temp =
        waitingHead;

    int pos = 1;

    while (temp != NULL) {

        printf("  | %-3d | %-20s | %-3d | %-14s |\n",
               pos++,
               temp->data.name,
               temp->data.age,
               temp->data.destination);

        temp = temp->next;
    }

    printf("  +-----+----------------------+-----+----------------+\n");

    printf("  Total on waiting list: %d\n",
           waitingCount);
}