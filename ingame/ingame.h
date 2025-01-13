/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ingame.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aghergut <aghergut@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/13 15:22:34 by aghergut          #+#    #+#             */
/*   Updated: 2025/01/13 18:28:12 by aghergut         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INGAME_H
#   define INGAME_H

#include "../so_long.h"

void	show_moves(t_data *app);
void	moving_around(t_data *app, int new_x, int new_y);
void	check_gate(t_data *app, int new_x, int new_y);
int		check_wall(t_data *app, int new_x, int new_y);
int		check_food(t_data *app, int new_x, int new_y);
int		check_body(t_data *app, int new_x, int new_y);
int		check_enemy(t_data *app, int new_x, int new_y);

#endif