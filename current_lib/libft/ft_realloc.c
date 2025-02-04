/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_realloc.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdel-fra <rdel-fra@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/04 16:31:56 by rdel-fra          #+#    #+#             */
/*   Updated: 2025/02/04 16:38:18 by rdel-fra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Includes/libft.h"

void	*my_realloc(void *ptr, size_t new_size)
{
    void *new_ptr;

	if (ptr == NULL)
		return malloc(new_size);
    if (new_size == 0)
    {
        free(ptr);
        return (NULL);
    }
    new_ptr = malloc(new_size);
	if (new_ptr == NULL)
		return NULL;
	ft_memcpy(new_ptr, ptr, new_size);
	free(ptr);
    return (new_ptr);
}
