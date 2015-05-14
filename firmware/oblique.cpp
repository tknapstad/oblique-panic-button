#include "application.h"
#include "randomiser.h"
#include "data.h"
#include "button.h"

int buttonPin = D2;
int buttonLedPin = A0;

int ledPin    = D7;

Data data;
Button button;

void test(USARTSerial* serial)
{
    Serial.println((int)serial, HEX);
}

/**
 * Returns true or false randomly
 */
bool coinFlip();

void onButtonPressedISR();

void printRandomEntry();

void setup() {
    RGB.control(true);
    RGB.brightness(1);
    RGB.control(false);

    pinMode(ledPin, OUTPUT);

    button.init(buttonPin, buttonLedPin);
//    attachInterrupt(buttonPin, onButtonPressedISR, FALLING);
    attachInterrupt(buttonPin, &Button::buttonPressedISR, FALLING);

    Serial.begin(9600);
    //while(!Serial.available()) SPARK_WLAN_Loop();

    //Serial1.begin(9600);

    //data.addUserEntry("testing testing");
}

void loop() {
//    digitalWrite(ledPin, HIGH);
//    delay(1000);
//    digitalWrite(ledPin, LOW);
//    delay(1000);

    button.cycleLed();
    delay(100);
    if (button.pressed()) {
        Serial.println("Button pressed");
        button.flash();
        printRandomEntry();
        button.clearPress();
    }
}

void printRandomEntry() {
    //int entry = randomEntry();
//    Serial1.println(oblique_4th_ed[entry]);
    //Serial.println(oblique_entries[entry]);
}

bool coinFlip()
{
    return random(2);
}
