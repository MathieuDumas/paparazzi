#include "vn100.h"
#include "LPC21xx.h"
#include "mcu_periph/spi_arch.h"

#define PINSEL0_SCK  (1 << 8)
#define PINSEL0_SCK_MASK ~(0x03 << 8)
#define PINSEL0_MISO (1 << 10)
#define PINSEL0_MISO_MASK ~(0x03 << 10)
#define PINSEL0_MOSI (1 << 12)
#define PINSEL0_MOSI_MASK ~(0x03 << 12)

/* S0SPCR settings */
#define SPI0_BITENABLE  (0x01 << 2)  /* data size : other than 8 bits   */
#define SPI0_CPHA       (0x00 << 3)  /* clock phase : first edge */
#define SPI0_CPOL       (0x00 << 4)  /* clock polarity : active high */
#define SPI0_MSTR       (0x01 << 5)  /* master mode */
#define SPI0_LSBF       (0x00 << 6)  /* MSB First */
#define SPI0_SPIE       (0x00 << 7)  /* Interrupt : Disable */
#define SPI0_BITS       (0x00 << 8)  /* data size : 16 bits*/

/* SSPCR1 settings */
#define SPI0_LBM  0x00 << 0  /* loopback mode     : disabled                  */
#define SPI0_SSE  0x00 << 1  /* SSP enable        : disabled                  */
#define SPI0_MS   0x00 << 2  /* master slave mode : master                    */
#define SPI0_SOD  0x00 << 3  /* slave output disable : don't care when master */

#define S0SPCCR_VAL 0x04

#define SS_PIN 7
#define SS_BIT 14
#define SS_VAL 0x00
#define SS_PINSEL PINSEL0

#define SPI0_SELECTA_PIN 27
#define SPI0_SELECTB_PIN 26
#define SPI0_SELECT_PINSEL PINSEL2

/* LOCAL FUNCTION DECLARATION */
void SS_On(void);
void SS_Off(void);
uint16_t SPITransmit(uint16_t value);

/* LOCAL FUNCTION DEFINITION */

void SS_On(void){
  IO0SET = _BV(SS_PIN);
}

void SS_Off(void){
  IO0CLR = _BV(SS_PIN);
}

uint16_t SPITransmit(uint16_t value){
  SS_Off();
  S0SPDR = value;
  while(!bit_is_set(S0SPSR, 7)); // While periph busy
  SS_On();

  return S0SPDR;
}

/* PUBLIC FUNCTION DEFINITION */

void VN100_Init(void){
  /* setup pins for SPI0 (SCK, MISO, MOSI) */
  PINSEL0 &= PINSEL0_SCK_MASK & PINSEL0_MISO_MASK & PINSEL0_MOSI_MASK;
  PINSEL0 |= PINSEL0_SCK | PINSEL0_MISO | PINSEL0_MOSI;
  
  SS_PINSEL &= ~(SS_VAL << SS_BIT);
  IO0DIR |= _BV(SS_PIN);
  SS_Off();

  /* setup SPI0 */
  uint32_t *SPI0_CR = (uint32_t*)0xE0020000;
  *SPI0_CR = SPI0_BITENABLE | SPI0_CPHA | SPI0_CPOL | SPI0_MSTR | SPI0_LSBF | SPI0_SPIE | SPI0_BITS;
  S0SPCCR = S0SPCCR_VAL; /* Prescaler */
  
  // Setup SPI0 select pins
  SPI0_SELECT_PINSEL &= ~(1<<3);
  SPI0_SELECT_PINSEL &= ~(1<<2);
  IO1DIR |= _BV(SPI0_SELECTA_PIN);
  IO1DIR |= _BV(SPI0_SELECTB_PIN);
  IO1SET = _BV(SPI0_SELECTA_PIN);
  IO1CLR = _BV(SPI0_SELECTB_PIN);
}

void VN100_Periodic(void){
   SPITransmit(0x55AA);
}
