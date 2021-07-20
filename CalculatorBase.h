#ifndef __CALCULATOR_BASE_H__
#define __CALCULATOR_BASE_H__
#include "Calculator.h"
#include "Calculations.h"

#include "LCD.h"
#include "Keypad.h"
#include "Dealy.h"

void  getStarted   (void);
char  scanKeypad   (void);

void  store        (volatile double, double*);
double memfinalize (double*);

#endif

