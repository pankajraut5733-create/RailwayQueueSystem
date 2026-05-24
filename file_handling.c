#include "file_handling.h"

/* ============================================================
 *  SAVE PASSENGER TO CSV FILE
 * ============================================================ */

void savePassengerToFile(struct Passenger p) {

    FILE *fp;

    fp = fopen("passengers.csv", "a");

    if (fp == NULL) {

        printf("\n  [!] File opening error.\n");

        return;
    }

    fprintf(fp,
            "%d,%s,%d,%c,%d,%s,%s\n",
            p.id,
            p.name,
            p.age,
            p.gender,
            p.trainNumber,
            p.destination,
            p.seatPref);

    fclose(fp);

    printf("\n  [+] Passenger data saved to CSV file.\n");
}