#include "list.h"

//*********************************************************************************************************************
//                                     Functions Implementation
//*********************************************************************************************************************


/*Function to insert a Node at the beginning of the list*/
int List_Insert_Beginning(Node **PtrHead,int item)
{
    /*create a Node dynamically*/
    Node* PtrNode=(Node*)malloc(sizeof(Node));
    if(PtrNode!=NULL)
    {
     /*if Memory allocated*/

    /*update Node with required data*/
    PtrNode->data=item;
    /*Make Node point to the Head as we are inserting a Node at the beginning of the list*/
    PtrNode->next=*PtrHead;
    /*Make Head point to the Node as now the Node is the first Node in the list*/
    *PtrHead=PtrNode;
    /*return 1 which means that Node inserted successfully*/
    return (1);
    }
    else
    /*return 0 which means Node not inserted due to fail to allocate memory for it*/
    return (0);
}




/*function to insert a Node at a certain position in the list*/
int List_Insert_At(Node **PtrHead,int position,int item)
{
/*create a Node ptrs*/
Node* pTemp=*PtrHead;
Node* ptrNode=NULL;

/*determine length of List first*/
int length=List_length(*PtrHead);

if( (position>(length+1)) || (position<1) )
{
    /*if position is out of possible range return error value*/
    return (0);
}

/*if reached here then position is logically correct so continue inserting the Node*/

/*Find first the predecessor of the Node we want to insert at it's position*/
if(position==1)
{
    /*Insert at beginning as the position is equal one*/
    List_Insert_Beginning(PtrHead,item);
}

else
{

for(int i=0;i<position-2;i++)
{
/*update temp ptr with the next pointer the node is pointing to */
pTemp=pTemp->next;
}

/*after finding address of the predecessor node update the pointer of the node we want to insert
to point to next node
*/
/*create the node first*/
ptrNode=(Node*)malloc(sizeof(Node));
/*update the node with the required data*/
ptrNode->data=item;
/*make created node point t the next node*/
ptrNode->next=pTemp->next;
/*make previous node point to the created node*/
pTemp->next=ptrNode;
}
//insertion done correctly
return (1);
}


/*Function to delete a node at a certain position*/
int List_Delete_At(Node **PtrHead,int position)
{
   /*pointer to head of the list*/
    Node* Head=*PtrHead;
    Node* CurrentNode=NULL;

  /*get length of the list*/
  int list_length=List_length(*PtrHead);

  if(position>list_length || position<1)
  {
   /*if position of node is not logical then return an error */
      return (0);
  }

  if(position==1)
  {
      /*if deleting the first Node make Head pointer point to the next node then delete that node*/
      CurrentNode=*PtrHead;
      //we did this here because we need to edit the actual header pointer itself that refrecne the list*/
      *PtrHead=CurrentNode->next;
      free(CurrentNode);
  }
  else
  {
     /*find predecessor of the Node we want to delete*/
     for(int i=0;i<position-2;i++)
     {
         Head=Head->next;
     }
     CurrentNode=Head->next;
     Head->next=CurrentNode->next;
     free(CurrentNode);
  }
return(1);
}


/*Function to Reverse a linked list*/
void List_Reverse(Node **PtrHead)
{
/*declare some temp variables to be used in the implementation*/
Node  *previous,*current,*next;
previous=NULL;
next=NULL;
current=*PtrHead;

/*traverse the list*/
while(current!=NULL)
{
  /*save ptr to next node in a temp variable*/
  next=current->next;
  /*make node point to previous node*/
  current->next=previous;
  /*update previous ptr to point to current node*/
  previous=current;
  /*update current ptr to point to next node*/
  current=next;
}
/*update Head to point to first element of the list after reversing*/
*PtrHead=previous;
}






/*function to return length of a list*/
int List_length(Node* ptrNode)
{int counter=0;
while(ptrNode!=NULL)
{
counter++;
ptrNode=ptrNode->next;
}
return counter;
}






/*Function to Print items in the List*/
void List_Print(Node* ptrNode)
{
/*As long as we didn't reach end of the list print the item*/
while(ptrNode!=NULL)
{
    printf("%d ",ptrNode->data);
    ptrNode=ptrNode->next;
}
printf("\r\n");
}


