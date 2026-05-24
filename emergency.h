#ifndef EMERGENCY_H
#define EMERGENCY_H

#include "common.h"

void initStack(struct Stack *s);

int isStackEmpty(struct Stack *s);

int isStackFull(struct Stack *s);

int push(struct Stack *s, struct Passenger p);

struct Passenger pop(struct Stack *s);

void displayStack(struct Stack *s);

void addEmergencyPassenger(struct Stack *s);

void serveEmergencyPassenger(struct Stack *s);

#endif