#ifndef __LIST__H
#define __LIST__H
#include <stdio.h>
#include <stdlib.h>

/*Structure that represents a Node in a linkedList*/
typedef struct
{
int data;
struct Node* next;
}Node;


//*************************************************************************************************************
//                              Prototypes
//*************************************************************************************************************
int List_Insert_Beginning(Node **PtrHead,int item);
int List_Insert_At(Node **PtrHead,int position,int item);
int List_Delete_At(Node **PtrHead,int position);
void List_Reverse  (Node **PtrHead);
int List_length(Node* ptrNode);
void List_Print(Node* ptrNode);
//**************************************************************************************************************

#endif // __LIST__H
