#ifndef POWER_LED_H
#define POWER_LED_H

#include "std.h"

void PowerLed_Init(void);
void PowerLed_Periodic(void);
extern uint8_t LeftWing_State, RightWing_State, Tail_State;

#endif
