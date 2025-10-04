/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdel-fra <rdel-fra@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/11 10:42:27 by rdel-fra          #+#    #+#             */
/*   Updated: 2024/11/29 17:21:08 by rdel-fra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Includes/libft.h"

static char	*ft_populate(char *ptr, unsigned int nb, int len, int sign);
static int	ft_allocate(int nb);

char	*ft_itoa(int n)
{
	unsigned int	nb;
	char			*ptr;
	int				sign;
	int				len;

	sign = 1;
	if (n < 0)
		sign = sign *(-1);
	nb = n * sign;
	len = ft_allocate(nb);
	if (sign < 0)
		ptr = (char *)malloc((len + 2) * sizeof(char));
	else
		ptr = (char *)malloc((len + 1) * sizeof(char));
	if (!ptr)
		return (NULL);
	ptr = ft_populate(ptr, nb, len, sign);
	return (ptr);
}

static int	ft_allocate(int nb)
{
	int	len;

	len = 0;
	if (nb == 0)
		return (++len);
	while (nb != 0)
	{
		nb = nb / 10;
		len++;
	}
	return (len);
}

static char	*ft_populate(char *ptr, unsigned int nb, int len, int sign)
{
	if (sign < 0)
		ptr[len + 1] = '\0';
	else
	{
		ptr[len] = '\0';
		len = len - 1;
	}
	if (nb == 0)
	{
		ptr[len] = nb % 10 + '0';
		return (ptr);
	}
	while (nb != 0)
	{
		ptr[len] = nb % 10 + '0';
		nb = nb / 10;
		len--;
	}
	if (sign < 0)
		ptr[len] = '-';
	return (ptr);
}
