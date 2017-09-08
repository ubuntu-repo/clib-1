#include "debug.h"
#include "string.h"
#include "vector.h"

void testDebug()
{
    char *a = "What";
    char *b = " is";
    char *c = " up";
    char *o = cstring_concat(a,b);
    o = cstring_concat(o,c);
    
    debug_log("%s",o);
    debug_error("%i",&o);
    
}

void testVector()
{
    int i, s;
    vector a;
    vector_init(&a);
    
    for (i = 0, s = 5; i < s; i++)
        vector_pushback(&a, i);
    
    for (i = 0, s = a.count; i < s; i++)
        debug_log("%i",vector_get(&a,i));
    
    for (i = 0, s = a.count; i < s; i++)
        vector_remove(&a, 0);
    
    for (i = 0, s = a.count; i < s; i++)
        debug_log("%i",vector_get(&a,i));
    
    vector_free(&a);
    
}

int main(int argc, const char * argv[])
{
    testDebug();
    
    testVector();
    
    debug_log("おはようございます");
    
    return 0;
    
}
