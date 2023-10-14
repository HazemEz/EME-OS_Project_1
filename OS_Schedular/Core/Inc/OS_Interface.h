/*
 * OS_Interface.h
 *
 *  Created on: Oct 12, 2023
 *      Author: Administrator
 */

#ifndef OS_INTERFACE_H_
#define OS_INTERFACE_H_

#include "../Inc/main.h"

void OS_CreateTask (uint8_t priority ,uint16_t periodicity, void (*Fptr) (void));

void OS_Scheduler (void);

void OS_Start (void);

#endif /* OS_INTERFACE_H_ */
