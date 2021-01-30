#include "stack.h"

/*Function to create the stack dynamically*/
STACK* stack_create(void)
{
    /*dynamically allocate the stack*/
    STACK* temp=(STACK*)malloc(sizeof(STACK));
    /*Initialize top of stack*/
    temp->top=NULL;
    temp->nodeCount=0;
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

 /*create a new node at the top of the stack and fill it with the data we want*/
 List_Insert_Beginning( &(StackInstance->top),data );
 StackInstance->nodeCount++;

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
  tempData=StackInstance->top->data;
  /*delete Node that we want to pop out of stack we will always pop the node at the beginning*/
  List_Delete_At(&(StackInstance->top),1);
  StackInstance->nodeCount--;
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
  if(StackInstance->nodeCount==0)
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

if(StackInstance->nodeCount >= stackSize)
{
/*stack is full*/
return (1);
}
else
{
    return (0);
}

}

