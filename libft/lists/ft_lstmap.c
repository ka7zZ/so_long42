/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aghergut <aghergut@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/27 13:46:05 by aghergut          #+#    #+#             */
/*   Updated: 2024/10/18 20:55:32 by aghergut         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lists.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*node;
	t_list	*temp;
	char	*f_content;

	if (!lst || !del || !f)
		return (NULL);
	node = NULL;
	while (lst != NULL)
	{
		f_content = (char *)f(lst->content);
		temp = ft_lstnew(f_content);
		if (!temp)
        {
            del(f_content);
            ft_lstclear(&node, del);
			return (NULL);
		}
        if (node == NULL)
			node = temp;
		else
			ft_lstadd_back(&node, temp);
		lst = lst->next;
	}
	ft_lstadd_back(&node, lst);
	return (node);
}
