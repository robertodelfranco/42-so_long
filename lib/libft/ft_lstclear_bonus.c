/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdel-fra <rdel-fra@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/17 15:50:34 by rdel-fra          #+#    #+#             */
/*   Updated: 2024/12/19 15:15:27 by rdel-fra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Includes/libft.h"

void	ft_lstclear(t_list **lst, void (*del)(int))
{
	t_list	*nav;

	while (*lst != NULL)
	{
		nav = (*lst)->next;
		ft_lstdelone(*lst, del);
		*lst = nav;
	}
}
