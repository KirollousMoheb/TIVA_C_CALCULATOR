#include "Calculator.h"
void menu(void)
{
  LCD_command(0x01);
  LCD_command(0X08);
  setRow(0,0);
  LCD_printString("Welcome to My Calculator:"); 
  setRow(1,0);
  LCD_printString("1 -> Basic Calc");
}
void calculator_Init(void)
{
  Init_Keypad();
  LCD_Init();
  
}
