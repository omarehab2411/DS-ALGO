#include <stdio.h>
#include <stdlib.h>

int factorial_recursion (int number)
{
    /*base case*/
    if( number == 2 )
    {
        return 2;
    }

    /*recursion case*/
    return (  number * factorial_recursion (number -1 ) );
}

int factorial_iterative (int number)
{
int result = 1;

while(number > 1)
{
    result *= number;
    number --;
}
return result;
}


int main()
{
    printf("Result using iterative method is %d\r\n", factorial_iterative(4) );
    printf("Result using recursion method is %d\r\n", factorial_recursion(4) );
    return 0;
}
