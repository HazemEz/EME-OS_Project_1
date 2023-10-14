/*
 * OS_Private.h
 *
 *  Created on: Oct 12, 2023
 *      Author: Administrator
 */

#ifndef OS_PRIVATE_H_
#define OS_PRIVATE_H_

#include "main.h"

typedef struct{
	uint16_t periodicity;
	void (*ptr) (void);
}Task;




#endif /* OS_PRIVATE_H_ */
