/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_types.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdel-fra <rdel-fra@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/25 14:57:46 by rdel-fra          #+#    #+#             */
/*   Updated: 2024/12/10 21:36:45 by rdel-fra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Includes/ft_printf_bonus.h"

int	ft_isstring(va_list new_list)
{
	char	*arg;

	arg = va_arg(new_list, char *);
	if (arg == NULL)
	{
		ft_putstr("(null)", 1);
		return (6);
	}
	ft_putstr(arg, 1);
	return (ft_strlen(arg));
}

int	ft_ispointer(va_list new_list, char c)
{
	void	*ptr;

	ptr = va_arg(new_list, void *);
	if (ptr == 0)
	{
		ft_putstr("(nil)", 1);
		return (5);
	}
	ft_putstr("0x", 1);
	ft_putnbr_base((unsigned long)ptr, c);
	return (ft_hexa_len((unsigned long) ptr) + 2);
}

int	ft_isnumber(va_list new_list, t_flags *flags)
{
	int	d;
	int	sign_count;
	int	space_count;

	sign_count = 0;
	space_count = 0;
	d = va_arg(new_list, int);
	if ((*flags).sign == 1 && d > -1)
		ft_putchar('+', 1);
	else if ((*flags).space == 1 && d > -1)
		ft_putchar(' ', 1);
	ft_putnbr(d, 1);
	if ((*flags).sign == 1 && d > -1)
		sign_count = 1;
	else if ((*flags).space == 1 && d > -1)
		space_count = 1;
	return (ft_nbrlen(d) + sign_count + space_count);
}

int	ft_isunsigned(va_list new_list)
{
	unsigned int	u;

	u = va_arg(new_list, unsigned int);
	ft_putnbr(u, 1);
	return (ft_nbrlen(u));
}

int	ft_ishexa(va_list new_list, t_flags *flags, char c)
{
	unsigned int	x;
	int				hash_count;

	hash_count = 0;
	x = va_arg(new_list, int);
	if (c == 'x')
	{
		if ((*flags).hash == 1 && x != 0)
			ft_putstr("0x", 1);
		ft_putnbr_base(x, c);
	}
	else
	{
		if ((*flags).hash == 1 && x != 0)
			ft_putstr("0X", 1);
		ft_putnbr_base(x, c);
	}
	if ((*flags).hash == 1 && x != 0)
		hash_count = 2;
	return (ft_hexa_len(x) + hash_count);
}
