#ifndef AIRSPEED_H
#define AIRSPEED_H

#include "std.h"

extern float airspeedMs;
extern float temperatureC;

extern void airspeedInit( void );   
extern void airspeedRead( void );   /* 60Hz */
extern void airspeedUpdate( void ); /* 10Hz  */

#endif /* AIRSPEED_H */
