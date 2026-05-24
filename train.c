#include "train.h"

/* ============================================================
 *  GLOBAL TRAIN ARRAY
 * ============================================================ */

struct Train trains[MAX_TRAINS];

/* ============================================================
 *  INITIALIZE TRAINS
 * ============================================================ */

void initTrains() {

    /* Train 1 */

    trains[0].trainId = 12301;

    strcpy(trains[0].trainName,
           "Rajdhani Express");

    strcpy(trains[0].source,
           "Mumbai");

    strcpy(trains[0].destination,
           "Delhi");

    trains[0].totalSeats = 5;

    trains[0].availableSeats = 5;

    trains[0].ticketPrice = 1500.00f;

    /* Train 2 */

    trains[1].trainId = 22692;

    strcpy(trains[1].trainName,
           "Duronto Express");

    strcpy(trains[1].source,
           "Bangalore");

    strcpy(trains[1].destination,
           "Hyderabad");

    trains[1].totalSeats = 4;

    trains[1].availableSeats = 4;

    trains[1].ticketPrice = 950.00f;

    /* Train 3 */

    trains[2].trainId = 11028;

    strcpy(trains[2].trainName,
           "Chennai Mail");

    strcpy(trains[2].source,
           "Chennai");

    strcpy(trains[2].destination,
           "Kolkata");

    trains[2].totalSeats = 6;

    trains[2].availableSeats = 6;

    trains[2].ticketPrice = 1100.00f;
}

/* ============================================================
 *  FIND TRAIN
 * ============================================================ */

int findTrain(int trainId) {

    int i;

    for (i = 0; i < MAX_TRAINS; i++) {

        if (trains[i].trainId == trainId)
            return i;
    }

    return -1;
}

/* ============================================================
 *  DISPLAY TRAINS
 * ============================================================ */

void displayTrains() {

    printf("\n  +--------+--------------------+------------+------------+-------+----------+-----------+\n");

    printf("  | ID     | Name               | Source     | Dest       | Seats | Avail    | Price(Rs) |\n");

    printf("  +--------+--------------------+------------+------------+-------+----------+-----------+\n");

    int i;

    for (i = 0; i < MAX_TRAINS; i++) {

        printf("  | %-6d | %-18s | %-10s | %-10s | %-5d | %-8d | %-9.2f |\n",
               trains[i].trainId,
               trains[i].trainName,
               trains[i].source,
               trains[i].destination,
               trains[i].totalSeats,
               trains[i].availableSeats,
               trains[i].ticketPrice);
    }

    printf("  +--------+--------------------+------------+------------+-------+----------+-----------+\n");
}