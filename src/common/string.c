#include "string.h"

#include <stdlib.h>

int cstring_length(char *a)
{
    int length = 0;
    
    for(;*a != '\0'; a++,length++);
 
    return length;
    
}

char *cstring_concat(char *a, char *b)
{
    int aSize = cstring_length(a);
    int bSize = cstring_length(b);
    
    char *output = malloc(sizeof(char) * (aSize + bSize));
    
    if (output)
    {
        char *iter = output;
        int i;
        
        for (i = 0; i < aSize; i++, a++, iter++)
            *iter = *a;
        
        for (i = 0; i < bSize; i++, b++, iter++)
            *iter = *b;
        
        *iter = '\0';
        
    }
    
    return output;
    
}
