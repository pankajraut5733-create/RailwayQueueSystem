#ifndef EMERGENCY_H
#define EMERGENCY_H

#include "common.h"
/* Stack Initialization */
void initStack(struct Stack *s);

int isStackEmpty(struct Stack *s);

int isStackFull(struct Stack *s);
/* Add Emergency Passenger */
int push(struct Stack *s, struct Passenger p);
/* Serve Emergency Passenger */
struct Passenger pop(struct Stack *s);

void displayStack(struct Stack *s);

void addEmergencyPassenger(struct Stack *s);

void serveEmergencyPassenger(struct Stack *s);

#endif
