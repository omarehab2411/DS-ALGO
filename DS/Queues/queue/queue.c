#include "queue.h"

/*Function to create a queue instance*/
QUEUE* queue_create(void)
{ /*create a queue dynamically*/
  QUEUE* temp=(QUEUE*)malloc(sizeof(QUEUE));
  /*INIT head and tail of this queue to -1*/
  temp->Head=-1;
  temp->Tail=-1;
  /*return queue instance Handler*/
  return temp;
}

/*Function to insert data into a queue*/
int queue_enqueue(QUEUE* queueInstance,int data)
{
/*before pushing data we should check if queue is full*/
if(! queue_IsFull(queueInstance) )
{
 /*If queue is not full then we are allowed to push data into the queue*/

 if( queue_IsEMpty(queueInstance) )
 {
  /*when inserting first element*/
   queueInstance->Head=0;
   queueInstance->Tail=0;
 }
 else
 {
   /*increment the tail to point to index we will insert element into*/
   queueInstance->Tail++;
}

  /*insert the element*/
  queueInstance->queueArray[queueInstance->Tail]=data;

  /*element inserted successfully*/
  return (1);
}
else
{
    /*queue is full (overflow) took place return error*/
    return (0);
}

}

/*function to pop elements out of a queue*/
int queue_dequeue(QUEUE* queueInstance)
{
/*temp variable to hold data*/
int data=0;

/*first we should check if the queue is not empty*/
if( !queue_IsEMpty(queueInstance) )
{
  /*If queue is not empty then we are allowed to pop elements out of a queue*/
    /*save data in a temp variable*/
    data=queueInstance->queueArray[queueInstance->Head];
     /*if we are removing the last element in the queue*/
    if( queueInstance->Head == queueSize-1 )
    {
    /*reset the front and rear ptrs which means we reset the queue and it is empty now*/
    queueInstance->Head=-1;
    queueInstance->Tail=-1;
    }
    else
    {
    /*increment the head pointer*/
    queueInstance->Head++;
    }
    /*return data*/
    return (data);
}
else
{
    /*if queue is empty then error occurred (underflow)*/
    return (NULL);
}

}

/*Function to check if a queue is full*/
int queue_IsFull (QUEUE* queueInstance)
{

if( (queueInstance->Tail >= (queueSize-1) ) )
{
    return (1);
}

else
{
    /*queue is not full */
    return (0);
}

}


/*Function to check if a queue is empty*/
int queue_IsEMpty(QUEUE* queueInstance)
{

if( (queueInstance->Head == -1 ) ||  (queueInstance->Head > queueInstance->Tail ) )
{
    return (1);
}

else
{
    /*queue is not empty */
    return (0);
}

}
