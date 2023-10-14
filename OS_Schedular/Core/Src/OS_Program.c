/*
 * OS_Program.c
 *
 *  Created on: Oct 12, 2023
 *      Author: Administrator
 */


#include "../Inc/OS_Interface.h"
#include "../Inc/OS_Private.h"
#include "../Inc/OS_Config.h"



/* Create array of tasks "Array of structures"*/

Task OS_Tasks[NUM_OF_TASKS] = {0};


/*  Create a local variable to be incremented every calling of Systick handler*/
volatile uint32_t Tick_counts = 0;

/*
 * Function_Name : OS_CreateTask
 *
 * Arguments : a_priority
 * 			 : Variable to assign a priority to the task
 *
 * 			 : a_periodicity
 * 			 : Variable to assign a periodicity of the task
 *
 * 			 : Fptr
 * 			 : Pointer to function which holds the address of the function to be executed
 *
 * */

void OS_CreateTask (uint8_t a_priority ,uint16_t a_periodicity, void (*Fptr) (void))
{
	OS_Tasks[a_priority].periodicity=a_periodicity;
	OS_Tasks[a_priority].ptr=Fptr;
}

void OS_Start (void)
{
	SysTick->CTRL = 0;
	SysTick->VAL = 0;
	SysTick->CTRL = (SysTick_CTRL_TICKINT_Msk|
			SysTick_CTRL_ENABLE_Msk|
			SysTick_CTRL_CLKSOURCE_Msk);
}

void OS_Scheduler (void)
{
	uint8_t i;

	for(i=0;i<NUM_OF_TASKS;i++)
	{

		/* Check if the tick counts matches or a multiple of the task periodicity */

		if ( ( (OS_Tasks[i].ptr) != 0) && (Tick_counts % OS_Tasks[i].periodicity) == 0 )
		{
			OS_Tasks[i].ptr();			/*Call the function*/
		}

		else
		{
			/* do nothing*/
		}
	}

	Tick_counts++;
}
