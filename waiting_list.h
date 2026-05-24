#ifndef WAITING_LIST_H
#define WAITING_LIST_H

#include "common.h"

void addToWaitingList(struct Passenger p);

struct Passenger removeFromWaitingList();

void displayWaitingList();

#endif