#ifndef __HASHTABLE__H
#define __HASHTABLE__H

#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <string.h>

#define TableSize (10)

typedef struct
{
    uint8_t* key;
    uint8_t* value;
   struct hashTable_entry* nextEntry;
}hashTable_entry;

typedef struct
{
  hashTable_entry** entries;
}hashTable;



hashTable* hashTable_Create(void);
void hashTable_set(hashTable* table,uint8_t* key,uint8_t* value);
uint8_t* hashTable_get(hashTable* table,uint8_t* key);


#endif // __HASHTABLE__H
