#include "checkers.h"

static void    free_map(char ***map)
{
   int i;

    if (!map || !*map)
        return;
    i = 0;
    while((*map)[i] != NULL)
    {
        free((*map)[i]);
        i++;
    }
    free(*map);
    *map = NULL; 
}
void return_error(char	***map)
{
	free_map(map);
	ft_printf("Wrong format of the map!\n");
	exit(EXIT_FAILURE);
}