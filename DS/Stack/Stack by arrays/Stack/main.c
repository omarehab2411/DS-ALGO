#include <stdio.h>
#include <stdlib.h>
#include "stack.h"

int main()
{
    /*create a stack instance*/
    STACK* instance=stack_create();

    /*Push data into the stack*/
    for(int i=0;i<10;i++)
    {
      if(!stack_push(instance,i))
      {
          printf("stack overflow\r\n");
          return 0;
      }

    }

    /*print elements in the stack*/
    while(instance->top != -1)
    {
        int temp=stack_pop(instance);
        printf("%d ",temp);
    }

    return 0;
}
