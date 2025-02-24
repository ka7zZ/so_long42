/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_buildmap_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aghergut <aghergut@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/13 15:23:07 by aghergut          #+#    #+#             */
/*   Updated: 2025/02/22 14:24:41 by aghergut         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../../includes/so_long_bonus.h"

static int	ft_checksnake(t_data *app)
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

static int	ft_checkexit(t_data *app)
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

int	ft_buildmap(t_data *app, char *argv)
{
	if (!ft_checkmap(app, argv) || !ft_checkexit(app) || !ft_checksnake(app))
	{
		ft_errormap(app);
		return (0);
	}
	return (1);
}
