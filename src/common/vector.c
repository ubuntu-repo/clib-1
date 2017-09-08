#include "vector.h"

#include "debug.h"

#include <stdio.h>
#include <stdlib.h>

static const int c_InitialVectorCapacity = 4;

static void vector_resize(vector *a, int capacity)
{
    void **data = realloc(a->data, sizeof(void *) * capacity);
    
    if (data)
    {
        a->data = data;
        a->_capacity = capacity;
        
    }
    
}

void vector_init(vector *a)
{
    a->_capacity = c_InitialVectorCapacity;
    a->count = 0;
    a->data = malloc(sizeof(void *) * a->_capacity);
    
}

void vector_free(vector *a)
{
    free(a->data);
    
}

void vector_pushback(vector *a, void *item)
{
    if (a->_capacity == a->count)
        vector_resize(a, a->_capacity * 2);
    
    a->data[a->count++] = item;
    
}

void vector_set(vector *a, int index, void *item)
{
    if (index >= 0 && index < a->count)
        a->data[index] = item;

}

void *vector_get(vector *a, const int index)
{
    if (index >= 0 && index < a->count)
        return a->data[index];

    return NULL;

}

void vector_remove(vector *a, int index)
{
    if (index >= 0 && index < a->count)
    {
        
        a->data[index] = NULL;
        
        for (int i = index; i < a->count - 1; i++)
        {
            a->data[i] = a->data[i + 1];
            a->data[i + 1] = NULL;
    
        }
    
        a->count--;
    
        if (a->count > 0 && a->count == a->_capacity / 4)
            vector_resize(a, a->_capacity / 2);
        
    }
    
}
