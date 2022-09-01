#include <Arduino.h>

/*
 *  Project 01-blink_01
 *      Blinks a LED changing blink frequency by pushing a
 *      key connected to ground, so program must add pullup resistor
 *      Prints delay in milliseconds
 *      Austral 2022 - IntroCom - EAM
 */

static const int long_delay = 1000;
static const int short_delay = 100;

static int old_val = 0;

void
setup(void)
{
    pinMode(LED,OUTPUT);
    pinMode(PUSH,INPUT_PULLUP);
    Serial.begin(BAUD);
}

void
loop(void)
{
    int delay_val;

    digitalWrite(LED, !digitalRead(LED));
    delay( delay_val = ( digitalRead(PUSH)==HIGH ? long_delay : short_delay ) );
    if( delay_val != old_val )
        Serial.println(old_val = delay_val);
}
