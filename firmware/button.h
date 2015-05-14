#ifndef _BUTTON_H_
#define _BUTTON_H_

class Button
{
public:
    Button();

    void init(int buttonPin, int buttonLedPin);

    void cycleLed();

    void flash();

    bool pressed();

    void clearPress();

    static void buttonPressedISR();
private:
    int pin;
    int ledPin;

    int ledBrightness;
    bool increaseLedBrightness;
    static volatile unsigned long timestamp;
    static volatile bool buttonPressed;
};

#endif // _BUTTON_H_
