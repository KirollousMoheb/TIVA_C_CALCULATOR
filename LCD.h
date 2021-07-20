#ifndef _LCD_
#define _LCD_
#include <stdio.h>          // printf, scanf, NULL 
#include <stdlib.h>         // malloc, free, rand 
#include "tm4c123gh6pm.h"
#include "Dealy.h"


void LCD_Init              (void);
void LCD_command           (unsigned int);
void LCD_data              (unsigned char);
void LCD_printInt          (int);
void LCD_printdouble        (double);
void LCD_printString       (char*);

void setRow   (unsigned int, unsigned int);


#endif

