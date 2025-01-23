/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_map.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aghergut <aghergut@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/13 15:23:19 by aghergut          #+#    #+#             */
/*   Updated: 2025/01/23 13:40:46 by aghergut         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CREATE_MAP_H
# define CREATE_MAP_H

# include "../so_long.h"
# define BUFFER_SZ	1024

typedef struct s_data	t_data;
int		check_map(t_data *app, char *argv);
int		create_map(t_data *app, char *argv);
int		checkmap_error(t_data *app);
int		free_map(char **map);

#endif