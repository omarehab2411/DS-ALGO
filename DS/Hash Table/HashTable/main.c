#include "hashTable.h"

int main()
{
    hashTable* ht =hashTable_Create();

    hashTable_set(ht,"omar","2");
    hashTable_set(ht,"ehab","100");
    hashTable_set(ht,"ahmed","4");
    uint8_t* val = hashTable_get(ht,"ehab");
    printf("value is %s\r\n",val);

    return 0;
}
