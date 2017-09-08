#ifndef _MAP_H
#define _MAP_H

/*!
 Hashmap
 */
struct pair;

typedef struct map
{
    struct pair *_data;
    int _keysize;
    
} map;

///Initialize a map instance
void map_init(map *a, const int aKeySize);

///Delete a map instance
void map_free(map *a);

///Try to get a value given a key. Returns NULL if no value exists.
void *map_get(map *a, void* aKey);

///Insert a new value at the specified key.
void map_insert(map *a, void* aKey, void* aValue);

#endif /* _MAP_H */
