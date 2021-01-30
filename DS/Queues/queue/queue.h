#ifndef __QUEUE__H
#define __QUEUE__H

#include <stdio.h>
#include <stdlib.h>

#define queueSize (2)
typedef struct
{
 int Head;
 int Tail;
 int queueArray[queueSize];
}QUEUE;



//****************************************************************************************************
//                                     Functions Prototypes
//****************************************************************************************************
QUEUE* queue_create(void);
int queue_enqueue(QUEUE* queueInstance,int data);
int queue_dequeue(QUEUE* queueInstance);
int queue_IsFull (QUEUE* queueInstance);
int queue_IsEMpty(QUEUE* queueInstance);
//****************************************************************************************************
#endif // __QUEUE__H
