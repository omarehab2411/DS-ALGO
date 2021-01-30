#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

int8_t BinarySearch(uint8_t* array,uint8_t size,uint8_t item);

int main()
{
    /*driver Code*/
    /*Note the array should be sorted for binary search to work successfully*/
    uint8_t array[10]={0,1,2,3,4,5,6,7,8,9};
    int result =BinarySearch(array,10,4);
    printf("Number is:%d\r\n",result);
    result =BinarySearch(array,10,100);
    printf("Number is:%d\r\n",result);
    return 0;
}

int8_t BinarySearch(uint8_t* array,uint8_t size,uint8_t item)
{

/*define two variables High and Low to go through the array those variables
 defines the bounds of the current chunk we are searching in at the moment.
 those variables will be updated with every guess we make during each iteration.
*/
 uint8_t High =size-1;
 uint8_t Low  =0;


/*define variable to hold the guessed item
that we will compare it to the actual item we are searching for*/
uint8_t Medium=(High+Low)/2;
/*variable to hold guessed item in the list*/
uint8_t guessedItem=array[Medium];


 /*as long as Low is lower of equal High go through the array
 and search for the item we want to look for
 */
 while(Low<=High)
 {
  if(guessedItem==item)
  {   /*the guessed item is the item we are searching for so return it's index*/
      return Medium;
  }
  else if(guessedItem<item)
  {   /*guessed item is too lower than the item we are searching for so update the chunk we
      will search in by updating Low index to be higher than this guessed number by one element
      */
      Low=Medium+1;
  }
  else
  {    /*guessed item is Higher than the item we are searching for so update the chunk we
       will search in by updating High index to be lower than this guessed number by one element
      */
      High=Medium-1;
  }
    Medium=(High+Low)/2;
    guessedItem=array[Medium];
}
 /*if reached here this means item do not exist in the list so return a value that means it is empty*/
 return (-1);
}
