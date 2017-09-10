#include "map.h"

#include "uthash.h"

typedef struct pair
{
    void *key;
    void *value;
    
    UT_hash_handle hh;
    
} pair;

void map_init(map *a, const int aKeySize)
{
    if (!a) return;
    
    a->_data = NULL;
    a->_keysize = aKeySize;
    
}

void *map_get(map *aMap, void* aKey)
{
    if (aMap && aKey)
    {
        pair *p = NULL;
    
        HASH_FIND(hh, aMap->_data, &aKey, sizeof(void *), p);
    
        if (p)
            return p->value;
    }
    
    return NULL;
}

void map_insert(map *aMap, void* aKey, void* aValue)
{
    if (!aMap || !aKey || !aValue) return;
    
    pair *newPair = (pair*)malloc(sizeof(pair));
    newPair->key   = aKey;
    newPair->value = aValue;
    
    HASH_ADD(hh, aMap->_data, key, sizeof(void *), newPair);
}
