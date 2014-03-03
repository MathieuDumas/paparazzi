/* This file has been generated from /home/lionel/paparazziProto1/var/Colibri/settings_modules.xml /home/lionel/paparazziProto1/conf/settings/control/ctl_basic.xml /home/lionel/paparazziProto1/conf/settings/fixedwing_basic.xml /home/lionel/paparazziProto1/var/Colibri/settings_telemetry.xml */
/* Please DO NOT EDIT */

#ifndef SETTINGS_H
#define SETTINGS_H

#define RCSettings(mode_changed) { \
}

#include "autopilot.h"
#include "guidance/guidance_v.h"
#include "stabilization/stabilization_attitude.h"
#include "subsystems/gps.h"
#include "subsystems/nav.h"
#include "generated/modules.h"
#include "generated/periodic_telemetry.h"

#define DlSetting(_idx, _value) { \
  switch (_idx) { \
    case 0: telemetry_mode_Ap = _value; break;\
    case 1: telemetry_mode_Fbw = _value; break;\
    case 2: flight_altitude = _value; break;\
    case 3: nav_course = _value; break;\
    case 4: nav_IncreaseShift( _value ); _value = nav_shift; break;\
    case 5: autopilot_ResetFlightTimeAndLaunch( _value ); _value = estimator_flight_time; break;\
    case 6: nav_SetNavRadius( _value ); _value = nav_radius; break;\
    case 7: route_ap_time = _value; break;\
    case 8: pprz_mode = _value; break;\
    case 9: launch = _value; break;\
    case 10: kill_throttle = _value; break;\
    case 11: gps_Reset( _value ); _value = gps.reset; break;\
    case 12: h_ctl_pitch_pgain = _value; break;\
    case 13: h_ctl_pitch_dgain = _value; break;\
    case 14: h_ctl_elevator_of_roll = _value; break;\
    case 15: h_ctl_roll_attitude_gain = _value; break;\
    case 16: h_ctl_roll_rate_gain = _value; break;\
    case 17: h_ctl_aileron_of_throttle = _value; break;\
    case 18: h_ctl_roll_slew = _value; break;\
    case 19: h_ctl_course_pgain = _value; break;\
    case 20: h_ctl_course_dgain = _value; break;\
    case 21: h_ctl_course_pre_bank_correction = _value; break;\
    case 22: h_ctl_roll_max_setpoint = _value; break;\
    case 23: v_ctl_altitude_pgain = _value; break;\
    case 24: guidance_v_SetCruiseThrottle( _value ); _value = v_ctl_auto_throttle_cruise_throttle; break;\
    case 25: v_ctl_auto_throttle_pgain = _value; break;\
    case 26: v_ctl_auto_throttle_igain = _value; break;\
    case 27: v_ctl_auto_throttle_dgain = _value; break;\
    case 28: v_ctl_auto_throttle_climb_throttle_increment = _value; break;\
    case 29: v_ctl_auto_throttle_pitch_of_vz_pgain = _value; break;\
    case 30: v_ctl_auto_throttle_pitch_of_vz_dgain = _value; break;\
    default: break;\
  }\
}
#define PeriodicSendDlValue(_trans, _dev) { \
  static uint8_t i;\
  float var;\
  if (i >= 31) i = 0;\
  switch (i) { \
    case 0: var = telemetry_mode_Ap; break;\
    case 1: var = telemetry_mode_Fbw; break;\
    case 2: var = flight_altitude; break;\
    case 3: var = nav_course; break;\
    case 4: var = nav_shift; break;\
    case 5: var = estimator_flight_time; break;\
    case 6: var = nav_radius; break;\
    case 7: var = route_ap_time; break;\
    case 8: var = pprz_mode; break;\
    case 9: var = launch; break;\
    case 10: var = kill_throttle; break;\
    case 11: var = gps.reset; break;\
    case 12: var = h_ctl_pitch_pgain; break;\
    case 13: var = h_ctl_pitch_dgain; break;\
    case 14: var = h_ctl_elevator_of_roll; break;\
    case 15: var = h_ctl_roll_attitude_gain; break;\
    case 16: var = h_ctl_roll_rate_gain; break;\
    case 17: var = h_ctl_aileron_of_throttle; break;\
    case 18: var = h_ctl_roll_slew; break;\
    case 19: var = h_ctl_course_pgain; break;\
    case 20: var = h_ctl_course_dgain; break;\
    case 21: var = h_ctl_course_pre_bank_correction; break;\
    case 22: var = h_ctl_roll_max_setpoint; break;\
    case 23: var = v_ctl_altitude_pgain; break;\
    case 24: var = v_ctl_auto_throttle_cruise_throttle; break;\
    case 25: var = v_ctl_auto_throttle_pgain; break;\
    case 26: var = v_ctl_auto_throttle_igain; break;\
    case 27: var = v_ctl_auto_throttle_dgain; break;\
    case 28: var = v_ctl_auto_throttle_climb_throttle_increment; break;\
    case 29: var = v_ctl_auto_throttle_pitch_of_vz_pgain; break;\
    case 30: var = v_ctl_auto_throttle_pitch_of_vz_dgain; break;\
    default: var = 0.; break;\
  }\
  DOWNLINK_SEND_DL_VALUE(_trans, _dev, &i, &var);\
  i++;\
}
static inline float settings_get_value(uint8_t i) {
  switch (i) { \
    case 0: return telemetry_mode_Ap;
    case 1: return telemetry_mode_Fbw;
    case 2: return flight_altitude;
    case 3: return nav_course;
    case 4: return nav_shift;
    case 5: return estimator_flight_time;
    case 6: return nav_radius;
    case 7: return route_ap_time;
    case 8: return pprz_mode;
    case 9: return launch;
    case 10: return kill_throttle;
    case 11: return gps.reset;
    case 12: return h_ctl_pitch_pgain;
    case 13: return h_ctl_pitch_dgain;
    case 14: return h_ctl_elevator_of_roll;
    case 15: return h_ctl_roll_attitude_gain;
    case 16: return h_ctl_roll_rate_gain;
    case 17: return h_ctl_aileron_of_throttle;
    case 18: return h_ctl_roll_slew;
    case 19: return h_ctl_course_pgain;
    case 20: return h_ctl_course_dgain;
    case 21: return h_ctl_course_pre_bank_correction;
    case 22: return h_ctl_roll_max_setpoint;
    case 23: return v_ctl_altitude_pgain;
    case 24: return v_ctl_auto_throttle_cruise_throttle;
    case 25: return v_ctl_auto_throttle_pgain;
    case 26: return v_ctl_auto_throttle_igain;
    case 27: return v_ctl_auto_throttle_dgain;
    case 28: return v_ctl_auto_throttle_climb_throttle_increment;
    case 29: return v_ctl_auto_throttle_pitch_of_vz_pgain;
    case 30: return v_ctl_auto_throttle_pitch_of_vz_dgain;
    default: return 0.;
    }
  }

/* Persistent Settings */
struct PersistentSettings {
};

extern struct PersistentSettings pers_settings;

static inline void persistent_settings_store( void ) {
}

static inline void persistent_settings_load( void ) {
};

#endif // SETTINGS_H
