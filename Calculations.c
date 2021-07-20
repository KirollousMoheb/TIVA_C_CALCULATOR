#include "Calculations.h"
double mem[10]  = {0};

double result   = 0;
double num1 = 0;
double num2 = 0;

char opsympo  = '0';
char addition  = '0';
char subtract  = '0';
char multiply  = '0';
char division  = '0';

volatile unsigned char key;
volatile double doublekey;


void printResult(double result)
{
  LCD_command(0X0C); //Display on and cursor is off
  LCD_command(0XC0);	//Cursor start on 2nd line
  LCD_printdouble(result);//print the result as a double
}
//Function to add 2 numbers
void add(double num1,double num2){
result=num1+num2;
printResult(result);
}
//Function to subtract 2 numbers
void sub(double num1,double num2){
result=num1-num2;
printResult(result);
}
//Function to multiply 2 numbers
void mult(double num1,double num2){
result=num1*num2;
printResult(result);
}
//Function to divide 2 numbers
void divide(double num1,double num2){
result=num1/num2;
printResult(result);
}


void LCD_Calc(void){
	LCD_command(0X0E);//Display On and Cursor On
  delay_milli(50);
  LCD_command(0x10);//Clear display
  delay_milli(50);
  LCD_command(0x10);//Clear display
  delay_milli(50);
  LCD_command(0x10);//Clear display
  delay_milli(50);
  LCD_command(0x10);//Clear display
  LCD_command(0X80);//Cursor start on 2nd line
  LCD_command(0X0E);//Cursor On and diplay On
  LCD_command(0X0F);//Display On Cursor Blink
}
void calculate(void){
LCD_Calc();//Start calculations on 2nd line
	
	while(1)
  {
    key = getKey();//get key pressed
    if      (key != '.')//if not clear('.')
    {
      if  (addition == '1')//check addition
      {
        LCD_data(key);
        if(key == '=')//print entered niumbers and operation until equal is presssed
        {
          num2 = memfinalize(mem);
          add(num1,num2);
            num1 = 0;num2 = 0;result    = 0;doublekey  = 0;addition  = '0';subtract  = '0';multiply  = '0';division  = '0';
        }
        else
        {
          doublekey = key - 48;       //////////ASCI Compensation
          store(doublekey, mem);
        }
        delay_milli(500);
      }
      else if (subtract == '1')//check subtraction
      {
        LCD_data(key);//print entered niumbers and operation until equal is presssed
        if(key=='=')
        {
          num2 = memfinalize(mem);
          sub(num1, num2);
         num1 = 0;num2 = 0;result    = 0;doublekey  = 0;addition  = '0';subtract  = '0';multiply  = '0';division  = '0';
        }
        else
        {
          doublekey = key - 48;      //////////ASCI Compensation
          store(doublekey, mem);
        }
        delay_milli(500);  
      }
      else if (multiply == '1')//check multiplication
      {
        LCD_data(key);//print entered niumbers and operation until equal is presssed
        if(key == '=')
        {
          num2 = memfinalize(mem);
          mult(num1,num2);
         num1 = 0;num2 = 0;result    = 0;doublekey  = 0;addition  = '0';subtract  = '0';multiply  = '0';division  = '0';
        }
        else
        {
          doublekey = key - 48;     //////////ASCI Compensation
          store(doublekey, mem);
        }
        delay_milli(500);
      }
      else if (division == '1')//check divison
      {
        LCD_data(key);//print entered niumbers and operation until equal is presssed
        if(key=='=')
        {
          num2 = memfinalize(mem);
          divide(num1,num2);
         num1 = 0;num2 = 0;result    = 0;doublekey  = 0;addition  = '0';subtract  = '0';multiply  = '0';division  = '0';
        }
        else
        {
          doublekey = key - 48;   //////////ASCI Compensation
          store(doublekey, mem);
        }
        delay_milli(500); 
      }
      else 
      {
        LCD_data(key);
        switch (key)
        {
      case '+':
            addition = '1';
            num1 = memfinalize(mem);
            break;
      case '-':
            subtract = '1';
            num1 = memfinalize(mem);
            break;
      case '*':
            multiply = '1';
            num1 = memfinalize(mem);
            break;
      case '/':
            division = '1';
            num1 = memfinalize(mem);
            break;
      default:
          doublekey = key - 48;   //////////ASCI Compensation
          store(doublekey, mem);
        }
        delay_milli(500);
      }
    }
    else if (key == '.')//Clear all data if ('.') is pressed
    {
      LCD_Calc();
      num1 = 0;num2 = 0;result    = 0;doublekey  = 0;addition  = '0';subtract  = '0';multiply  = '0';division  = '0';
      delay_milli(50);
      num1 = 0;num2 = 0;result    = 0;doublekey  = 0;addition  = '0';subtract  = '0';multiply  = '0';division  = '0';
      delay_milli(50);
      num1 = 0;num2 = 0;result    = 0;doublekey  = 0;addition  = '0';subtract  = '0';multiply  = '0';division  = '0';
      delay_milli(50);
      num1 = 0;num2 = 0;result    = 0;doublekey  = 0;addition  = '0';subtract  = '0';multiply  = '0';division  = '0';
    }
  }
}


