#include "mapping.h"

void    free_map(char ***map)
{
   int i;

    if (!map || !*map)
        return;
    i = 0;
    while((*map)[i] != '\0')
    {
        free((*map)[i]);
        i++;
    }
    free(*map);
    *map = NULL; 
}
