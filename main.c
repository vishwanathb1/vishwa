#include <avr/io.h>
#include<util/delay.h>
 uint16_t ReadADC(uint8_t ch);
int main(void)
{

    // Insert code
    TCCR1A|=((1<<COM1A1)|(1<< WGM10)|(1<<WGM11));
    TCCR1B|=((1<<WGM12)|(1<<CS11)|(1<<CS10));
    TCNT1=0x00;
    InitADC();
    uint16_t x = 0;


    DDRB|=(1<<PB1);

    while(1)
    {
      x = ReadADC(0);

          OCR1A= x;
          _delay_ms(500);

    }

    return 0;
}



    void InitADC()
    {
        ADMUX = (1<<REFS0);
        ADCSRA = (1<<ADEN) | (7<<ADPS0);
    }
    uint16_t ReadADC(uint8_t ch)
    {
        ADMUX &= 0XF8;
        ch = ch & 0b00000111;
        ADMUX |= ch;
        ADCSRA |= (1<<ADSC);
        while(!(ADCSRA & (1<<ADIF)));
        ADCSRA |= (1<<ADIF);
        return ADC;
    }
