#include "VAMUdeS_Board/airspeed.h"
#include "estimator.h"
#include "mcu_periph/i2c.h"
#include <math.h>

#define AIRSPEED_ADDR 0b1010000

#ifndef AIRSPEED_I2C_DEV
#define AIRSPEED_I2C_DEV i2c0
#endif

// Extern variables
float airspeedMs;
float temperatureC;

// Local variables
uint16_t airspeedRaw;
uint16_t airspeedRawAvg;
uint16_t temperatureRaw;
uint16_t temperatureRawAvg;
uint8_t  status;
uint8_t  data0, data1, data2, data3;
struct i2c_transaction airspeedI2cTrans;

// Local functions
float temperatureCalc(uint16_t _temperatureRawAvg);
float airspeedCalc(uint16_t _airspeedRawAvg);

extern void airspeedInit( void ){
   airspeedMs     = 0;
   temperatureC   = 0;

   airspeedRaw    = 0;
   airspeedRawAvg = 0;
   temperatureRaw = 0;
   temperatureRawAvg = 0;
   status         = 0;
   data0 = 0;
   data1 = 0;
   data2 = 0;
   data3 = 0;
   airspeedI2cTrans.status = I2CTransDone;
}
   
extern void airspeedRead( void ){   // 60Hz
   airspeedI2cTrans.status = I2CTransDone;
   if (airspeedI2cTrans.status == I2CTransDone){
      I2CReceive(AIRSPEED_I2C_DEV, airspeedI2cTrans, AIRSPEED_ADDR, 4);
   }
   data0 = airspeedI2cTrans.buf[0];
   data1 = airspeedI2cTrans.buf[1];
   data2 = airspeedI2cTrans.buf[2];
   data3 = airspeedI2cTrans.buf[3];
   
   status = (data0 >> 6) & 0x03;
   
   if (status == 0){ // Data is ready
      airspeedRaw    = ((uint16_t)(data0 << 8) & 0x3F00) | ((uint16_t)(data1));
      temperatureRaw = ((uint16_t)(data2 << 3) & 0x07F8) | ((uint16_t)(data3 >> 5) & 0x0007);

      airspeedRawAvg    = (airspeedRawAvg   *(5/6)+airspeedRaw   )/6;
      temperatureRawAvg = (temperatureRawAvg*(5/6)+temperatureRaw)/6;
   }
   else if (status == 1){ // Command Mode WARNING
   }
   else if (status == 2){ // Data not yet ready
   }
   else if (status == 3){ // Diagnostic WARNING
   } else { // Unknown value WARNING
   }
}

extern void airspeedUpdate( void ){ // 10Hz
   temperatureC = temperatureCalc(temperatureRawAvg);
   airspeedMs   = airspeedCalc(airspeedRawAvg);
   EstimatorSetAirspeed(airspeedMs);
}

float temperatureCalc(uint16_t _temperatureRawAvg){
   float _temperatureC = ((float)(_temperatureRawAvg)/10.235)-50;
   return _temperatureC;
}

float airspeedCalc(uint16_t _airspeedRawAvg){
   // Switch uint16_t to PSI           PSI = (uint16_t/8192) - 1
   // PSI to Pa                        Pa  = PSI * 6894.75729
   // Pa to m/s                        m/s = sqrt(2*Pa/1.225)
   
   float _airspeedMs = 0;
   if (_airspeedRawAvg < 8192){
      _airspeedMs = -sqrtf(-(1.37411*(float)(_airspeedRawAvg)-11256.7));
   } else {
      _airspeedMs = sqrtf(1.37411*(float)(_airspeedRawAvg)-11256.7);
   }
   
   return _airspeedMs;
}
