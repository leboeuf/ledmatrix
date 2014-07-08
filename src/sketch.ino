#include "../lib/HT1632C/ht1632c.cpp"
#include "bitmaps.h"

ht1632c ledmatrix = ht1632c(&PORTD, 7, 6, 4, 5, GEOM_32x16, 2);

String serialCommand = "";  
char s;

void setup ()
{
    ledmatrix.pwm(6);
    ledmatrix.clear();
    
    Serial.begin(9600);
    Serial.println("");
    Serial.println("Arduino LED Matrix ready");

    // Temporary feedback to indicate that the program is started
    ledmatrix.plot(63, 15, ORANGE);
    ledmatrix.sendframe();
}

void loop ()
{
    while (Serial.available() > 0)
    {
        s = (char)Serial.read();
        if (s == '\n')
        {
            handleSerialCommand();
            serialCommand = "";
        }
        else
        {  
            serialCommand += s;
        }
    }
}

void handleSerialCommand()
{
    Serial.println("COMMAND=" + serialCommand);

    if (serialCommand == "clear")
    {
        ledmatrix.clear();
    }
    else if (serialCommand == "plot")
    {
        ledmatrix.plot(0, 0, GREEN);
        ledmatrix.sendframe();
    }
    else if (serialCommand == "test")
    {
        ledmatrix.hscrolltext(0, "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz", GREEN, 60);
        ledmatrix.sendframe();
    }
    else if (serialCommand == "test2")
    {
        // TODO: replace 16,16 by 8,8 for BITMAP_8
        ledmatrix.putbitmap(0, 0, BITMAP_8[0], 16, 16, RED);
        ledmatrix.sendframe();
    }
    else
    {
        // Unrecognized command
        ledmatrix.plot(63, 15, RED);
        ledmatrix.sendframe();
    }
}
