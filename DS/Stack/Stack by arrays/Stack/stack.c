#include "stack.h"

/*Function to create the stack dynamically*/
STACK* stack_create(void)
{
    /*dynamically allocate the stack*/
    STACK* temp=(STACK*)malloc(sizeof(STACK));
    if(temp!=NULL)
    {
    /*initialize top of stack with -1*/
    temp->top=-1;
    }
    /*return a handler of this stack instance*/
    return(temp);
}

/*Function that pushes data into stack*/
int  stack_push(STACK* StackInstance,int data)
{
/*Before pushing data we should check if stack is not full */
if( !stack_IsFull(StackInstance) )
{
 /* if stack is not full we are allowed to push data into the stack */

 /*Increment first the ptr that point to the top of stack*/
 StackInstance->top++;
 /*add the element we want to push */
 StackInstance->stackArray[ StackInstance->top]=data;

 /*return 1 that means item pushed into the stack*/
 return (1);
}
else
{
/*stack overflow we cant push data so return error value*/
return (0);
}
}


/*Function that is used to pop element from the stack*/
int  stack_pop (STACK* StackInstance)
{
 /*temp variable to hold popped item*/
 int tempData=0;

/*Check first if stack is not empty*/
if( !stack_IsEmpty(StackInstance) )
{
  /*stack is not empty so we can pop elements from it*/

  /*save the item we will pop into a temp variable*/
  tempData=StackInstance->stackArray[StackInstance->top];
  /*decrement the top of the stack by one to pop the item*/
  StackInstance->top--;
  /*return the poped item*/
  return tempData;
}
else
{
 /*stack is empty so underflow case*/
 return NULL;
}

}

/*Function to check if stack is empty*/
int  stack_IsEmpty(STACK* StackInstance)
{
  if(StackInstance->top==-1)
  {
      /*this means that the stack is empty*/
      return (1);
  }
  else
  {
      return (0);
  }
}


/*function to check if stack is full*/
int  stack_IsFull (STACK* StackInstance)
{

if(StackInstance->top >= stackSize)
{
/*stack is full*/
return (1);
}
else
{
    return (0);
}

}

