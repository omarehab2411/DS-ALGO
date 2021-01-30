#include <stdio.h>
#include <stdlib.h>



void InsertionSort (int* array , int size)
{
for(int i=1;i<size;i++)
{
  int temp = array[i];
  int j = i-1;

   /* Move elements of arr[0..i-1], that are
          greater than key, to one position ahead
          of their current position */
    while( array[j] > temp && j>=0 )
    {
        array[j+1] =array[j];
        j--;
    }
    //place it in the gap made
    array[j+1] =temp;
}

}


int main()
{
    int array[] ={6,7,1,3,9,5};
    InsertionSort(array,6);   //TimeComplexity when array is nearly sorted is O(n)

    for(int i=0;i<6;i++)
    {
        printf("Array[%d] = %d \r\n",i,array[i]);
    }

    return 0;
}
