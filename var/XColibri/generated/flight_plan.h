/* This file has been generated from /home/lionel/paparazziAssembla/vamudes-paparazzi/conf/flight_plans/versatile.xml */
/* Please DO NOT EDIT */

#ifndef FLIGHT_PLAN_H
#define FLIGHT_PLAN_H

#include "std.h"
#include "generated/modules.h"
#include "subsystems/datalink/datalink.h"
#include "firmwares/fixedwing/combi_switch.h"
#include "firmwares/fixedwing/takeoff_gyro.h"
#define FLIGHT_PLAN_NAME "Versatile"
#define NAV_UTM_EAST0 360286
#define NAV_UTM_NORTH0 4813592
#define NAV_UTM_ZONE0 31
#define NAV_LAT0 434622000 /* 1e7deg */
#define NAV_LON0 12729000 /* 1e7deg */
#define NAV_ALT0 0 /* mm above msl */
#define NAV_MSL0 51850 /* mm, EGM96 geoid-height (msl) over ellipsoid */
#define QFU 270.0
#define WP_dummy 0
#define WP_HOME 1
#define WP_STDBY 2
#define WP_1 3
#define WP_2 4
#define WP_R1 5
#define WP_R2 6
#define WP_R3 7
#define WP_R4 8
#define WP_R5 9
#define WAYPOINTS { \
 {42.0, 42.0, 75},\
 {0.0, 0.0, 75},\
 {20.0, 80.0, 75},\
 {44.8, 102.2, 75},\
 {-63.5, 122.9, 75},\
 {-20.0, -50.0, 75},\
 {-20.0, -25.0, 75},\
 {-20.0, 0.0, 75},\
 {-20.0, 25.0, 75},\
 {-20.0, 50.0, 75},\
};
#define WAYPOINTS_LLA { \
 {434625858, 12734081, 7500}, /* 1e7deg, 1e7deg, cm (hmsl=51.85m) */ \
 {434621999, 12729000, 7500}, /* 1e7deg, 1e7deg, cm (hmsl=51.85m) */ \
 {434629237, 12731266, 7500}, /* 1e7deg, 1e7deg, cm (hmsl=51.85m) */ \
 {434631281, 12734273, 7500}, /* 1e7deg, 1e7deg, cm (hmsl=51.85m) */ \
 {434632942, 12720838, 7500}, /* 1e7deg, 1e7deg, cm (hmsl=51.85m) */ \
 {434617462, 12726656, 7500}, /* 1e7deg, 1e7deg, cm (hmsl=51.85m) */ \
 {434619712, 12726592, 7500}, /* 1e7deg, 1e7deg, cm (hmsl=51.85m) */ \
 {434621962, 12726528, 7500}, /* 1e7deg, 1e7deg, cm (hmsl=51.85m) */ \
 {434624212, 12726464, 7500}, /* 1e7deg, 1e7deg, cm (hmsl=51.85m) */ \
 {434626462, 12726400, 7500}, /* 1e7deg, 1e7deg, cm (hmsl=51.85m) */ \
};
#define NB_WAYPOINT 10
#define NB_BLOCK 9
#define GROUND_ALT 0.
#define GROUND_ALT_CM 0
#define SECURITY_HEIGHT 25.
#define SECURITY_ALT 25.
#define HOME_MODE_HEIGHT 50.
#define MAX_DIST_FROM_HOME 1500.
#ifdef NAV_C

static inline void auto_nav(void) {
  switch (nav_block) {
    Block(0) // Wait GPS
    ; // pre_call
    switch(nav_stage) {
      Stage(0)
        kill_throttle = 1;
        NextStageAndBreak();
        break;
      Label(while_1)
      Stage(1)
        if (! (!(GpsFixValid()))) Goto(endwhile_2) else NextStageAndBreak();
        Stage(2)
          Goto(while_1)
        Label(endwhile_2)
      default:
      Stage(3)
        NextBlock();
        break;
    }
    ; // post_call
    break;

    Block(1) // Geo init
    ; // pre_call
    switch(nav_stage) {
      Label(while_3)
      Stage(0)
        if (! (LessThan(NavBlockTime(),10))) Goto(endwhile_4) else NextStageAndBreak();
        Stage(1)
          Goto(while_3)
        Label(endwhile_4)
      Stage(2)
        if (! (NavSetGroundReferenceHere()))
          NextStageAndBreak();
        break;
      default:
      Stage(3)
        NextBlock();
        break;
    }
    ; // post_call
    break;

    Block(2) // Holding point
    ; // pre_call
    switch(nav_stage) {
      Stage(0)
        kill_throttle = 1;
        NextStageAndBreak();
        break;
      Stage(1)
        {
          NavAttitude(RadOfDeg(0));
          NavVerticalAutoThrottleMode(RadOfDeg(0.000000));
          NavVerticalThrottleMode(9600*(0));
        }
        break;
      default:
      Stage(2)
        NextBlock();
        break;
    }
    ; // post_call
    break;

    Block(3) // Takeoff
    ; // pre_call
    if ((nav_block != 4) && (estimator_z>210)) { GotoBlock(4); return; }
    switch(nav_stage) {
      Stage(0)
        kill_throttle = 0;
        NextStageAndBreak();
        break;
      Stage(1)
        combi_switch_status = 0;
        NextStageAndBreak();
        break;
      Stage(2)
        {
          NavAttitude(RadOfDeg(0.000000));
          NavVerticalAutoThrottleMode(RadOfDeg(30.000000));
          NavVerticalThrottleMode(9600*(1.000000));
        }
        break;
      default:
      Stage(3)
        NextBlock();
        break;
    }
    ; // post_call
    break;

    Block(4) // Standby
    ; // pre_call
    switch(nav_stage) {
      Stage(0)
        combi_switch_status = 1;
        NextStageAndBreak();
        break;
      Stage(1)
        NavVerticalAutoThrottleMode(RadOfDeg(0.000000));
        NavVerticalAltitudeMode(WaypointAlt(2), 0.);
        NavCircleWaypoint(2, nav_radius);
        break;
      default:
      Stage(2)
        NextBlock();
        break;
    }
    ; // post_call
    break;

    Block(5) // Figure 8
    ; // pre_call
    switch(nav_stage) {
      Stage(0)
        nav_eight_init();
        NextStageAndBreak();
      Stage(1)
        NavVerticalAutoThrottleMode(RadOfDeg(0.000000));
        NavVerticalAltitudeMode(WaypointAlt(3), 0.);
        Eight(3, 4, nav_radius);
        break;
      default:
      Stage(2)
        NextBlock();
        break;
    }
    ; // post_call
    break;

    Block(6) // Oval 1-2
    ; // pre_call
    switch(nav_stage) {
      Stage(0)
        nav_oval_init();
        NextStageAndBreak();
      Stage(1)
        NavVerticalAutoThrottleMode(RadOfDeg(0.000000));
        NavVerticalAltitudeMode(WaypointAlt(3), 0.);
        Oval(3, 4, nav_radius);
        break;
      default:
      Stage(2)
        NextBlock();
        break;
    }
    ; // post_call
    break;

    Block(7) // Route
    ; // pre_call
    switch(nav_stage) {
      Stage(0)
        if (NavApproaching(5,CARROT)) NextStageAndBreakFrom(5) else {
          NavGotoWaypoint(5);
          NavVerticalAutoThrottleMode(RadOfDeg(0.000000));
          NavVerticalAltitudeMode(WaypointAlt(5), 0.);
        }
        break;
      Label(while_5)
      Stage(1)
        if (! (TRUE)) Goto(endwhile_6) else NextStageAndBreak();
        Stage(2)
          if (NavApproachingFrom(6,5,route_ap_time)) NextStageAndBreakFrom(6) else {
            NavSegment(5, 6);
            NavVerticalAutoThrottleMode(RadOfDeg(0.000000));
            NavVerticalAltitudeMode(WaypointAlt(6), 0.);
          }
          break;
        Stage(3)
          if (NavApproachingFrom(7,6,route_ap_time)) NextStageAndBreakFrom(7) else {
            NavSegment(6, 7);
            NavVerticalAutoThrottleMode(RadOfDeg(0.000000));
            NavVerticalAltitudeMode(WaypointAlt(7), 0.);
          }
          break;
        Stage(4)
          if (NavApproachingFrom(8,7,route_ap_time)) NextStageAndBreakFrom(8) else {
            NavSegment(7, 8);
            NavVerticalAutoThrottleMode(RadOfDeg(0.000000));
            NavVerticalAltitudeMode(WaypointAlt(8), 0.);
          }
          break;
        Stage(5)
          if (NavApproachingFrom(9,8,route_ap_time)) NextStageAndBreakFrom(9) else {
            NavSegment(8, 9);
            NavVerticalAutoThrottleMode(RadOfDeg(0.000000));
            NavVerticalAltitudeMode(WaypointAlt(9), 0.);
          }
          break;
        Stage(6)
          if (NavApproachingFrom(5,9,route_ap_time)) NextStageAndBreakFrom(5) else {
            NavSegment(9, 5);
            NavVerticalAutoThrottleMode(RadOfDeg(0.000000));
            NavVerticalAltitudeMode(WaypointAlt(5), 0.);
          }
          break;
        Stage(7)
          Goto(while_5)
        Label(endwhile_6)
      default:
      Stage(8)
        NextBlock();
        break;
    }
    ; // post_call
    break;

    Block(8) // HOME
    ; // pre_call
    switch(nav_stage) {
      Stage(0)
        nav_home();
        break;
      default:
      Stage(1)
        NextBlock();
        break;
    }
    ; // post_call
    break;

    default: break;
  }
}
#endif // NAV_C

#endif // FLIGHT_PLAN_H
