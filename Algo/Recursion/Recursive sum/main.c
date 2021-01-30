#include <stdio.h>
#include <stdlib.h>

int recursive_sum (int* array,int size)
{
  if( size == 1)
  {
      return array[0];
  }
  return (array[0] + recursive_sum( &array[1] , size-1 ) );
}



int main()
{
    int arr[]={10,20,30,40};

    printf("sum is %d\r\n",recursive_sum(arr,4) );
    return 0;
}
