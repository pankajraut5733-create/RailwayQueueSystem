#ifndef WAITING_LIST_H
#define WAITING_LIST_H

#include "common.h"
/* Add Passenger to Waiting List */
void addToWaitingList(struct Passenger p);
/* Remove Passenger from Waiting List */
struct Passenger removeFromWaitingList();
/* Display Waiting List */
void displayWaitingList();

#endif
