#include "power_led.h"
#include "LPC21xx.h"

#define LEFTWING_PWR_PIN 19
#define RIGHTWING_PWR_PIN 18
#define TAIL_PWR_PIN 22

#define POWERLED_PINSEL PINSEL2

#define OFF      0
#define ON       1
#define FLASH_1S 2
#define FLASH_2S 3

uint8_t LeftWing_State, RightWing_State, Tail_State;

uint8_t LeftWing_Timer, RightWing_Timer, Tail_Timer;

void PowerLed_Init(void){
  POWERLED_PINSEL &= ~(0<<3);
  POWERLED_PINSEL &= ~(0<<2);
  IO1DIR |= _BV(LEFTWING_PWR_PIN);
  IO1DIR |= _BV(RIGHTWING_PWR_PIN);
  IO1DIR |= _BV(TAIL_PWR_PIN);
  LeftWing_State = OFF;
  RightWing_State = OFF;
  Tail_State = OFF;
  LeftWing_Timer = 0;
  RightWing_Timer = 0;
  Tail_Timer = 0;
}

void PowerLed_Periodic(void){
  // Left Wing
  if (LeftWing_State == OFF)
    IO1CLR = _BV(LEFTWING_PWR_PIN);
  else if (LeftWing_State == ON)
    IO1SET = _BV(LEFTWING_PWR_PIN);
  else if (LeftWing_State == FLASH_1S){
    if (LeftWing_Timer == 0){
      LeftWing_Timer++;
      IO1CLR = _BV(LEFTWING_PWR_PIN);
    }
    else{
      LeftWing_Timer = 0;
      IO1SET = _BV(LEFTWING_PWR_PIN);
    }
  }
  else if (LeftWing_State == FLASH_2S){
    if (LeftWing_Timer == 0 || LeftWing_Timer == 1){
      LeftWing_Timer++;
      IO1CLR = _BV(LEFTWING_PWR_PIN);
    }
    else if (LeftWing_Timer == 2){
      LeftWing_Timer++;
      IO1SET = _BV(LEFTWING_PWR_PIN);
    }
    else{
      IO1SET = _BV(LEFTWING_PWR_PIN);
      LeftWing_Timer = 0;
    }
  }
  else
    IO1CLR = _BV(LEFTWING_PWR_PIN);
  
  // Right Wing
  if (RightWing_State == OFF)
    IO1CLR = _BV(RIGHTWING_PWR_PIN);
  else if (RightWing_State == ON)
    IO1SET = _BV(RIGHTWING_PWR_PIN);
  else if (RightWing_State == FLASH_1S){
    if (RightWing_Timer == 0){
      RightWing_Timer++;
      IO1CLR = _BV(RIGHTWING_PWR_PIN);
    }
    else{
      RightWing_Timer = 0;
      IO1SET = _BV(RIGHTWING_PWR_PIN);
    }
  }
  else if (RightWing_State == FLASH_2S){
    if (RightWing_Timer == 0 || RightWing_Timer == 1){
      RightWing_Timer++;
      IO1CLR = _BV(RIGHTWING_PWR_PIN);
    }
    else if (RightWing_Timer == 2){
      RightWing_Timer++;
      IO1SET = _BV(RIGHTWING_PWR_PIN);
    }
    else{
      IO1SET = _BV(RIGHTWING_PWR_PIN);
      RightWing_Timer = 0;
    }
  }
  else
    IO1CLR = _BV(RIGHTWING_PWR_PIN);
    
  // Tail Wing
  if (Tail_State == OFF)
    IO1CLR = _BV(TAIL_PWR_PIN);
  else if (Tail_State == ON)
    IO1SET = _BV(TAIL_PWR_PIN);
  else if (Tail_State == FLASH_1S){
    if (Tail_Timer == 0){
      Tail_Timer++;
      IO1CLR = _BV(TAIL_PWR_PIN);
    }
    else{
      Tail_Timer = 0;
      IO1SET = _BV(TAIL_PWR_PIN);
    }
  }
  else if (Tail_State == FLASH_2S){
    if (Tail_Timer == 0 || Tail_Timer == 1){
      Tail_Timer++;
      IO1CLR = _BV(TAIL_PWR_PIN);
    }
    else if (Tail_Timer == 2){
      Tail_Timer++;
      IO1SET = _BV(TAIL_PWR_PIN);
    }
    else{
      IO1SET = _BV(TAIL_PWR_PIN);
      Tail_Timer = 0;
    }
  }
  else
    IO1CLR = _BV(TAIL_PWR_PIN);
}
