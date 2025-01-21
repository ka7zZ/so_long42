/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   anime_loops.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aghergut <aghergut@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/15 10:04:57 by aghergut          #+#    #+#             */
/*   Updated: 2025/01/21 17:34:59 by aghergut         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "builds.h"

int	show_exit(t_data *app)
{
	t_list      *ptr;
	t_seg	    *buf;
	static int  n = 0;
	int			temp;
	
	if (n == 9)
		n = 8;
	ptr = app->items.gate;
	n++;
	temp = n;
	while (ptr && temp--)
	{
		buf = ptr->content;
		ptr = ptr->next;
	}
	if (buf->img)
		deploy_image(app, buf->img, buf->x, buf->y);
	return (0);
}
