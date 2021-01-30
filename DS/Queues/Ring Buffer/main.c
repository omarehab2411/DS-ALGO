#include <stdio.h>
#include <stdlib.h>
#include "queue.h"


int main()
{
    QUEUE* instance=queue_create();


    queue_enqueue(instance,1);
    queue_enqueue(instance,2);
    queue_enqueue(instance,3);
    queue_enqueue(instance,4);

    for(int i=0;i<queueSize;i++)
    {
    printf("%d ",instance->queueArray[i]);
    }


  return 0;
}
