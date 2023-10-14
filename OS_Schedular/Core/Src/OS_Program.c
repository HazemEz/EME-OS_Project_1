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

volatile uint32_t Tick_counts = 0;



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
		if (((OS_Tasks[i].ptr) != 0) && (Tick_counts % OS_Tasks[i].periodicity) == 0 )
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
