/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstlast_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdel-fra <rdel-fra@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/17 14:48:39 by rdel-fra          #+#    #+#             */
/*   Updated: 2024/12/10 17:54:17 by rdel-fra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Includes/libft.h"

t_list	*ft_lstlast(t_list *lst)
{
	t_list	*nav;
	int		i;

	nav = lst;
	i = ft_lstsize(lst);
	while (i > 1)
	{
		nav = (*nav).next;
		i--;
	}
	return (nav);
}
