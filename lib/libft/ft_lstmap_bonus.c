/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdel-fra <rdel-fra@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/17 17:02:23 by rdel-fra          #+#    #+#             */
/*   Updated: 2024/12/10 17:41:07 by rdel-fra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Includes/libft.h"

t_list	*ft_lstmap(t_list *lst, int (*f)(int), void (*del)(int))
{
	t_list	*new_node;
	t_list	*new_nodelist;

	new_nodelist = NULL;
	while (lst != NULL)
	{
		new_node = ft_lstnew(f((*lst).nb));
		if (!new_node)
		{
			del((*lst).nb);
			ft_lstclear(&new_node, del);
			return (NULL);
		}
		ft_lstadd_back(&new_nodelist, new_node);
		lst = (*lst).next;
	}
	return (new_nodelist);
}
