#include "application.h"
#include "randomiser.h"
#include "data.h"

#define DEBOUNCE_TIMEOUT 20

int buttonPin = D2;
int ledPin    = D7;

volatile unsigned long timestamp = 0;
volatile bool buttonPressed = 0;

Data data;

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
    pinMode(buttonPin, INPUT);

    attachInterrupt(buttonPin, onButtonPressedISR, RISING);

    Serial.begin(9600);
    while(!Serial.available()) SPARK_WLAN_Loop();

    Serial1.begin(9600);

    Serial.println("Hello spark");
    Serial.print("Oblique count: ");
//    Serial.println(obliqueCount, DEC);
    test(&Serial1);
    data.addUserEntry("testing testing");
}

void loop() {
    digitalWrite(ledPin, HIGH);
    delay(1000);
    digitalWrite(ledPin, LOW);
    delay(1000);

    if (buttonPressed) {
        printRandomEntry();
    }
}

void printRandomEntry() {
    //int entry = randomEntry();
//    Serial1.println(oblique_4th_ed[entry]);
    //Serial.println(oblique_entries[entry]);
}

void onButtonPressedISR() {
    if (millis() - timestamp < DEBOUNCE_TIMEOUT) {
        return;
    }

    timestamp = millis();
    buttonPressed = true;
}

bool coinFlip()
{
    return random(2);
}
