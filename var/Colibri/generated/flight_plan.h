/* This file has been generated from /home/lionel/paparazziProto1/conf/flight_plans/bancTest/testmotorisation.xml */
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
#define NB_BLOCK 32
#define GROUND_ALT 0.
#define GROUND_ALT_CM 0
#define SECURITY_HEIGHT -25.
#define SECURITY_ALT -25.
#define HOME_MODE_HEIGHT 50.
#define MAX_DIST_FROM_HOME 1500.
#ifdef NAV_C

static inline void auto_nav(void) {
  switch (nav_block) {
    Block(0) // Servo Right avant
    ; // pre_call
    switch(nav_stage) {
      Stage(0)
        radio_control.values[1] = (9600*0.600000);
        NextStageAndBreak();
        break;
      Label(while_1)
      Stage(1)
        if (! (TRUE)) Goto(endwhile_2) else NextStageAndBreak();
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

    Block(1) // Servo Right arriere
    ; // pre_call
    switch(nav_stage) {
      Stage(0)
        radio_control.values[1] = (-(9600)*0.600000);
        NextStageAndBreak();
        break;
      Label(while_3)
      Stage(1)
        if (! (TRUE)) Goto(endwhile_4) else NextStageAndBreak();
        Stage(2)
          Goto(while_3)
        Label(endwhile_4)
      default:
      Stage(3)
        NextBlock();
        break;
    }
    ; // post_call
    break;

    Block(2) // Servo Right centre
    ; // pre_call
    switch(nav_stage) {
      Stage(0)
        radio_control.values[1] = 0;
        NextStageAndBreak();
        break;
      Label(while_5)
      Stage(1)
        if (! (TRUE)) Goto(endwhile_6) else NextStageAndBreak();
        Stage(2)
          Goto(while_5)
        Label(endwhile_6)
      default:
      Stage(3)
        NextBlock();
        break;
    }
    ; // post_call
    break;

    Block(3) // Servo Left avant
    ; // pre_call
    switch(nav_stage) {
      Stage(0)
        radio_control.values[2] = (-(9600)*0.600000);
        NextStageAndBreak();
        break;
      Label(while_7)
      Stage(1)
        if (! (TRUE)) Goto(endwhile_8) else NextStageAndBreak();
        Stage(2)
          Goto(while_7)
        Label(endwhile_8)
      default:
      Stage(3)
        NextBlock();
        break;
    }
    ; // post_call
    break;

    Block(4) // Servo Left arriere
    ; // pre_call
    switch(nav_stage) {
      Stage(0)
        radio_control.values[2] = (9600*0.600000);
        NextStageAndBreak();
        break;
      Label(while_9)
      Stage(1)
        if (! (TRUE)) Goto(endwhile_10) else NextStageAndBreak();
        Stage(2)
          Goto(while_9)
        Label(endwhile_10)
      default:
      Stage(3)
        NextBlock();
        break;
    }
    ; // post_call
    break;

    Block(5) // Servo Left centre
    ; // pre_call
    switch(nav_stage) {
      Stage(0)
        radio_control.values[2] = 0;
        NextStageAndBreak();
        break;
      Label(while_11)
      Stage(1)
        if (! (TRUE)) Goto(endwhile_12) else NextStageAndBreak();
        Stage(2)
          Goto(while_11)
        Label(endwhile_12)
      default:
      Stage(3)
        NextBlock();
        break;
    }
    ; // post_call
    break;

    Block(6) // Servo Roll centre
    ; // pre_call
    switch(nav_stage) {
      Stage(0)
        radio_control.values[3] = 0;
        NextStageAndBreak();
        break;
      Label(while_13)
      Stage(1)
        if (! (TRUE)) Goto(endwhile_14) else NextStageAndBreak();
        Stage(2)
          Goto(while_13)
        Label(endwhile_14)
      default:
      Stage(3)
        NextBlock();
        break;
    }
    ; // post_call
    break;

    Block(7) // Servo Roll droit
    ; // pre_call
    switch(nav_stage) {
      Stage(0)
        radio_control.values[3] = (9600*0.600000);
        NextStageAndBreak();
        break;
      Label(while_15)
      Stage(1)
        if (! (TRUE)) Goto(endwhile_16) else NextStageAndBreak();
        Stage(2)
          Goto(while_15)
        Label(endwhile_16)
      default:
      Stage(3)
        NextBlock();
        break;
    }
    ; // post_call
    break;

    Block(8) // Servo Roll gauche
    ; // pre_call
    switch(nav_stage) {
      Stage(0)
        radio_control.values[3] = (-(9600)*0.600000);
        NextStageAndBreak();
        break;
      Label(while_17)
      Stage(1)
        if (! (TRUE)) Goto(endwhile_18) else NextStageAndBreak();
        Stage(2)
          Goto(while_17)
        Label(endwhile_18)
      default:
      Stage(3)
        NextBlock();
        break;
    }
    ; // post_call
    break;

    Block(9) // Pitch avant
    ; // pre_call
    switch(nav_stage) {
      Stage(0)
        radio_control.values[2] = (-(9600)*0.600000);
        NextStageAndBreak();
        break;
      Stage(1)
        radio_control.values[1] = (9600*0.600000);
        NextStageAndBreak();
        break;
      Label(while_19)
      Stage(2)
        if (! (TRUE)) Goto(endwhile_20) else NextStageAndBreak();
        Stage(3)
          Goto(while_19)
        Label(endwhile_20)
      default:
      Stage(4)
        NextBlock();
        break;
    }
    ; // post_call
    break;

    Block(10) // Pitch arriere
    ; // pre_call
    switch(nav_stage) {
      Stage(0)
        radio_control.values[2] = (9600*0.600000);
        NextStageAndBreak();
        break;
      Stage(1)
        radio_control.values[1] = (-(9600)*0.600000);
        NextStageAndBreak();
        break;
      Label(while_21)
      Stage(2)
        if (! (TRUE)) Goto(endwhile_22) else NextStageAndBreak();
        Stage(3)
          Goto(while_21)
        Label(endwhile_22)
      default:
      Stage(4)
        NextBlock();
        break;
    }
    ; // post_call
    break;

    Block(11) // Yaw droite
    ; // pre_call
    switch(nav_stage) {
      Stage(0)
        radio_control.values[2] = (9600*0.600000);
        NextStageAndBreak();
        break;
      Stage(1)
        radio_control.values[1] = (9600*0.600000);
        NextStageAndBreak();
        break;
      Label(while_23)
      Stage(2)
        if (! (TRUE)) Goto(endwhile_24) else NextStageAndBreak();
        Stage(3)
          Goto(while_23)
        Label(endwhile_24)
      default:
      Stage(4)
        NextBlock();
        break;
    }
    ; // post_call
    break;

    Block(12) // Yaw gauche
    ; // pre_call
    switch(nav_stage) {
      Stage(0)
        radio_control.values[2] = (-(9600)*0.600000);
        NextStageAndBreak();
        break;
      Stage(1)
        radio_control.values[1] = (-(9600)*0.600000);
        NextStageAndBreak();
        break;
      Label(while_25)
      Stage(2)
        if (! (TRUE)) Goto(endwhile_26) else NextStageAndBreak();
        Stage(3)
          Goto(while_25)
        Label(endwhile_26)
      default:
      Stage(4)
        NextBlock();
        break;
    }
    ; // post_call
    break;

    Block(13) // initialisation
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
        radio_control.values[0] = (9600*0.000000);
        NextStageAndBreak();
        break;
      Label(while_27)
      Stage(3)
        if (! (TRUE)) Goto(endwhile_28) else NextStageAndBreak();
        Stage(4)
          Goto(while_27)
        Label(endwhile_28)
      default:
      Stage(5)
        NextBlock();
        break;
    }
    ; // post_call
    break;

    Block(14) // 100%
    ; // pre_call
    switch(nav_stage) {
      Stage(0)
        radio_control.values[0] = (9600*1);
        NextStageAndBreak();
        break;
      Label(while_29)
      Stage(1)
        if (! (TRUE)) Goto(endwhile_30) else NextStageAndBreak();
        Stage(2)
          Goto(while_29)
        Label(endwhile_30)
      default:
      Stage(3)
        NextBlock();
        break;
    }
    ; // post_call
    break;

    Block(15) // 0.05%
    ; // pre_call
    switch(nav_stage) {
      Stage(0)
        radio_control.values[0] = (9600*0.050000);
        NextStageAndBreak();
        break;
      Label(while_31)
      Stage(1)
        if (! (TRUE)) Goto(endwhile_32) else NextStageAndBreak();
        Stage(2)
          Goto(while_31)
        Label(endwhile_32)
      default:
      Stage(3)
        NextBlock();
        break;
    }
    ; // post_call
    break;

    Block(16) // 0.15%
    ; // pre_call
    switch(nav_stage) {
      Stage(0)
        radio_control.values[0] = (9600*0.150000);
        NextStageAndBreak();
        break;
      Label(while_33)
      Stage(1)
        if (! (TRUE)) Goto(endwhile_34) else NextStageAndBreak();
        Stage(2)
          Goto(while_33)
        Label(endwhile_34)
      default:
      Stage(3)
        NextBlock();
        break;
    }
    ; // post_call
    break;

    Block(17) // 0.2%
    ; // pre_call
    switch(nav_stage) {
      Stage(0)
        radio_control.values[0] = (9600*0.200000);
        NextStageAndBreak();
        break;
      Label(while_35)
      Stage(1)
        if (! (TRUE)) Goto(endwhile_36) else NextStageAndBreak();
        Stage(2)
          Goto(while_35)
        Label(endwhile_36)
      default:
      Stage(3)
        NextBlock();
        break;
    }
    ; // post_call
    break;

    Block(18) // 0.25%
    ; // pre_call
    switch(nav_stage) {
      Stage(0)
        radio_control.values[0] = (9600*0.250000);
        NextStageAndBreak();
        break;
      Label(while_37)
      Stage(1)
        if (! (TRUE)) Goto(endwhile_38) else NextStageAndBreak();
        Stage(2)
          Goto(while_37)
        Label(endwhile_38)
      default:
      Stage(3)
        NextBlock();
        break;
    }
    ; // post_call
    break;

    Block(19) // 0.3%
    ; // pre_call
    switch(nav_stage) {
      Stage(0)
        radio_control.values[0] = (9600*0.300000);
        NextStageAndBreak();
        break;
      Label(while_39)
      Stage(1)
        if (! (TRUE)) Goto(endwhile_40) else NextStageAndBreak();
        Stage(2)
          Goto(while_39)
        Label(endwhile_40)
      default:
      Stage(3)
        NextBlock();
        break;
    }
    ; // post_call
    break;

    Block(20) // 0.35%
    ; // pre_call
    switch(nav_stage) {
      Stage(0)
        radio_control.values[0] = (9600*0.350000);
        NextStageAndBreak();
        break;
      Label(while_41)
      Stage(1)
        if (! (TRUE)) Goto(endwhile_42) else NextStageAndBreak();
        Stage(2)
          Goto(while_41)
        Label(endwhile_42)
      default:
      Stage(3)
        NextBlock();
        break;
    }
    ; // post_call
    break;

    Block(21) // 0.4%
    ; // pre_call
    switch(nav_stage) {
      Stage(0)
        radio_control.values[0] = (9600*0.400000);
        NextStageAndBreak();
        break;
      Label(while_43)
      Stage(1)
        if (! (TRUE)) Goto(endwhile_44) else NextStageAndBreak();
        Stage(2)
          Goto(while_43)
        Label(endwhile_44)
      default:
      Stage(3)
        NextBlock();
        break;
    }
    ; // post_call
    break;

    Block(22) // 0.45%
    ; // pre_call
    switch(nav_stage) {
      Stage(0)
        radio_control.values[0] = (9600*0.450000);
        NextStageAndBreak();
        break;
      Label(while_45)
      Stage(1)
        if (! (TRUE)) Goto(endwhile_46) else NextStageAndBreak();
        Stage(2)
          Goto(while_45)
        Label(endwhile_46)
      default:
      Stage(3)
        NextBlock();
        break;
    }
    ; // post_call
    break;

    Block(23) // 0.50%
    ; // pre_call
    switch(nav_stage) {
      Stage(0)
        radio_control.values[0] = (9600*0.500000);
        NextStageAndBreak();
        break;
      Label(while_47)
      Stage(1)
        if (! (TRUE)) Goto(endwhile_48) else NextStageAndBreak();
        Stage(2)
          Goto(while_47)
        Label(endwhile_48)
      default:
      Stage(3)
        NextBlock();
        break;
    }
    ; // post_call
    break;

    Block(24) // 0.55%
    ; // pre_call
    switch(nav_stage) {
      Stage(0)
        radio_control.values[0] = (9600*0.550000);
        NextStageAndBreak();
        break;
      Label(while_49)
      Stage(1)
        if (! (TRUE)) Goto(endwhile_50) else NextStageAndBreak();
        Stage(2)
          Goto(while_49)
        Label(endwhile_50)
      default:
      Stage(3)
        NextBlock();
        break;
    }
    ; // post_call
    break;

    Block(25) // 0.6%
    ; // pre_call
    switch(nav_stage) {
      Stage(0)
        radio_control.values[0] = (9600*0.600000);
        NextStageAndBreak();
        break;
      Label(while_51)
      Stage(1)
        if (! (TRUE)) Goto(endwhile_52) else NextStageAndBreak();
        Stage(2)
          Goto(while_51)
        Label(endwhile_52)
      default:
      Stage(3)
        NextBlock();
        break;
    }
    ; // post_call
    break;

    Block(26) // 0.65%
    ; // pre_call
    switch(nav_stage) {
      Stage(0)
        radio_control.values[0] = (9600*0.650000);
        NextStageAndBreak();
        break;
      Label(while_53)
      Stage(1)
        if (! (TRUE)) Goto(endwhile_54) else NextStageAndBreak();
        Stage(2)
          Goto(while_53)
        Label(endwhile_54)
      default:
      Stage(3)
        NextBlock();
        break;
    }
    ; // post_call
    break;

    Block(27) // 0.70%
    ; // pre_call
    switch(nav_stage) {
      Stage(0)
        radio_control.values[0] = (9600*0.700000);
        NextStageAndBreak();
        break;
      Label(while_55)
      Stage(1)
        if (! (TRUE)) Goto(endwhile_56) else NextStageAndBreak();
        Stage(2)
          Goto(while_55)
        Label(endwhile_56)
      default:
      Stage(3)
        NextBlock();
        break;
    }
    ; // post_call
    break;

    Block(28) // 0.75%
    ; // pre_call
    switch(nav_stage) {
      Stage(0)
        radio_control.values[0] = (9600*0.750000);
        NextStageAndBreak();
        break;
      Label(while_57)
      Stage(1)
        if (! (TRUE)) Goto(endwhile_58) else NextStageAndBreak();
        Stage(2)
          Goto(while_57)
        Label(endwhile_58)
      default:
      Stage(3)
        NextBlock();
        break;
    }
    ; // post_call
    break;

    Block(29) // 0.8%
    ; // pre_call
    switch(nav_stage) {
      Stage(0)
        radio_control.values[0] = (9600*0.800000);
        NextStageAndBreak();
        break;
      Label(while_59)
      Stage(1)
        if (! (TRUE)) Goto(endwhile_60) else NextStageAndBreak();
        Stage(2)
          Goto(while_59)
        Label(endwhile_60)
      default:
      Stage(3)
        NextBlock();
        break;
    }
    ; // post_call
    break;

    Block(30) // Fin de test
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
        radio_control.values[0] = 0;
        NextStageAndBreak();
        break;
      Label(while_61)
      Stage(4)
        if (! (TRUE)) Goto(endwhile_62) else NextStageAndBreak();
        Stage(5)
          Goto(while_61)
        Label(endwhile_62)
      default:
      Stage(6)
        NextBlock();
        break;
    }
    ; // post_call
    break;

    Block(31) // HOME
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
