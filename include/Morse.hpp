#ifndef MORSE_H
#define MORSE_H

/* Definiowanie portu do mrugania */

#define BLINK (1 << PD0)
#define BLINK_DDR DDRD
#define BLINK_PORT PORTD

/* ***************************** */

#include <avr/io.h>
#include <util/delay.h>
#include <ctype.h> // tolower
#include <string.h> // strlen

class Morse
{
    public:
        Morse(const char[]); // konstruktor
        void blink(uint16_t); // metoda mrugająca string z określoną prędkością (wpm)

    private:
        const char* s2b; // string 2 blink ;p - wskaźnik do tablicy
        uint16_t ditT, dahT, wpm, lenght; // najmniejsza jednostka (kroka / krótka przerwa), kreska, zadana prędkość i dł ciągu
        void port_init(); // inicjalizacja portu jako wyjście
        void l2b(char); // metoda mrugania literki
        uint16_t set_dot_time(uint16_t); // ustalenie czasu kropki na podstawie wpm
        void dit();
        void dah();
        void delay_ms(uint16_t); // bo oryginalna _delay_ms ma za parametr const
};

#endif // MORSE_H
