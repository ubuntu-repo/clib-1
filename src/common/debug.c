#include "debug.h"
//projectinc
#include "string.h"
//stdinc
#include <stdio.h>
#include <stdarg.h>
#include <stdlib.h>

void debug_log(char *format, ...)
{
    format = cstring_concat("D: ", format);
    format = cstring_concat(format, "\n");
    
    va_list args;
    
    va_start (args, format);
    
    vfprintf( stdout, format, args);
    
    va_end (args);
    
    free(format);

}

void debug_error(char *format, ...)
{
    format = cstring_concat("E: ", format);
    format = cstring_concat(format, "\n");
    
    va_list args;
    
    va_start (args, format);
    
    vfprintf( stderr, format, args);
    
    va_end (args);
    
    free(format);

}
