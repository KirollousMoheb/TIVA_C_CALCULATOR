#ifndef _Calculations_
#define _Calculations_
#include "CalculatorBase.h"
#include "LCD.h"
#include "KeyPad.h"
#include "Dealy.h"

void calculate         (void);
void LCD_Calc   (void);
void printResult    (double);

void add          (double, double);
void sub          (double, double);
void mult         (double, double);
void divide        (double, double);


#endif

