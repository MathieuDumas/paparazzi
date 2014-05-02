/* This file has been generated from /home/lionel/paparazziProto1/conf/airframes/colibri.xml */
/* Please DO NOT EDIT */

#ifndef AIRFRAME_H
#define AIRFRAME_H

#define AIRFRAME_NAME "Colibri"
#define AC_ID 2
#define MD5SUM ((uint8_t*)"\222\052\311\042\075\064\344\045\304\052\253\162\022\357\124\010")

#define SERVOS_NB 8

#define SERVO_ESC 4
#define SERVO_ESC_NEUTRAL 1500
#define SERVO_ESC_TRAVEL_UP 0.0520833333333
#define SERVO_ESC_TRAVEL_DOWN 0.0520833333333
#define SERVO_ESC_MAX 2000
#define SERVO_ESC_MIN 1000

#define SERVO_SERVO_LEFT 1
#define SERVO_SERVO_LEFT_NEUTRAL 1500
#define SERVO_SERVO_LEFT_TRAVEL_UP 0.0416666666667
#define SERVO_SERVO_LEFT_TRAVEL_DOWN 0.0416666666667
#define SERVO_SERVO_LEFT_MAX 1900
#define SERVO_SERVO_LEFT_MIN 1100

#define SERVO_SERVO_HOR 2
#define SERVO_SERVO_HOR_NEUTRAL 1500
#define SERVO_SERVO_HOR_TRAVEL_UP 0.0416666666667
#define SERVO_SERVO_HOR_TRAVEL_DOWN 0.0416666666667
#define SERVO_SERVO_HOR_MAX 1900
#define SERVO_SERVO_HOR_MIN 1100

#define SERVO_SERVO_RIGHT 7
#define SERVO_SERVO_RIGHT_NEUTRAL 1500
#define SERVO_SERVO_RIGHT_TRAVEL_UP 0.0416666666667
#define SERVO_SERVO_RIGHT_TRAVEL_DOWN 0.0416666666667
#define SERVO_SERVO_RIGHT_MAX 1900
#define SERVO_SERVO_RIGHT_MIN 1100


#define COMMAND_THROTTLE 0
#define COMMAND_PITCH 1
#define COMMAND_YAW 2
#define COMMAND_ROLL 3
#define COMMANDS_NB 4
#define COMMANDS_FAILSAFE {0,0,0,0}


#define SECTION_MIXER 1
#define AILERON_DIFF 0
#define COMBI_SWITCH 0

#define SetActuatorsFromCommands(values) { \
  uint32_t servo_value;\
  float command_value;\
  command_value = values[COMMAND_THROTTLE];\
  command_value *= command_value>0 ? SERVO_ESC_TRAVEL_UP : SERVO_ESC_TRAVEL_DOWN;\
  servo_value = SERVO_ESC_NEUTRAL + (int32_t)(command_value);\
  actuators[SERVO_ESC] = ChopServo(servo_value, SERVO_ESC_MIN, SERVO_ESC_MAX);\
\
  Actuator(SERVO_ESC) = SERVOS_TICS_OF_USEC(actuators[SERVO_ESC]);\
\
  command_value = values[COMMAND_ROLL];\
  command_value *= command_value>0 ? SERVO_SERVO_HOR_TRAVEL_UP : SERVO_SERVO_HOR_TRAVEL_DOWN;\
  servo_value = SERVO_SERVO_HOR_NEUTRAL + (int32_t)(command_value);\
  actuators[SERVO_SERVO_HOR] = ChopServo(servo_value, SERVO_SERVO_HOR_MIN, SERVO_SERVO_HOR_MAX);\
\
  Actuator(SERVO_SERVO_HOR) = SERVOS_TICS_OF_USEC(actuators[SERVO_SERVO_HOR]);\
\
  command_value = values[COMMAND_YAW];\
  command_value *= command_value>0 ? SERVO_SERVO_LEFT_TRAVEL_UP : SERVO_SERVO_LEFT_TRAVEL_DOWN;\
  servo_value = SERVO_SERVO_LEFT_NEUTRAL + (int32_t)(command_value);\
  actuators[SERVO_SERVO_LEFT] = ChopServo(servo_value, SERVO_SERVO_LEFT_MIN, SERVO_SERVO_LEFT_MAX);\
\
  Actuator(SERVO_SERVO_LEFT) = SERVOS_TICS_OF_USEC(actuators[SERVO_SERVO_LEFT]);\
\
  command_value = values[COMMAND_PITCH];\
  command_value *= command_value>0 ? SERVO_SERVO_RIGHT_TRAVEL_UP : SERVO_SERVO_RIGHT_TRAVEL_DOWN;\
  servo_value = SERVO_SERVO_RIGHT_NEUTRAL + (int32_t)(command_value);\
  actuators[SERVO_SERVO_RIGHT] = ChopServo(servo_value, SERVO_SERVO_RIGHT_MIN, SERVO_SERVO_RIGHT_MAX);\
\
  Actuator(SERVO_SERVO_RIGHT) = SERVOS_TICS_OF_USEC(actuators[SERVO_SERVO_RIGHT]);\
\
  ActuatorsCommit();\
}

#define AllActuatorsInit() { \
  ActuatorsInit();\
}

#define SetCommandsFromRC(_commands_array, _rc_array) { \
  _commands_array[COMMAND_THROTTLE] = _rc_array[RADIO_THROTTLE];\
  _commands_array[COMMAND_ROLL] = _rc_array[RADIO_ROLL];\
  _commands_array[COMMAND_PITCH] = _rc_array[RADIO_PITCH];\
  _commands_array[COMMAND_YAW] = _rc_array[RADIO_YAW];\
}

#define SetApOnlyCommands(ap_commands) { \
}

#define SECTION_AUTO1 1
#define AUTO1_MAX_ROLL 0.8
#define AUTO1_MAX_PITCH 0.785

#define SECTION_INFRARED 1
#define IR_ADC_IR1_NEUTRAL 512
#define IR_ADC_IR2_NEUTRAL 512
#define IR_ADC_TOP_NEUTRAL 512
#define IR_IR_LATERAL_CORRECTION 1
#define IR_IR_LONGITUDINAL_CORRECTION 1
#define IR_IR_VERTICAL_CORRECTION 1.
#define IR_HORIZ_SENSOR_TILTED 1
#define IR_IR1_SIGN 1
#define IR_IR2_SIGN 1
#define IR_TOP_SIGN 1
#define IR_ROLL_NEUTRAL_DEFAULT 0.
#define IR_PITCH_NEUTRAL_DEFAULT 0.2359685146
#define IR_CORRECTION_UP 1
#define IR_CORRECTION_DOWN 1
#define IR_CORRECTION_LEFT 1
#define IR_CORRECTION_RIGHT 0.795

#define SECTION_HORIZONTAL CONTROL 1
#define H_CTL_PITCH_PGAIN 4486
#define H_CTL_PITCH_DGAIN 0.
#define H_CTL_ELEVATOR_OF_ROLL 0
#define H_CTL_ROLL_ATTITUDE_GAIN 8000
#define H_CTL_ROLL_RATE_GAIN 0.
#define H_CTL_ROLL_SLEW 250.
#define H_CTL_AILERON_OF_THROTTLE 0
#define H_CTL_COURSE_DGAIN 1.2
#define H_CTL_COURSE_PGAIN 1.144
#define H_CTL_COURSE_PRE_BANK_CORRECTION 1.31
#define H_CTL_ROLL_MAX_SETPOINT 0.785
#define H_CTL_PITCH_MIN_SETPOINT -RadOfDeg(45)
#define H_CTL_PITCH_MAX_SETPOINT RadOfDeg(45)

#define SECTION_VERTICAL CONTROL 1
#define V_CTL_ALTITUDE_PGAIN 0.142
#define V_CTL_ALTITUDE_MAX_CLIMB 0.5
#define V_CTL_AUTO_THROTTLE_PGAIN 0.008
#define V_CTL_AUTO_THROTTLE_IGAIN 0.25
#define V_CTL_AUTO_THROTTLE_DGAIN 0
#define V_CTL_AUTO_THROTTLE_CLIMB_THROTTLE_INCREMENT 0.15
#define V_CTL_AUTO_THROTTLE_PITCH_OF_VZ_PGAIN 0.14
#define V_CTL_AUTO_THROTTLE_PITCH_OF_VZ_DGAIN 0
#define V_CTL_AUTO_THROTTLE_DASH_TRIM -1000
#define V_CTL_AUTO_THROTTLE_LOITER_TRIM 1500
#define V_CTL_AUTO_THROTTLE_NOMINAL_CRUISE_THROTTLE 0.4
#define V_CTL_AUTO_THROTTLE_MIN_CRUISE_THROTTLE 0
#define V_CTL_AUTO_THROTTLE_MAX_CRUISE_THROTTLE 1
#define V_CTL_THROTTLE_SLEW_LIMITER 0.5

#define SECTION_AGGRESSIVE 1
#define AGR_BLEND_START 18
#define AGR_BLEND_END 8
#define AGR_CLIMB_THROTTLE 1
#define AGR_CLIMB_PITCH 0.52
#define AGR_CLIMB_NAV_RATIO 0.8
#define AGR_DESCENT_THROTTLE 0
#define AGR_DESCENT_PITCH -0.5
#define AGR_DESCENT_NAV_RATIO 1

#define SECTION_SIMU 1
#define WEIGHT 1.
#define YAW_RESPONSE_FACTOR 1.
#define ROLL_RESPONSE_FACTOR 1.

#define SECTION_MISC 1
#define NOMINAL_AIRSPEED 18
#define CARROT 5.
#define CONTROL_RATE 60
#define DEFAULT_CIRCLE_RADIUS 100


#endif // AIRFRAME_H
