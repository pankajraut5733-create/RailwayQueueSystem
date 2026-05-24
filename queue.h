#ifndef QUEUE_H
#define QUEUE_H

#include "common.h"

void initQueue(struct Queue *q);

int isQueueEmpty(struct Queue *q);

int isQueueFull(struct Queue *q);

int enqueue(struct Queue *q, struct Passenger p);

struct Passenger dequeue(struct Queue *q);

void displayQueue(struct Queue *q);

struct Passenger collectPassengerDetails();

void addPassenger(struct Queue *q, struct Stack *s);

void bookTicket(struct Queue *q);

void cancelTicket(struct Queue *q);

#endif