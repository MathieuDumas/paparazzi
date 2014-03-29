/* This file has been generated from /home/lionel/paparazziProto1/var/Colibri/settings_modules.xml /home/lionel/paparazziProto1/conf/settings/fixedwing_basic.xml /home/lionel/paparazziProto1/conf/settings/control/ctl_basic.xml /home/lionel/paparazziProto1/var/Colibri/settings_telemetry.xml */
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
    case 2: h_ctl_pitch_pgain = _value; break;\
    case 3: h_ctl_pitch_dgain = _value; break;\
    case 4: h_ctl_elevator_of_roll = _value; break;\
    case 5: h_ctl_roll_attitude_gain = _value; break;\
    case 6: h_ctl_roll_rate_gain = _value; break;\
    case 7: h_ctl_aileron_of_throttle = _value; break;\
    case 8: h_ctl_roll_slew = _value; break;\
    case 9: h_ctl_course_pgain = _value; break;\
    case 10: h_ctl_course_dgain = _value; break;\
    case 11: h_ctl_course_pre_bank_correction = _value; break;\
    case 12: h_ctl_roll_max_setpoint = _value; break;\
    case 13: v_ctl_altitude_pgain = _value; break;\
    case 14: guidance_v_SetCruiseThrottle( _value ); _value = v_ctl_auto_throttle_cruise_throttle; break;\
    case 15: v_ctl_auto_throttle_pgain = _value; break;\
    case 16: v_ctl_auto_throttle_igain = _value; break;\
    case 17: v_ctl_auto_throttle_dgain = _value; break;\
    case 18: v_ctl_auto_throttle_climb_throttle_increment = _value; break;\
    case 19: v_ctl_auto_throttle_pitch_of_vz_pgain = _value; break;\
    case 20: v_ctl_auto_throttle_pitch_of_vz_dgain = _value; break;\
    case 21: flight_altitude = _value; break;\
    case 22: nav_course = _value; break;\
    case 23: nav_IncreaseShift( _value ); _value = nav_shift; break;\
    case 24: autopilot_ResetFlightTimeAndLaunch( _value ); _value = estimator_flight_time; break;\
    case 25: nav_SetNavRadius( _value ); _value = nav_radius; break;\
    case 26: route_ap_time = _value; break;\
    case 27: pprz_mode = _value; break;\
    case 28: launch = _value; break;\
    case 29: kill_throttle = _value; break;\
    case 30: gps_Reset( _value ); _value = gps.reset; break;\
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
    case 2: var = h_ctl_pitch_pgain; break;\
    case 3: var = h_ctl_pitch_dgain; break;\
    case 4: var = h_ctl_elevator_of_roll; break;\
    case 5: var = h_ctl_roll_attitude_gain; break;\
    case 6: var = h_ctl_roll_rate_gain; break;\
    case 7: var = h_ctl_aileron_of_throttle; break;\
    case 8: var = h_ctl_roll_slew; break;\
    case 9: var = h_ctl_course_pgain; break;\
    case 10: var = h_ctl_course_dgain; break;\
    case 11: var = h_ctl_course_pre_bank_correction; break;\
    case 12: var = h_ctl_roll_max_setpoint; break;\
    case 13: var = v_ctl_altitude_pgain; break;\
    case 14: var = v_ctl_auto_throttle_cruise_throttle; break;\
    case 15: var = v_ctl_auto_throttle_pgain; break;\
    case 16: var = v_ctl_auto_throttle_igain; break;\
    case 17: var = v_ctl_auto_throttle_dgain; break;\
    case 18: var = v_ctl_auto_throttle_climb_throttle_increment; break;\
    case 19: var = v_ctl_auto_throttle_pitch_of_vz_pgain; break;\
    case 20: var = v_ctl_auto_throttle_pitch_of_vz_dgain; break;\
    case 21: var = flight_altitude; break;\
    case 22: var = nav_course; break;\
    case 23: var = nav_shift; break;\
    case 24: var = estimator_flight_time; break;\
    case 25: var = nav_radius; break;\
    case 26: var = route_ap_time; break;\
    case 27: var = pprz_mode; break;\
    case 28: var = launch; break;\
    case 29: var = kill_throttle; break;\
    case 30: var = gps.reset; break;\
    default: var = 0.; break;\
  }\
  DOWNLINK_SEND_DL_VALUE(_trans, _dev, &i, &var);\
  i++;\
}
static inline float settings_get_value(uint8_t i) {
  switch (i) { \
    case 0: return telemetry_mode_Ap;
    case 1: return telemetry_mode_Fbw;
    case 2: return h_ctl_pitch_pgain;
    case 3: return h_ctl_pitch_dgain;
    case 4: return h_ctl_elevator_of_roll;
    case 5: return h_ctl_roll_attitude_gain;
    case 6: return h_ctl_roll_rate_gain;
    case 7: return h_ctl_aileron_of_throttle;
    case 8: return h_ctl_roll_slew;
    case 9: return h_ctl_course_pgain;
    case 10: return h_ctl_course_dgain;
    case 11: return h_ctl_course_pre_bank_correction;
    case 12: return h_ctl_roll_max_setpoint;
    case 13: return v_ctl_altitude_pgain;
    case 14: return v_ctl_auto_throttle_cruise_throttle;
    case 15: return v_ctl_auto_throttle_pgain;
    case 16: return v_ctl_auto_throttle_igain;
    case 17: return v_ctl_auto_throttle_dgain;
    case 18: return v_ctl_auto_throttle_climb_throttle_increment;
    case 19: return v_ctl_auto_throttle_pitch_of_vz_pgain;
    case 20: return v_ctl_auto_throttle_pitch_of_vz_dgain;
    case 21: return flight_altitude;
    case 22: return nav_course;
    case 23: return nav_shift;
    case 24: return estimator_flight_time;
    case 25: return nav_radius;
    case 26: return route_ap_time;
    case 27: return pprz_mode;
    case 28: return launch;
    case 29: return kill_throttle;
    case 30: return gps.reset;
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
