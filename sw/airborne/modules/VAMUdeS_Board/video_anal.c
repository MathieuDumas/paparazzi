#include "video_anal.h"
#include "LPC21xx.h"

#define VIDEOANAL_PWR_PIN 24
#define VIDEOANAL_PWR_PINSEL PINSEL2
#define VIDEOANAL_CAMSELECT_PIN 28

bool_t VideoAnal_Status;

void Cam_Select(uint8_t cam);

void VideoAnal_Init(void){
  VIDEOANAL_PWR_PINSEL |= (0<<3);
  VIDEOANAL_PWR_PINSEL |= (0<<2);
  IO1DIR |= _BV(VIDEOANAL_PWR_PIN);
  IO1DIR |= _BV(VIDEOANAL_CAMSELECT_PIN);
  VideoAnal_Status = 0;
  IO1SET = _BV(VIDEOANAL_PWR_PIN);
  Cam_Select(1);
}

void VideoAnal_Periodic(void){
  if (VideoAnal_Status)
    IO1SET = _BV(VIDEOANAL_PWR_PIN);
  else
    IO1CLR = _BV(VIDEOANAL_PWR_PIN);
}

void Cam_Select(uint8_t cam){
  if (cam==0)
    IO1CLR = _BV(VIDEOANAL_CAMSELECT_PIN);
  else
    IO1SET = _BV(VIDEOANAL_CAMSELECT_PIN);
}
