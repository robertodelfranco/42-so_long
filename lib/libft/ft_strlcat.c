/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdel-fra <rdel-fra@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/10 12:41:46 by rdel-fra          #+#    #+#             */
/*   Updated: 2024/11/29 17:21:08 by rdel-fra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Includes/libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	d;
	size_t	s;
	size_t	i;

	d = 0;
	s = 0;
	while (dst[d])
		d++;
	while (src[s])
		s++;
	if (size <= d)
		return (size + s);
	i = 0;
	while (src[i] && d + i < size - 1)
	{
		dst[d + i] = src[i];
		i++;
	}
	dst[d + i] = '\0';
	return (d + s);
}

// unsigned int main()
// {
// 	char	*dest;

// 	dest = (char *)malloc(sizeof(*dest) * 15);
// 	memset(dest, 'r', 14);
// 	printf("%zu\n", ft_strlcat(dest, "lorem ipsum dolor sit amet", 1));
// 	write(1, dest, 15);
// }