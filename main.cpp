/*

 */
#define F_CPU 1000000UL
#include <avr/io.h>
#include <util/delay.h>
#include <stdio.h>
#include <Morse.hpp>

//#define BLINK_PORT (1 << PD0)
//#define BLINK_DDR DDRD

int main(void)
{
    const char text[] = "SOS to tajny kod";
    Morse morsik(text);

    //while(1)
    //{
        morsik.blink(10);
   // }



    /*
    DDRD |= BLINK_PORT; // PD0 jako wyjście

    while(1) // pętla główna
    {
        PORTD ^= BLINK_PORT; // naprzemienna zmiana stanu
        _delay_ms(1000);
    }
    */

    return 0;
}
