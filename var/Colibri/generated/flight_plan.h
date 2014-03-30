/* This file has been generated from /home/lionel/paparazziProto1/conf/flight_plans/testAuto1.xml */
/* Please DO NOT EDIT */

#ifndef FLIGHT_PLAN_H
#define FLIGHT_PLAN_H

#include "std.h"
#include "generated/modules.h"
#include "subsystems/datalink/datalink.h"
#include "generated/airframe.h"
#include "commands.h"
#include "actuators.h"
#define FLIGHT_PLAN_NAME "Versatile"
#define NAV_UTM_EAST0 374889
#define NAV_UTM_NORTH0 4223058
#define NAV_UTM_ZONE0 18
#define NAV_LAT0 381467240 /* 1e7deg */
#define NAV_LON0 -764278110 /* 1e7deg */
#define NAV_ALT0 0 /* mm above msl */
#define NAV_MSL0 -37210 /* mm, EGM96 geoid-height (msl) over ellipsoid */
#define QFU 270.0
#define WP_dummy 0
#define WP_HOME 1
#define WAYPOINTS { \
 {42.0, 42.0, 75},\
 {0.0, 0.0, 75},\
};
#define WAYPOINTS_LLA { \
 {381471082, -764273391, 7500}, /* 1e7deg, 1e7deg, cm (hmsl=-37.21m) */ \
 {381467239, -764278109, 7500}, /* 1e7deg, 1e7deg, cm (hmsl=-37.21m) */ \
};
#define NB_WAYPOINT 2
#define NB_BLOCK 8
#define GROUND_ALT 0.
#define GROUND_ALT_CM 0
#define SECURITY_HEIGHT -25.
#define SECURITY_ALT -25.
#define HOME_MODE_HEIGHT 50.
#define MAX_DIST_FROM_HOME 1500.
#ifdef NAV_C

static inline void auto_nav(void) {
  switch (nav_block) {
    Block(0) // initialisation
    ; // pre_call
    switch(nav_stage) {
      Stage(0)
        launch = 1;
        NextStageAndBreak();
        break;
      Stage(1)
        fbw_mode = FBW_MODE_MANUAL;
        NextStageAndBreak();
        break;
      Stage(2)
        radio_control.values[0] = 9600;
        NextStageAndBreak();
        break;
      Stage(3)
        radio_control.values[1] = 9600;
        NextStageAndBreak();
        break;
      Stage(4)
        radio_control.values[2] = 9600;
        NextStageAndBreak();
        break;
      Stage(5)
        radio_control.values[3] = 9600;
        NextStageAndBreak();
        break;
      Label(while_1)
      Stage(6)
        if (! (LessThan(NavBlockTime(),10))) Goto(endwhile_2) else NextStageAndBreak();
        Stage(7)
          Goto(while_1)
        Label(endwhile_2)
      default:
      Stage(8)
        NextBlock();
        break;
    }
    ; // post_call
    break;

    Block(1) // bloc 1
    ; // pre_call
    switch(nav_stage) {
      Stage(0)
        radio_control.values[0] = -(9600);
        NextStageAndBreak();
        break;
      Stage(1)
        radio_control.values[1] = -(9600);
        NextStageAndBreak();
        break;
      Stage(2)
        radio_control.values[2] = -(9600);
        NextStageAndBreak();
        break;
      Stage(3)
        radio_control.values[3] = -(9600);
        NextStageAndBreak();
        break;
      Label(while_3)
      Stage(4)
        if (! (LessThan(NavBlockTime(),10))) Goto(endwhile_4) else NextStageAndBreak();
        Stage(5)
          Goto(while_3)
        Label(endwhile_4)
      default:
      Stage(6)
        NextBlock();
        break;
    }
    ; // post_call
    break;

    Block(2) // bloc 2
    ; // pre_call
    switch(nav_stage) {
      Stage(0)
        radio_control.values[0] = 9600;
        NextStageAndBreak();
        break;
      Stage(1)
        radio_control.values[1] = 9600;
        NextStageAndBreak();
        break;
      Stage(2)
        radio_control.values[2] = 9600;
        NextStageAndBreak();
        break;
      Stage(3)
        radio_control.values[3] = 9600;
        NextStageAndBreak();
        break;
      Label(while_5)
      Stage(4)
        if (! (LessThan(NavBlockTime(),10))) Goto(endwhile_6) else NextStageAndBreak();
        Stage(5)
          Goto(while_5)
        Label(endwhile_6)
      default:
      Stage(6)
        NextBlock();
        break;
    }
    ; // post_call
    break;

    Block(3) // bloc 3
    ; // pre_call
    switch(nav_stage) {
      Stage(0)
        radio_control.values[0] = -(9600);
        NextStageAndBreak();
        break;
      Stage(1)
        radio_control.values[1] = -(9600);
        NextStageAndBreak();
        break;
      Stage(2)
        radio_control.values[2] = -(9600);
        NextStageAndBreak();
        break;
      Stage(3)
        radio_control.values[3] = -(9600);
        NextStageAndBreak();
        break;
      Label(while_7)
      Stage(4)
        if (! (LessThan(NavBlockTime(),10))) Goto(endwhile_8) else NextStageAndBreak();
        Stage(5)
          Goto(while_7)
        Label(endwhile_8)
      default:
      Stage(6)
        NextBlock();
        break;
    }
    ; // post_call
    break;

    Block(4) // Fin de test
    ; // pre_call
    switch(nav_stage) {
      Stage(0)
        radio_control.values[0] = 0;
        NextStageAndBreak();
        break;
      Stage(1)
        radio_control.values[1] = 0;
        NextStageAndBreak();
        break;
      Stage(2)
        radio_control.values[2] = 0;
        NextStageAndBreak();
        break;
      Stage(3)
        radio_control.values[3] = 0;
        NextStageAndBreak();
        break;
      Label(while_9)
      Stage(4)
        if (! (TRUE)) Goto(endwhile_10) else NextStageAndBreak();
        Stage(5)
          Goto(while_9)
        Label(endwhile_10)
      default:
      Stage(6)
        NextBlock();
        break;
    }
    ; // post_call
    break;

    Block(5) // Block 4
    ; // pre_call
    switch(nav_stage) {
      Stage(0)
        if ((stage_time>15)) NextStageAndBreak() else {
          NavAttitude(RadOfDeg(-(14.000000)));
          NavVerticalAutoThrottleMode(RadOfDeg(0.000000));
          NavVerticalThrottleMode(9600*(0.500000));
        }
        break;
      default:
      Stage(1)
        NextBlock();
        break;
    }
    ; // post_call
    break;

    Block(6) // Block 5
    ; // pre_call
    switch(nav_stage) {
      Stage(0)
        if ((stage_time>15)) NextStageAndBreak() else {
          NavAttitude(RadOfDeg(14.000000));
          NavVerticalAutoThrottleMode(RadOfDeg(0.000000));
          NavVerticalThrottleMode(9600*(0.750000));
        }
        break;
      default:
      Stage(1)
        NextBlock();
        break;
    }
    ; // post_call
    break;

    Block(7) // HOME
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
