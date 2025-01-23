/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_map.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aghergut <aghergut@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/13 15:23:07 by aghergut          #+#    #+#             */
/*   Updated: 2025/01/23 13:35:13 by aghergut         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "create_map.h"

static int	check_snake(t_data *app)
{
	int	i;
	int	j;
	int	snake;

	i = 0;
	snake = 0;
	while (app->map[++i] != NULL)
	{
		j = 0;
		while (app->map[i][++j] != '\0')
		{
			if (app->map[i][j] == 'P')
				snake++;
		}
	}
	if (snake != 1)
		return (0);
	return (1);
}

static int	check_exit(t_data *app)
{
	int	i;
	int	j;
	int	gate;

	i = 0;
	gate = 0;
	while (app->map[++i] != NULL)
	{
		j = 0;
		while (app->map[i][++j] != '\0')
		{
			if (app->map[i][j] == 'E')
				gate++;
		}
	}
	if (gate != 1)
		return (0);
	return (1);
}

int	create_map(t_data *app, char *argv)
{
	if (!check_map(app, argv) || !check_exit(app) || !check_snake(app))
	{
		checkmap_error(app);
		return (0);
	}
	return (1);
}
