#include <stdio.h>
#include <stdlib.h>

#include "stack.h"

int main()
{
   /*create a stack instance*/
   STACK* instance=stack_create();
   stack_push(instance,10);
   stack_push(instance,20);
   stack_push(instance,30);

   while(instance->nodeCount!=0)
   {
       int temp=stack_pop(instance);
       printf("%d ",temp);
   }

   /*second stack instance*/
   STACK* instance2=stack_create();
   stack_push(instance2,1000);
   stack_push(instance2,2020);
   stack_push(instance2,30909);
 while(instance2->nodeCount!=0)
   {
       int temp=stack_pop(instance2);
       printf("%d ",temp);
   }
    return 0;
}
