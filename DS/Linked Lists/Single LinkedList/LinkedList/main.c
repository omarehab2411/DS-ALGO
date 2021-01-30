#include <stdio.h>
#include <stdlib.h>
#include "list.h"


int main()
{
   /*Pointer to Head of the list*/
    Node* Head=NULL;
    printf("List length is:%d\r\n",List_length(Head));
    List_Insert_Beginning(&Head,5);
    List_Insert_Beginning(&Head,4);
    List_Insert_Beginning(&Head,3);
    List_Insert_Beginning(&Head,2);
    List_Insert_Beginning(&Head,1);
    List_Insert_At(&Head,6,6);
    printf("List length is:%d\r\n",List_length(Head));
    List_Print(Head);
    List_Reverse(&Head);
    List_Print(Head);
}
