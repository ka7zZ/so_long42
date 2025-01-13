/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dead_body.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aghergut <aghergut@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/13 18:21:00 by aghergut          #+#    #+#             */
/*   Updated: 2025/01/13 18:35:59 by aghergut         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "builds.h"

int    dead_body(t_data *app)
{
    t_list	*ptr;
    t_snake	*buf;
    int     i;

    i = 0;
    ptr = app->snake;
    while (ptr)
    {
        buf = ptr->content;
        mlx_destroy_image(app->mlx, buf->img);
        if (i == 0)
            assign_image(app, &(buf->img), app->path.snake_hdead);
        else
            assign_image(app, &(buf->img), app->path.snake_bdead);
        deploy_image(app, buf->img, buf->x, buf->y);
        i++;
        ptr = ptr->next;
    }
    assign_image(app, &(buf->img), app->path.snake_bdead);
    deploy_image(app, buf->img, buf->x, buf->y);
    return (0);
}
