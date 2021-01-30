#include "BST.h"


BSTNode* BST_Create(void)
{
/*Create Root Node of the tree dynamically*/
BSTNode* Root =(BSTNode*) malloc( sizeof(BSTNode*) );
Root = NULL;
return Root;
}


void BST_Insert(BSTNode** pRoot ,uint8_t data)
{
if( *pRoot == NULL)
{
    *pRoot = (BSTNode*) malloc( sizeof(BSTNode) );
    (*pRoot)->data  = data;
    (*pRoot)->left  = NULL;
    (*pRoot)->rigth = NULL;
}
 else if((*pRoot)->data >= data)
   {
       /*Data is smaller or equal then insert to the left*/
        BST_Insert( & ( (*pRoot)->left ) , data );
   }
   else if ( (*pRoot)->data < data )
   {
       /*if data we want to insert is larger then go to right path*/
       BST_Insert( & ( (*pRoot)->rigth ) , data );
   }

}


BSTNode* BST_Search( BSTNode** pRoot , uint8_t data)
{

if( (*pRoot) == NULL)
{

    return (*pRoot);
}

if( (*pRoot)->data == data )
{

    return *pRoot;
}
else if( (*pRoot)->data > data )
{

  return  BST_Search( &(*pRoot)->left ,data );
}
else
{

  return   BST_Search( &(*pRoot)->rigth,data );
}


}


void BST_Remove(BSTNode** pRoot,uint8_t data)
{



}
