#include "actuators.h"

#include "paparazzi.h"
#include "generated/airframe.h"

uint8_t servos_4017_idx;

#define START_TIMEOUT 0xFFFF;

void actuators_init ( void ) {
#ifdef JOHN_AP_2012
  /* select clock pin as MAT0.3 output */
  IO0DIR |= _BV(SERVO_CLOCK_PIN);
  SERVO_CLOCK_PINSEL |= SERVO_CLOCK_PINSEL_VAL << SERVO_CLOCK_PINSEL_BIT;

  /* select reset pin as GPIO output */
  IO1DIR |= _BV(SERVO_RESET_PIN);
  PINSEL2 &= ~(_BV(3)); /* P1.25-16 are used as GPIO */
  /* assert RESET */
  IO1SET = _BV(SERVO_RESET_PIN);

  /* enable match 1 interrupt */
  T0MCR |= TMCR_MR3_I;

  #ifndef SERVOS_4017_CLOCK_FALLING
    /* lower clock         */
    T0EMR &= ~TEMR_EM3;
    T0EMR |= TEMR_EMC3_2;
  #else
    /* assert clock       */
    T0EMR |= TEMR_EM3;
    /* set low on match 1 */
    T0EMR |= TEMR_EMC3_1;
  #endif

  /* set first pulse in a while */
  T0MR3 = START_TIMEOUT;

#else /*if servo_clock_remap not define*/

  /* select clock pin as MAT0.1 output */
  IO0DIR |= _BV(SERVO_CLOCK_PIN);
  SERVO_CLOCK_PINSEL |= SERVO_CLOCK_PINSEL_VAL << SERVO_CLOCK_PINSEL_BIT;

  /* select reset pin as GPIO output */
  IO1DIR |= _BV(SERVO_RESET_PIN);
  PINSEL2 &= ~(_BV(3)); /* P1.25-16 are used as GPIO */
  /* assert RESET */
  IO1SET = _BV(SERVO_RESET_PIN);

  /* enable match 1 interrupt */
  T0MCR |= TMCR_MR1_I;

  #ifndef SERVOS_4017_CLOCK_FALLING
    /* lower clock         */
    T0EMR &= ~TEMR_EM1;             
    /* set high on match 1 */
    T0EMR |= TEMR_EMC1_2;
  #else
    /* assert clock       */
    T0EMR |= TEMR_EM1;
    /* set low on match 1 */
    T0EMR |= TEMR_EMC1_1;
  #endif

  /* set first pulse in a while */
  T0MR1 = START_TIMEOUT;

#endif

  servos_4017_idx = _4017_NB_CHANNELS;
  /* Set all servos at their midpoints */
  /* compulsory for unaffected servos  */
  uint8_t i;
  for( i=0 ; i < _4017_NB_CHANNELS ; i++ )
    servos_values[i] = SERVOS_TICS_OF_USEC(1500);
  #ifdef SERVO_MOTOR
    servos_values[SERVO_MOTOR] = SERVOS_TICS_OF_USEC(SERVO_MOTOR_NEUTRAL);
  #endif
  #ifdef SERVO_MOTOR_LEFT
    servos_values[SERVO_MOTOR_LEFT] = SERVOS_TICS_OF_USEC(SERVO_MOTOR_LEFT_NEUTRAL);
  #endif
  #ifdef SERVO_MOTOR_RIGHT
    servos_values[SERVO_MOTOR_RIGHT] = SERVOS_TICS_OF_USEC(SERVO_MOTOR_RIGHT_NEUTRAL);
  #endif
  #ifdef SERVO_HATCH
    servos_values[SERVO_HATCH] = SERVOS_TICS_OF_USEC(SERVO_HATCH_NEUTRAL);
  #endif

}

uint16_t servos_values[_4017_NB_CHANNELS];


