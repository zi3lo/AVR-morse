#include "Morse.hpp"


Morse::Morse(const char s[])
{
    s2b = s;
    lenght = strlen(s2b);
}

void Morse::port_init()
{
    BLINK_DDR |= BLINK; // jako wyjście
    BLINK_PORT &= ~BLINK; // gasimy gdyby świeciło ;p
}

void Morse::blink(uint16_t wpm)
{
    port_init(); //porty etc..
    ditT = set_dot_time(wpm); // kropka = wyliczenie z wpm
    dahT = 3*ditT; // kreska = 3 kropki

    for (uint16_t i = 0; i < lenght; i++)
    {
        if (s2b[i] == ' ')
        {
            delay_ms(6*ditT); // przerwa między słowami 7 * dit (1 po błysku + 6)
        }
        else
        {
            l2b(s2b[i]); // migamy znak;
            delay_ms(2*ditT); // przerwa po znaku 3 * dit (1 po błysku + 2)
        }
    }

}

uint16_t Morse::set_dot_time(uint16_t wpm)
{
    return uint16_t(1200/wpm);
}

void Morse::dit()
{
    BLINK_PORT |= BLINK; // zapalamy
    delay_ms(ditT); // milisekundy dit
    BLINK_PORT &= ~BLINK; // gasimy
    delay_ms(ditT); // przerwa po błysku
}

void Morse::dah()
{
    BLINK_PORT |= BLINK; // zapalamy
    delay_ms(dahT); // milisekundy dah
    BLINK_PORT &= ~BLINK; // gasimy
    delay_ms(ditT); // przerwa po błysku
}

void Morse::delay_ms(uint16_t ms)
{
    while (ms-- > 0)
    {
        _delay_ms(1);
    }
}


/////  ZNAKI ///////
void Morse::l2b(char l)
{
    l = tolower(l);
    switch(l)
    {
        case 'a':
            dit(); dah();
            break;
        case 'b':
            dah(); dit(); dit(); dit();
            break;
        case 'c':
            dah(); dit(); dah(); dit();
            break;
        case 'd':
            dah(); dit(); dit();
            break;
        case 'e':
            dit();
            break;
        case 'f':
            dit(); dit(); dah(); dit();
            break;
        case 'g':
            dah(); dah(); dit();
            break;
        case 'h':
            dit(); dit(); dit(); dit();
            break;
        case 'i':
            dit(); dit();
            break;
        case 'j':
            dit(); dah(); dah(); dah();
            break;
        case 'k':
            dah(); dit(); dah();
            break;
        case 'l':
            dit(); dah(); dit(); dit();
            break;
        case 'm':
            dah(); dah();
            break;
        case 'n':
            dah(); dit();
            break;
        case 'o':
            dah(); dah(); dah();
            break;
        case 'p':
            dit(); dah(); dah(); dit();
            break;
        case 'q':
            dah(); dah(); dit(); dah();
            break;
        case 'r':
            dit(); dah(); dit();
            break;
        case 's':
            dit(); dit(); dit();
            break;
        case 't':
            dah();
            break;
        case 'u':
            dit(); dit(); dah();
            break;
        case 'v':
            dit(); dit(); dit(); dah();
            break;
        case 'w':
            dit(); dah(); dah();
            break;
        case 'x':
            dah(); dit(); dit(); dah();
            break;
        case 'y':
            dah(); dit(); dah(); dah();
            break;
        case 'z':
            dah(); dah(); dit(); dit();
            break;
        case '1':
            dit(); dah(); dah(); dah(); dah();
            break;
        case '2':
            dit(); dit(); dah(); dah(); dah();
            break;
        case '3':
            dit(); dit(); dit(); dah(); dah();
            break;
        case '4':
            dit(); dit(); dit(); dit(); dah();
            break;
        case '5':
            dit(); dit(); dit(); dit(); dit();
            break;
        case '6':
            dah(); dit(); dit(); dit(); dit();
            break;
        case '7':
            dah(); dah(); dit(); dit(); dit();
            break;
        case '8':
            dah(); dah(); dah(); dit(); dit();
            break;
        case '9':
            dah(); dah(); dah(); dah(); dit();
            break;
        case '0':
            dah(); dah(); dah(); dah(); dah();
            break;
    }
}
