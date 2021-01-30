#include <stdio.h>
#include <stdlib.h>



int fibonacci_iterative (int index)
{
    long arr [2] ={0,1};
    long value =0;

    if(index <2)
    {
        return arr[index];
    }

    for(int i=2 ; i < (index+1) ;i++)
    {
        value   = arr[0] + arr[1] ;
        arr[0]  = arr [1] ;
        arr[1]  = value;
    }
    return value ;
}


int fibonacci_recursive (int index)
{
   if( index <2 )
   {
       return index;
   }

   return fibonacci_recursive(index-1) + fibonacci_recursive(index-2);

}

int main()
{
    printf("value is using iterative method %d\r\n", fibonacci_iterative(48) );   //time complexity 0(n)
      printf("value is using recursion method %d\r\n", fibonacci_recursive(48) ); //time complexity 0(2^n)
    return 0;
}
