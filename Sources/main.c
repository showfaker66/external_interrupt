/* ###################################################################
**     Filename    : main.c
**     Processor   : S32K1xx
**     Abstract    :
**         Main module.
**         This module contains user's application code.
**     Settings    :
**     Contents    :
**         No public methods
**
** ###################################################################*/
/*!
** @file main.c
** @version 01.00
** @brief
**         Main module.
**         This module contains user's application code.
*/         
/*!
**  @addtogroup main_module main module documentation
**  @{
*/         
/* MODULE main */


/* Including necessary module. Cpu.h contains other modules needed for compiling.*/
#include "Cpu.h"
//#include "delay.h"
//#include "uart.h"
//#include "key.h"
//#include "oled.h"

volatile int exit_code = 0;
//#define LED1(x)     PINS_DRV_WritePin(PTD,16,!x);
//#define LED1(x)     PINS_DRV_WritePin(PTD,15,!x);
//#define LED1(x)     PINS_DRV_WritePin(PTD,0,!x);

/* User includes (#include below this line is not maintained by Processor Expert) */

/*! 
  \brief The main function for the project.
  \details The startup initialization sequence is the following:
 * - startup asm routine
 * - main()
*/
  //端口中断状态位,判断哪个按键触发中断
void PTC_EXT_IRQ (void)
{
	uint32_t buttonsPrssed = PINS_DRV_GetPortIntFlag(PORTC) & (( 1 << 12 ) | ( 1 << 13) );
	if(buttonsPrssed !=0)
	{
		if( ((buttonsPrssed >>12) & 0x01) ==1 )
		{
			PINS_DRV_TogglePins(PTD,1<<0);
		}
		if( ((buttonsPrssed >>13) & 0x01) ==1 )
		{
			PINS_DRV_TogglePins(PTD,1<<15);
		}
	}
PINS_DRV_ClearPortIntFlagCmd(PORTC);
}
void delay(volatile int cycles)
{
	/* Delay function - do nothing for a number of cycles */
	while(cycles--);
}
int main(void)
 {
  /* Write your local variable definition here */

  /*** Processor Expert internal initialization. DON'T REMOVE THIS CODE!!! ***/
  #ifdef PEX_RTOS_INIT
    PEX_RTOS_INIT();                   /* Initialization of the se lected RTOS. Macro is defined by the RTOS component. */
  #endif
  /*** End of Processor Expert internal initialization.                    ***/
      CLOCK_SYS_Init(g_clockManConfigsArr, CLOCK_MANAGER_CONFIG_CNT,
 					 g_clockManCallbacksArr, CLOCK_MANAGER_CALLBACK_CNT);
 	  CLOCK_SYS_UpdateConfiguration(0U, CLOCK_MANAGER_POLICY_AGREEMENT);
 	  PINS_DRV_Init(NUM_OF_CONFIGURED_PINS, g_pin_mux_InitConfigArr);
 	  PINS_DRV_SetPinIntSel(PORTC,12,PORT_INT_RISING_EDGE);//(端口号,号数,上升沿触发)(中断条件)
 	  PINS_DRV_SetPinIntSel(PORTC,13,PORT_INT_RISING_EDGE);

 	  INT_SYS_InstallHandler(PORTC_IRQn,&PTC_EXT_IRQ,NULL);
      INT_SYS_EnableIRQ(PORTC_IRQn);

 	  LPUART_DRV_Init(INST_LPUART1, &lpuart1_State, &lpuart1_InitConfig0);


 	  while(1)
 	  {
 		  delay(100);
 	  }

  /* Write your code here */
  /* For example: for(;;) { } */

  /*** Don't write any code pass this line, or it will be deleted during code generation. ***/
  /*** RTOS startup code. Macro PEX_RTOS_START is defined by the RTOS component. DON'T MODIFY THIS CODE!!! ***/
  #ifdef PEX_RTOS_START
    PEX_RTOS_START();                  /* Startup of the selected RTOS. Macro is defined by the RTOS component. */
  #endif
  /*** End of RTOS startup code.  ***/
  /*** Processor Expert end of main routine. DON'T MODIFY THIS CODE!!! ***/
  for(;;) {
    if(exit_code != 0) {
      break;
    }
  }
  return exit_code;
  /*** Processor Expert end of main routine. DON'T WRITE CODE BELOW!!! ***/
} /*** End of main routine. DO NOT MODIFY THIS TEXT!!! ***/

/* END main */
/*!
** @}
*/
/*
** ###################################################################
**
**     This file was created by Processor Expert 10.1 [05.21]
**     for the NXP S32K series of microcontrollers.
**
** ###################################################################
*/
