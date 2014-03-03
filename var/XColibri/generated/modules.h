/* This file has been generated from /home/lionel/paparazziAssembla/vamudes-paparazzi/conf/airframes/valkyrie.xml */
/* Please DO NOT EDIT */

#ifndef MODULES_H
#define MODULES_H

#define MODULES_IDLE  0
#define MODULES_RUN   1
#define MODULES_START 2
#define MODULES_STOP  3

#ifdef MODULES_C
#define EXTERN_MODULES
#else
#define EXTERN_MODULES extern
#endif
#include "std.h"
#include "sensors/infrared_adc.h"

#define INFRARED_ADC_UPDATE_PERIOD 0.016667
#define INFRARED_ADC_UPDATE_FREQ 60.000000


#ifdef MODULES_C

static inline void modules_init(void) {
  infrared_adc_init();
}

static inline void modules_periodic_task(void) {
  static uint8_t i1; i1++; if (i1>=1) i1=0;


  infrared_adc_update();
}

static inline void modules_event_task(void) {
}

#endif // MODULES_C

#ifdef MODULES_DATALINK_C

#include "messages.h"
#include "generated/airframe.h"
static inline void modules_parse_datalink(uint8_t msg_id __attribute__ ((unused))) {
}

#endif // MODULES_DATALINK_C

#endif // MODULES_H
