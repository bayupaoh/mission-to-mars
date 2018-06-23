#include <Wire.h>
#include <LiquidCrystal_I2C.h>

#define BACKLIGHT_PIN 3

LiquidCrystal_I2C lcd(0x27,2,1,0,4,5,6,7,BACKLIGHT_PIN,POSITIVE);

void setup()
{
    pinMode ( BACKLIGHT_PIN, OUTPUT );
    digitalWrite ( BACKLIGHT_PIN, HIGH );
    lcd.begin(16,2);
}

void loop()
{
    lcd.home ();                   // go home (0,0)
    lcd.print("Good Morning");
    lcd.setCursor ( 0, 1 );        // go to the next line
    lcd.print ("Have a nice day");
}

