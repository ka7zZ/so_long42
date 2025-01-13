/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builds.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aghergut <aghergut@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/13 15:23:28 by aghergut          #+#    #+#             */
/*   Updated: 2025/01/13 16:35:00 by aghergut         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUILDS_H
# define BUILDS_H

#include "../so_long.h"

// add body in case of food
void	add_body(t_data*app, int x, int y);
// image utils
void    assign_image(t_data *app, void **image, char *addr);
void    deploy_image(t_data *app, void *image, int x, int y);
// deploy on the window
void    deploy_immutable(t_data *app);
void	deploy_items(t_data *app);
// game window
void	game_window(t_data *app);
// hooks
void	game_hooks(t_data *app);
void	start_hooks(t_data *app);
// frees
int		free_game(t_data *app);
void	free_items(t_data *app);

#endif