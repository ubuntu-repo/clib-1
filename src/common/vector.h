#ifndef _VECTOR_H
#define _VECTOR_H

/*!
 Dynamic array
 */
typedef struct vector
{
    void **data;
    int count;
    
    int _capacity;

} vector;


///initializes a vector
void vector_init(vector *);

///Delete a vector instance
void vector_free(vector *);

///Add a new item to the end of the vector
void vector_pushback(vector *, void *);

///Set an item in a vector at an index
void vector_set(vector *, int, void *);

///Get an item from the vector at an index
void *vector_get(vector *, const int);

///Remove an item from the vector
void vector_remove(vector *, int);

#endif /* _VECTOR_H */
