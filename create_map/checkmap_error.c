/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checkmap_error.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aghergut <aghergut@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/13 15:23:13 by aghergut          #+#    #+#             */
/*   Updated: 2025/01/23 13:26:06 by aghergut         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "create_map.h"

int	free_map(char **map)
{
	int	i;

	if (!map || !(*map))
		return (0);
	i = 0;
	while (map[i] != NULL)
	{
		free(map[i]);
		i++;
	}
	free(map);
	map = NULL;
	return (0);
}

int	checkmap_error(t_data *app)
{
	free_map(app->map);
	free(app->map_arg);
	free(app);
	ft_printf("Check again the name/design of the map!\n");
	exit(EXIT_FAILURE);
	return (0);
}
