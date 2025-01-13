/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aghergut <aghergut@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/13 15:23:07 by aghergut          #+#    #+#             */
/*   Updated: 2025/01/13 15:50:56 by aghergut         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

static void	check_snake(t_data *app)
{
	int	i;
	int	j;
	int	s;

	i = 0;
	s = 0;
	while (app->map[++i] != NULL)
	{
		j = 0;
		while (app->map[i][++j] != '\0')
		{
			if (app->map[i][j] == 'P')
				s++;
		}
	}
	if (s != 1)
		return_error(app);	
}

static void	check_exit(t_data *app)
{
	int	i;
	int	j;
	int	s;

	i = 0;
	s = 0;
	while (app->map[++i] != NULL)
	{
		j = 0;
		while (app->map[i][++j] != '\0')
		{
			if (app->map[i][j] == 'E')
				s++;
		}
	}
	if (s != 1)
		return_error(app);			
}

void	checker(t_data *app, char *argv)
{
    check_map(app, argv);
    check_exit(app);
    check_snake(app);
}

/*ERRORS HANDLED
	1. error if there are more than 1 symbol
	2. error if there is not designed enough space for the snake
*/