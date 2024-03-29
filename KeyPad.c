#include "KeyPad.h"

/****************************************************/   
/*
*  Hardware Connentions
*
* [PE1 - PE4] -> [R1 - R4]  Rows
* [PC4 - PC7] -> [C1 - C4]  Columns
*  
****************************************************/

//values corresponding to each cell in the keypad
//'.' is used to clear the screen adn restart the running operation

unsigned char values[4][4]={{'1','2','3','+'},{'4','5','6','-'},{'7','8','9','*'},{'.','0','=','/'}};




void Init_Keypad(){
  SYSCTL_RCGCGPIO_R |= 0x14;       			//Clock for port C and E    
  while ((SYSCTL_RCGCGPIO_R&0x14)==0);	//wait for clock to be enabled
  GPIO_PORTE_LOCK_R=0x4C4F434B;					//open lock for port E
  GPIO_PORTC_LOCK_R=0x4C4F434B;					//open lock for port C
  GPIO_PORTC_CR_R  |= 0xF0;            
  GPIO_PORTE_CR_R  |= 0x1E;            
  GPIO_PORTC_DIR_R |= 0xF0;             //Columns are output
  GPIO_PORTE_DIR_R |= 0x00;            	//Rows are input
  GPIO_PORTE_PDR_R |= 0x1E;           
  GPIO_PORTC_DEN_R |= 0xF0;            	//Digital enable for port C(7-4)
  GPIO_PORTE_DEN_R |= 0x1E; 						//Digital enable for port E(7-4)


}
char getKey(void){
	int i;int j;
  while(1)
  {
    for( i = 0; i < 4; i++)                        //columns traverse
    {
      GPIO_PORTC_DATA_R = (1U << (i+4));
      
      for( j = 0; j < 4; j++)                     //raws traverse
      {
        if((GPIO_PORTE_DATA_R & 0x1E) & (1U << (j+1)))
          return values[j][i];
      }
    }	
  }
}

