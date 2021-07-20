#include "CalculatorBase.h"
int memcount = 0;
float mem2[10]  = {0};
volatile unsigned char a;

char scanKeypad(void)
{ 
  a = getKey();
  return a;
}
void getStarted(void)
{
	int c = 0;
  menu();//Print the welcome message and the menu
  
  c = scanKeypad();
  switch (c)
  {
  case '1':                        
    
    calculate();
    break;
	default:
		getStarted();
		
  }
}


void store(volatile double no, double* mem2)
{
  *(mem2 + memcount) = no;
  memcount++;
}

double memfinalize(double* mem2)
{
	int j;
	int k;
  const int mul[10] = {1 , 10, 100, 1000, 
                     10000, 100000, 1000000, 
                     10000000, 100000000, 1000000000};
  double memreturn = 0;
  for( j = 0; j < 10; j++)
  {
    memreturn += ((mem2[j]) * mul[memcount-1]);
    memcount--;
    if(memcount == -1)
      break;
  }
  for( k = 0; k < 10; k++)
    mem2[k] = 0;
  memcount = 0;
  return memreturn;
}

