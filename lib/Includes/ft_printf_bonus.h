/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_bonus.h                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdel-fra <rdel-fra@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/23 10:43:53 by rdel-fra          #+#    #+#             */
/*   Updated: 2024/12/10 21:33:17 by rdel-fra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_BONUS_H
# define FT_PRINTF_BONUS_H

# include <unistd.h>
# include <stdarg.h>
# include "libft.h"

typedef struct s_flags
{
	int		sign;
	int		space;
	int		hash;
}	t_flags;

int		ft_printf(const char *format, ...);
int		ft_ischar(va_list new_list);
int		ft_isstring(va_list new_list);
int		ft_ispointer(va_list new_list, char c);
int		ft_isunsigned(va_list new_list);
int		ft_isnumber(va_list new_list, t_flags *flags);
int		ft_ishexa(va_list new_list, t_flags *flags, char c);
void	ft_putptr(void *ptr);
void	ft_putnbr(long n, int fd);
void	ft_putstr(char *s, int fd);
void	ft_putchar(char c, int fd);
void	ft_putnbr_base(unsigned long nb, char hex);
size_t	ft_nbrlen(long n);
size_t	ft_hexa_len(unsigned long n);
size_t	ft_search_percent(va_list new_list, char *format);
size_t	ft_check_type(char *str, size_t len, va_list new_list, t_flags *flags);
void	ft_initialize_flags(t_flags *flags);
size_t	ft_jump(char *str, size_t len);
size_t	ft_check_flags(char *str, t_flags *flags);

#endif /* FT_PRINTF_BONUS_H */