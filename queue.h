#ifndef QUEUE_H
#define QUEUE_H

#include "common.h"
/* Queue Initialization */
void initQueue(struct Queue *q);

int isQueueEmpty(struct Queue *q);

int isQueueFull(struct Queue *q);
/* Insert Passenger into Queue */
int enqueue(struct Queue *q, struct Passenger p);
/* Remove Passenger from Queue */
struct Passenger dequeue(struct Queue *q);

void displayQueue(struct Queue *q);

struct Passenger collectPassengerDetails();

void addPassenger(struct Queue *q, struct Stack *s);

void bookTicket(struct Queue *q);

void cancelTicket(struct Queue *q);

#endif
