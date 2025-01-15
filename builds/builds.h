/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builds.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aghergut <aghergut@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/13 15:23:28 by aghergut          #+#    #+#             */
/*   Updated: 2025/01/15 13:10:20 by aghergut         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUILDS_H
# define BUILDS_H

#include "../so_long.h"

// add body in case of food
int		add_body(t_data*app, int x, int y);
int		dead_head(t_data *app, char type);
// image utils
int		assign_image(t_data *app, void **image, char *addr);
int		deploy_image(t_data *app, void *image, int x, int y);
// deploy on the window
void    deploy_immutable(t_data *app);
void	deploy_items(t_data *app);
void	deploy_gate_anim(t_data *app, int j, int i);
int		gate_loop(t_data *app, int stop);
int		add_enemy_anim(t_data *app, int j, int i);
int		show_exit(t_data *app);
int		enemy_loop(t_data *app);
// game window
int		game_window(t_data *app);
// hooks
int		game_hooks(t_data *app);
int		start_hooks(t_data *app);
// frees
int		free_game(t_data *app);
int		free_items(t_data *app);
//snake
int		dead_head(t_data *app, char type);
int		change_skin(t_data *app);


#endif