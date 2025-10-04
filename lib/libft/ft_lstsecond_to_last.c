/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstsecond_to_last.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdel-fra <rdel-fra@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/18 12:11:49 by rdel-fra          #+#    #+#             */
/*   Updated: 2024/12/18 15:54:47 by rdel-fra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Includes/libft.h"

t_list	*ft_lstsecond_to_last(t_list *lst)
{
	t_list	*nav;
	int		i;

	nav = lst;
	i = ft_lstsize(lst);
	while (i > 2)
	{
		nav = (*nav).next;
		i--;
	}
	return (nav);
}
