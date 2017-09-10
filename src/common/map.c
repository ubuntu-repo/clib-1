#include "map.h"

#include "uthash.h"

typedef struct pair
{
    void *key;
    void *value;
    
    UT_hash_table _maphandle;
    
} pair;

void map_init(map *a, const int aKeySize)
{
    if (!a) return;
    
    a->_data = NULL;
    a->_keysize = aKeySize;
    
}

void *map_get(map *a, void* aKey)
{
    if (!a || !aKey) return 0;
    
    //pair *keyvalue = 0;
    void *ptr;
    
    //HASH_FIND(_maphandle, a->_data, &aKey, a->_keysize, ptr);  /* s: output pointer */
    return ptr;
    
    //HASH_FIND(a->_data)
    
}

void map_insert(map *a, void* aKey, void* aValue)
{
    if (!a || !aKey || !aValue) return;
    
}
