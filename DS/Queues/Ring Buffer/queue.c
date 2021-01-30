#include "queue.h"

/*Function to create a queue instance*/
QUEUE* queue_create(void)
{ /*create a queue dynamically*/
  QUEUE* temp=(QUEUE*)malloc(sizeof(QUEUE));
  /*INIT head and tail of this queue to 0*/
  temp->Head=0;
  temp->Tail=0;
  /*return queue instance Handler*/
  return temp;
}

/*Function to insert data into a queue*/
int queue_enqueue(QUEUE* queueInstance,int data)
{
 /*In Ring buffer we use last element as an flag to wrap the pointers*/
  int next=queueInstance->Tail+1;

  /*if next element to write into is last element wrap the ptr back to 0*/
  if(next>=queueSize)
  {   /*wrap the tail back to start of the queue*/
      next=0;
  }

/*before pushing data we should check if queue is full*/
if( next != queueInstance->Head )
{
 /*If queue is not full then we are allowed to push data into the queue*/

   /*insert the element*/
  queueInstance->queueArray[queueInstance->Tail]=data;

   /*increment the tail to point to index we will insert element into*/
   queueInstance->Tail=next;

  /*element inserted successfully*/
  return (1);
}
else
{
    /*queue is full in ring buffer it is your choice to discard or overwrite the data already written
      in this implementation i decided to overwrite
    */

     /*insert the element*/
   queueInstance->queueArray[queueInstance->Tail]=data;

   /*increment the tail to point to index we will insert element into*/
   queueInstance->Tail=next;
    return (0);
}

}

/*function to pop elements out of a queue*/
int queue_dequeue(QUEUE* queueInstance)
{
/*temp variable to hold data*/
int data=0;
int next=0;

/*first we should check if the queue is not empty*/
if( queueInstance->Head != queueInstance->Tail )
{
  /*If queue is not empty then we are allowed to pop elements out of a queue*/
    next=queueInstance->Head+1;

    /*if next element to be poped out is equal to size of queue then we need to wrap the ptr*/
    if(next>=queueSize)
    {
      /*wrap the pointer back*/
       next=0;
    }

    /*save data in a temp variable*/
    data=queueInstance->queueArray[queueInstance->Head];
    queueInstance->Head = next;
    return (data);
}
else
{
    /*if queue is empty then error occurred (underflow)*/
    return (NULL);
}

}
