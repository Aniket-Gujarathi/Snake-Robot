/* Extreme values and pin number for each servo
OCR0B = 20; // servo2
OCR0A = 20; // servo4
OCR1B = 28; // servo3
OCR1A = 15; // servo1
OCR0B = 35;
OCR0A = 35;
OCR1B = 15;
OCR1A = 28;
*/
 
#include <avr/io.h>
#include <util/delay.h>

void setup_timer0_pwm(void)
{
  // set PD5 and PD6 as output (these are the OC0A and OC0B pins)(pin D5 and pin D6 on Nano)
  DDRD |= (1 << PD6) | (1 << PD5);
  
  // non-inverting modes for OCR0A and OCR0B and setting fast PWM
  TCCR0A |= (1 << COM0A1) | (1 << COM0B1) | (1 << WGM01) | (1 << WGM00);

  // prescaling by 1024
  TCCR0B |= (1 << CS02) | (1 << CS00);
}

void setup_timer1_pwm(void)
{
  // set PB1 and PB2 as output (these are OC1A and OC1B pins)(pin D9 and pin D10 on Nano)
  DDRB |= (1 << PB1) | (1 << PB2);

  // non-inverting modes for OCR1A and OCR1B and setting 8-bit fast PWM
  TCCR1A |= (1 << COM1A1) | (1 << COM1B1) | (1 << WGM10);
  TCCR1B |= (1 << WGM12);

  // prescaling by 1024
  TCCR1B |= (1 << CS12) | (1 << CS10);
}

int main(void)
{
  setup_timer0_pwm();
  setup_timer1_pwm();
  while (1)
  {
//    OCR0B = 20; // servo2
//    OCR0A = 20; // servo4
    OCR1B = 24; // servo3
    OCR1A = 18; // servo1
    _delay_ms(500);

    OCR1B = 21;
    OCR1A = 21;
    _delay_ms(500);
//    OCR0B = 35;
//    OCR0A = 35;
    OCR1B = 18;
    OCR1A = 24;
    _delay_ms(500);

    OCR1B = 21;
    OCR1A = 21;
    _delay_ms(500);
  }
}
