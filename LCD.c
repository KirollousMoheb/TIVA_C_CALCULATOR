#include "LCD.h"
/****************************************************
*    Command  *  Discription         
*  ***********************************
*     0x01    *  Clear display screen
*     0x02    *  Return to home position
*     0x04    *  Shift cursor to left
*     0x06    *  Shift cursor to right
*     0x05    *  Shift display right
*     0x07    *  Shift display left
*     0x08    *  Display off, Cursor off
*     0x0A    *  Display off, Cursor on
*     0x0C    *  Display on , Cursor off
*     0x0E    *  Display on , Cursor on 
*     0x0F    *  Display on , Cursor blinking
*     0x10    *  Shift cursor position to left
*     0x14    *  Shift cursor position to right
*     0x18    *  Shift entire display to left
*     0x1C    *  Shift entire display to right
*     0x20    *  Function set : 4-bit, 1 lines, 5x7 matrix
*     0x28    *  Function set : 4-bit, 2 lines, 5x7 matrix
*     0x30    *  Function set : 8-bit, 1 lines, 5x7 matrix
*     0x38    *  Function set : 8-bit, 2 lines, 5x7 matrix
*     0x80    *  Force cursor to start from 1st line
*     0xC0    *  Force cursor to start from 2nd line

*  
****************************************************/
void LCD_command(unsigned int command)
{
  GPIO_PORTA_DATA_R = 0x20;               //set RS to 1 to enable Command Register and RW to low to write to the LCD
  GPIO_PORTB_DATA_R = command;
  GPIO_PORTA_DATA_R = 0x80;
  delay_micro(1);
  GPIO_PORTA_DATA_R = 0x00;                  //High to Low pulse to push the command to the LCD
  if (command < 4) 
    delay_milli(2);                          // command 1 and 2 needs up to 1.64ms 
  else             
    delay_micro(40);                         // all others 40 us
}

void LCD_Init(void){
SYSCTL_RCGCGPIO_R |= 0x03;              // enable clock to port A & B
while ((SYSCTL_RCGCGPIO_R&0x03)==0);    //wait for clock to be enabled
GPIO_PORTA_CR_R  |= 0xE0;               // allow changes to all the bits in port A
GPIO_PORTA_DIR_R |= 0xE0;               // set PORTA pin 7-5 as output for control
GPIO_PORTA_DEN_R |= 0xE0;               // set PORTA pin 7-5 as digital pins 
GPIO_PORTB_CR_R  |= 0xFF;                // allow changes to all the bits in port B
GPIO_PORTB_DIR_R |= 0xFF;               // set all PORTB pins as output for data
GPIO_PORTB_DEN_R |= 0xFF;               // set all PORTB pins as digital pins


delay_milli(20);
LCD_command(0X38);//Function set : 8-bit, 2 lines, 5x7 matrix
delay_milli(5);
LCD_command(0X38);//Function set : 8-bit, 2 lines, 5x7 matrix
delay_micro(100);
LCD_command(0X38);//Function set : 8-bit, 2 lines, 5x7 matrix
LCD_command(0X08);//Display off cursor off 
LCD_command(0X01);//Clear display            
LCD_command(0X06);//Shift cursor to right
LCD_command(0X0E);//Display on , Cursor on 


}
void LCD_data(unsigned char data)
{ 
  GPIO_PORTA_DATA_R = 0x20;              
  GPIO_PORTB_DATA_R = data;
  GPIO_PORTA_DATA_R = 0x80 | 0x20;
  delay_micro(1);
  GPIO_PORTA_DATA_R = 0;              
  delay_micro(40);
}
void LCD_printInt(int number)
{
	 int i = 0;
  char toprint[4] = {0};
  sprintf(toprint, "%d", number);
 
  while(toprint[i] != '\0')
  {
    LCD_data(toprint[i]);
    i++;
  }
}


void LCD_printdouble(double number)
{
   int j = 0;
  int len = snprintf('\0', 0, "%f", number);
  char* toprint = (char *)malloc(len + 1);
  snprintf(toprint, len + 1, "%f", number);
 
  while (j < len - 3 )
  {
    LCD_data(toprint[j]);
    j++;
  }
  free(toprint);
}


void LCD_printString(char* str)
{
	int i = 0;
  LCD_command(0X0C);
  
  while (str[i] != '\0')
  {
    LCD_data(str[i]);
    i++;
  }
}


void setRow(unsigned int row, unsigned int col)
{
  int command = 0x00;
  if( row == 0)
  {
    command = 0x80;
    while(col <=  0x0F && col >= 0x00)
    {
      LCD_command(command + col);
      break;
    }
  }
    if( row == 1)
  {
    command = 0xC0;
    while(col <=  0x0F && col >= 0x00)
    {
      LCD_command(command + col);
      break;
    }
  }

}

