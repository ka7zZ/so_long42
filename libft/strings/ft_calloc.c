/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aghergut <aghergut@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/10 16:34:13 by aghergut          #+#    #+#             */
/*   Updated: 2024/10/18 13:26:56 by aghergut         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "strings.h"

void	*ft_calloc(size_t n, size_t size)
{
	void	*str;

	str = malloc(n * size);
	if (str)
	{
		ft_bzero(str, n * size);
		return (str);
	}
	return (0);
}
