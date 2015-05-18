#ifndef _PRINTER_H_
#define _PRINTER_H_

#include "Adafruit_Thermal.h"

class Printer
{
public:
    Printer();

    void printString(const char* str);

private:
    Adafruit_Thermal thermal;
};

#endif // _PRINTER_H_
