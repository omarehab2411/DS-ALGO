#ifndef __STACK__H
#define __STACK__H
#include <stdio.h>
#include <stdlib.h>


#define stackSize (10)
typedef struct
{
int top;
int stackArray[stackSize];
}STACK;


//************************************************************************************************************************
//                                               Function Prototypes
//************************************************************************************************************************
STACK* stack_create(void);
int  stack_push(STACK* StackInstance,int data);
int  stack_pop (STACK* StackInstance);
int  stack_IsEmpty(STACK* StackInstance);
int  stack_IsFull (STACK* StackInstance);
//*************************************************************************************************************************

#endif // __STACK__H
