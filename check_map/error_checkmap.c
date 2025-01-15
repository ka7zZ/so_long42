/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_checkmap.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aghergut <aghergut@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/13 15:23:13 by aghergut          #+#    #+#             */
/*   Updated: 2025/01/15 09:29:54 by aghergut         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

void    free_map(char **map)
{
    int i;

	if (!map || !(*map))
        return;
    i = 0;
    while(map[i] != NULL)
    {
        free(map[i]);
        i++;
    }
    free(map);
    map = NULL; 
}

void error_checkmap(t_data *app)
{
	free_map(app->map);
    free(app);
	ft_printf("Wrong format of the map!\n");
	exit(EXIT_FAILURE);
}