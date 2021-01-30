#include "BST.h"

int main()
{

  BSTNode* ROOT  = BST_Create();

  BST_Insert(&ROOT,10);

  BST_Insert(&ROOT,20);

  BST_Insert(&ROOT,5);

  BST_Insert(&ROOT,6);

  BST_Insert(&ROOT,200);

  BSTNode* node = BST_Search(&ROOT,6);

  if(node != NULL)
  printf("Value is %d\r\n",node->data);
  else
  printf("NULL\r\n");

    return 0;
}
