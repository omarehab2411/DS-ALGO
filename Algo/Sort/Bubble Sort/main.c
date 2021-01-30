#include <stdio.h>
#include <stdlib.h>

void bubbleSort (int* array , int size)
{
      for(int i=0;i<size-1;i++)
    {
        for(int j=i;j<size;j++)
        {
            if(array[i]>array[j])
            {
               int temp =array[i];
               array[i]=array[j];
               array[j]=temp;
            }

        }

    }

}


int main()
{
      int array [] ={5,4,8,2,9,1,0,5,6};
      bubbleSort(array,9);  //Time Complexity is of O(n^2)

       for(int i=0;i<9;i++)
    printf("Array[%d] = %d\r\n",i,array[i]);

    return 0;
}
