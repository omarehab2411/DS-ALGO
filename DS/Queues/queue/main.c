#include <stdio.h>
#include <stdlib.h>
#include "queue.h"


int main()
{
    QUEUE* instance=queue_create();
    for(int i=0;i<2;i++)
    {
      queue_enqueue(instance,i);
    }

     int temp=queue_dequeue(instance);
     printf("%d ",temp);
     temp=queue_dequeue(instance);
     printf("%d ",temp);

     for(int i=2;i<4;i++)
    {
      queue_enqueue(instance,i);
    }

      temp=queue_dequeue(instance);
     printf("%d ",temp);
     temp=queue_dequeue(instance);
     printf("%d ",temp);

  return 0;
}
