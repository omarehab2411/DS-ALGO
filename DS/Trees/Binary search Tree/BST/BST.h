#ifndef __BST__H
#define __BST__H

#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

typedef struct
{
uint8_t data;
struct BSTNode* rigth;
struct BSTNode* left;
}BSTNode;



BSTNode* BST_Create(void);
void BST_Insert(BSTNode** pRoot ,uint8_t data);
BSTNode* BST_Search(BSTNode** pRoot , uint8_t data);
void BST_Remove(BSTNode** pRoot,uint8_t data);


#endif // __BST__H
