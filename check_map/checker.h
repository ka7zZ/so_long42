/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aghergut <aghergut@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/13 15:23:19 by aghergut          #+#    #+#             */
/*   Updated: 2025/01/13 16:08:11 by aghergut         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHECKER_H
#   define CHECKER_H

#include "../so_long.h"
#   define BUFFER_SZ 1024

void    checker(t_data *app, char *argv);
void	check_map(t_data *app, char *argv);
void	return_error(t_data *app);
void    free_app(t_data *app);

#endif