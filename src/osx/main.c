#include "debug.h"
#include "string.h"
#include "vector.h"
#include "map.h"
#include "cJSON.h"

void testCString()
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

void testMap()
{
    map a;
    void *b;
    
    map_init(&a, 0);
    
    map_insert(&a, "ThisIsMyKey", "ThisIsMyValue");
    
    b = map_get(&a, "ThisIsMyKey");
    
    if (b)
        debug_log("retreived value: %s", (char *)b);
    else
        debug_log("nope");
}

void testCJSON()
{
    char *data =
    "{"
        "\"name\": \"Jack ('Bee') Nimble\","
        "\"format\": {"
            "\"type\":       \"rect\","
            "\"width\":      1920,"
            "\"height\":     1080,"
            "\"interlace\":  false,"
            "\"frame rate\": 24"
        "}"
    "}";
    
    cJSON *root = cJSON_Parse(data);
    
    if (root)
    {
        cJSON *name_item;
        
        if ((name_item = cJSON_GetObjectItem(root, "name")))
        {
            if (cJSON_IsString(name_item))
            {
                char *name = NULL;
                name = name_item->valuestring;
                debug_log("JSON name: %s", name);
            }
        }
        
        cJSON *format;
        
        if ((format = cJSON_GetObjectItemCaseSensitive(root, "format")))
        {
            cJSON *framerate_item = cJSON_GetObjectItemCaseSensitive(format, "frame rate");
            
            if (cJSON_IsNumber(framerate_item))
            {
                float framerate = 0;
            
                framerate = framerate_item->valuedouble;
                debug_log("JSON framerate: %f", framerate);
            
                cJSON_SetNumberValue(framerate_item, 25);
                framerate = framerate_item->valuedouble;
                debug_log("JSON framerate: %f", framerate);
            }
        }
    }
    
    cJSON_Delete(root);
}

int main(int argc, const char * argv[])
{
    testCString();
    testVector();
    testMap();
    testCJSON();
    
    return 0;
}
