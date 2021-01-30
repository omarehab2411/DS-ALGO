#include "hashTable.h"


//*****************************************************************************
//                           Static functions
//*****************************************************************************

static unsigned int hash(const char *key) {
    unsigned long int value = 0;
    unsigned int i = 0;
    unsigned int key_len = strlen(key);

    // do several rounds of multiplication
    for (; i < key_len; ++i) {
        value = value * 37 + key[i];
    }

    // make sure value is 0 <= value < TABLE_SIZE
    value = value % TableSize;

    return value;
}


static hashTable_entry* hashTable_createEntry (uint8_t* key,uint8_t* value)
{
  hashTable_entry* entry =(hashTable_entry*) malloc(sizeof(hashTable_entry));

  entry->key   = malloc(strlen(key) + 1);
  entry->value = malloc(strlen(value) + 1);

  strcpy(entry->key,key);
  strcpy(entry->value,value);

  entry->nextEntry =NULL;

  return entry;
}
//*****************************************************************************




//************************************************************************
//                          Public functions
//************************************************************************
hashTable* hashTable_Create(void)
{
  //create hashTable
  hashTable* htable =(hashTable*)malloc(sizeof(hashTable));

  //create pointers to slot entries of the table
  htable->entries =(hashTable_entry*)malloc(sizeof(hashTable_entry*)*TableSize) ;

  //init table slots with NULL ptr
  for(int i=0;i<TableSize;i++)
  {
       htable->entries[i] =NULL;
  }

  return htable;
}


void hashTable_set(hashTable* table,uint8_t* key,uint8_t* value)
{
uint32_t slot =hash(key);

 hashTable_entry *currentEntry =table->entries[slot];
 hashTable_entry *PrevEntry    =NULL;

if( currentEntry == NULL)
{
    /*slot is empty so allocate entry and add it to this slot*/
    table->entries[slot] =hashTable_createEntry(key,value);
    return;
}

while(currentEntry != NULL)
{
    if(strcmp(currentEntry->key,key)==0)
    {
        /*same key so update this entry*/
         free(currentEntry->value);
         currentEntry->value = malloc(strlen(value) + 1);
         strcpy(currentEntry->value, value);
        return ;
    }
    /*go to next entry in  this slot*/
    PrevEntry =currentEntry;
    currentEntry =PrevEntry->nextEntry;
}
/*if code gets here this means there is no matched key so add a new entry in the slot linked list*/
PrevEntry->nextEntry =hashTable_createEntry(key,value);
}


uint8_t* hashTable_get(hashTable* table,uint8_t* key)
{
uint32_t slot = hash(key);

hashTable_entry *currentEntry =table->entries[slot];
hashTable_entry *PrevEntry    =NULL;

if(currentEntry == NULL )
{
    return NULL;
}
else
{
    while(currentEntry != NULL)
    {
        if(strcmp(currentEntry->key,key)==0)
        {
            /*key matches so return entry*/
            return currentEntry->value;
        }
        /*key doesn't match so iterate through linked list*/
        PrevEntry =currentEntry;
        currentEntry =PrevEntry->nextEntry;
    }
    /*no matched key*/
    return NULL;
}


}
//*******************************************************************************
