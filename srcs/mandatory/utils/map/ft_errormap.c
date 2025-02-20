/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_errormap_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aghergut <aghergut@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/13 15:23:13 by aghergut          #+#    #+#             */
/*   Updated: 2025/02/20 17:53:53 by aghergut         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "../../includes/so_long.h"
# include "../../includes/so_long_bonus.h"

int	ft_freemap(char **map)
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

int	ft_errormap(t_data *app)
{
	ft_freemap(app->map);
	free(app->map_arg);
	free(app);
	ft_putstr_fd("Error!\n", 1);
	exit(EXIT_FAILURE);
	return (0);
}
