/* ============================================================
 *  COMMON HEADER FILE
 *  Contains structures, constants, and global variables
 * ============================================================ */
#ifndef COMMON_H
#define COMMON_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_QUEUE   50
#define MAX_STACK   10
#define MAX_TRAINS   3
#define MAX_NAME    50
#define MAX_DEST    30

extern int passengerIDCounter;

struct Passenger {
    int id;
    char name[MAX_NAME];
    int age;
    char gender;
    int trainNumber;
    char destination[MAX_DEST];
    char seatPref[10];
    int isEmergency;
};

struct Train {
    int trainId;
    char trainName[MAX_NAME];
    char source[MAX_DEST];
    char destination[MAX_DEST];
    int totalSeats;
    int availableSeats;
    float ticketPrice;
};

struct Queue {
    struct Passenger data[MAX_QUEUE];
    int front;
    int rear;
    int size;
};

struct Stack {
    struct Passenger data[MAX_STACK];
    int top;
};

struct WaitingNode {
    struct Passenger data;
    struct WaitingNode *next;
};

extern struct Train trains[MAX_TRAINS];

extern struct WaitingNode *waitingHead;

extern int waitingCount;

#endif
