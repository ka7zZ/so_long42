/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   return_error.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aghergut <aghergut@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/13 15:23:13 by aghergut          #+#    #+#             */
/*   Updated: 2025/01/13 15:23:15 by aghergut         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

void    free_app(t_data *app)
{
    int i;

	if (!app->map || !(*app->map))
        return;
    i = 0;
    while(app->map[i] != NULL)
    {
        free(app->map[i]);
        i++;
    }
    free(app->map);
    app->map = NULL; 
}

void return_error(t_data *app)
{
	free_app(app);
	ft_printf("Wrong format of the map!\n");
	exit(EXIT_FAILURE);
}