#include "button.h"
#include "application.h"

#define BRIGHTNESS_STEP  5
#define DEBOUNCE_TIMEOUT 50

volatile unsigned long Button::timestamp = 0;
volatile bool Button::buttonPressed = false;

Button::Button()
    : ledBrightness(0),
      increaseLedBrightness(true)
{

}

void Button::init(int buttonPin, int buttonLedPin)
{
    pin = buttonPin;
    ledPin = buttonLedPin;
    pinMode(pin, INPUT_PULLUP);
    pinMode(ledPin, OUTPUT);

    timestamp = millis();
}

void Button::cycleLed()
{
    if (increaseLedBrightness) {
        if (ledBrightness >= 255) {
            increaseLedBrightness = false;
        } else {
            ledBrightness += BRIGHTNESS_STEP;
            analogWrite(ledPin, ledBrightness);
        }
    }
    if (!increaseLedBrightness) {
        if (ledBrightness <= 0) {
            increaseLedBrightness = true;
        } else {
            ledBrightness -= BRIGHTNESS_STEP;
            analogWrite(ledPin, ledBrightness);
        }
    }
}

void Button::flash()
{
    for(int i = 0; i < 5; i++) {
        analogWrite(ledPin, 0);
        delay(100);
        analogWrite(ledPin, 255);
        delay(100);
    }
    ledBrightness = 0;
}

bool Button::pressed()
{
    return buttonPressed;
}

void Button::clearPress()
{
    buttonPressed = false;
    timestamp = millis();
}

void Button::buttonPressedISR()
{
    Serial.println("ISR triggered");
    if (millis() - timestamp < DEBOUNCE_TIMEOUT) {
        return;
    }

    timestamp = millis();
    buttonPressed = true;
}
