/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdel-fra <rdel-fra@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/21 09:42:52 by rdel-fra          #+#    #+#             */
/*   Updated: 2024/12/10 21:35:57 by rdel-fra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Includes/ft_printf_bonus.h"

int	ft_printf(const char *format, ...)
{
	va_list	new_list;
	int		count;

	if (!format)
		return (-1);
	va_start(new_list, format);
	count = ft_search_percent(new_list, (char *)format);
	va_end(new_list);
	return (count);
}

size_t	ft_search_percent(va_list new_list, char *format)
{
	t_flags	flags;
	size_t	count;
	size_t	i;
	size_t	j;

	i = 0;
	j = 0;
	count = 0;
	while (format[i] != '\0')
	{
		ft_initialize_flags(&flags);
		if (format[i] == '%')
		{
			i++;
			j += ft_check_flags(&format[i], &flags);
			count += ft_check_type(format, i, new_list, &flags);
			i += ft_jump(format, i);
		}
		else
			ft_putchar(format[i], 1);
		i++;
	}
	return (i + count - j);
}

size_t	ft_check_type(char *str, size_t len, va_list new_list, t_flags *flags)
{
	size_t	count;

	while (str[len] == '#' || str[len] == ' ' || str[len] == '+')
		len++;
	count = 0;
	if (str[len] == 'c')
		count += ft_ischar(new_list);
	else if (str[len] == 's')
		count += ft_isstring(new_list);
	else if (str[len] == 'p')
		count += ft_ispointer(new_list, 'p');
	else if (str[len] == 'd' || str[len] == 'i')
		count += ft_isnumber(new_list, flags);
	else if (str[len] == 'u')
		count += ft_isunsigned(new_list);
	else if (str[len] == 'x' || str[len] == 'X')
		count += ft_ishexa(new_list, flags, str[len]);
	else
	{
		ft_putchar('%', 1);
		count += 1;
	}
	return (count);
}

size_t	ft_jump(char *str, size_t len)
{
	size_t	j;

	j = 0;
	while (str[len + j] == '#' || str[len + j] == ' ' || str[len + j] == '+')
		j++;
	return (j);
}

int	ft_ischar(va_list new_list)
{
	char	c;

	c = va_arg(new_list, int);
	ft_putchar(c, 1);
	return (1);
}

/*
#include <stdio.h>
#include <limits.h>

void printcmp(int a, int b)
{
    if (a == b)
    {
        ft_printf("OK\n");
    }
    else
        ft_printf("KO --!\n");
}

int	main(void)
{
	char ch = 'A';
	char *s = "string";
	int i = -42;
	int j = -42;
	unsigned int u = 42;
    int count;

    count = 0;

    //cc -w ft_printf_bonus.c ../Includes/ft_printf_bonus.h ft_lib_bonus.c 
	//ft_types_bonus.c ft_utils_bonus.c ft_flags_bonus.c
	//-Wall -Wextra -Werror
    //compile with -w

	// //Test 1: c, s, d, i
	printf("Test1\n");
	count = ft_printf("%s  %c  %d  %i\n", s, ch, i, i);
	printf("ft_printf count = %d\n\n", count);
	count = printf("%s  %c  %d  %i\n", s, ch, i, i);
    printf("printf count = %d\n\n\n", count);

	//Test 2: p
	printf("Test2\n");
    count = ft_printf("p: %p\n", s);
	printf("ft_printf count = %d\n\n", count);  
	count = printf("p: %p\n", s);
	printf("printf count = %d\n\n\n", count);  

	//Test 3: u
	printf("Test3\n");
    count = ft_printf("unsigned: %u\n", u);
	printf("ft_printf count = %d\n\n", count);
	count = printf("unsigned: %u\n", u);
	printf("printf count = %d\n\n\n", count);

	//Test 4: u but sending negative int
	printf("Test4\n");
    count = ft_printf("unsigned: %u\n", j);
	printf("ft_printf count = %d\n\n", count);
	count = printf("unsigned: %u\n", j);
	printf("printf count = %d\n\n\n", count);

	//Test 5: x
	printf("Test5\n");
	count = ft_printf("hex: %x\n", i);
	printf("ft_printf count = %d\n\n", count);
	ft_printf("hex: %x\n", i);
	printf("printf count = %d\n\n\n", count);

	//Test 6: X
	printf("Test6\n");
	count = ft_printf("hex: %X\n", i);
	printf("ft_printf count = %d\n\n", count);
	ft_printf("hex: %X\n", i);
	printf("printf count = %d\n\n\n", count);

	//Test 7: %%
	printf("Test7\n");
	count = ft_printf("percentage %%\n");
	printf("ft_printf count = %d\n\n", count);
	count = printf("percentage %%\n");
	printf("printf count = %d\n\n\n", count);

	//Test 8: %j - an invalid argument
	printf("Test8\n");
    count = ft_printf("f%jk\n", i);
	printf("ft_printf count = %d\n\n", count);
	count = printf("f%jk\n", i);
	printf("printf count = %d\n\n\n", count);

	//Test 9: s (null)
	printf("Test9\n");
	count = ft_printf(" NULL %s NULL\n", NULL);
	printf("ft_printf count = %d\n\n", count);
	count = printf(" NULL %s NULL\n", NULL);
	printf("printf count = %d\n\n\n", count);

	//Test 10: s (sending 0)
	printf("Test10\n");
	count = ft_printf(" NULL %s NULL\n", 0);
	printf("ft_printf count = %d\n\n", count);
	count = printf(" NULL %s NULL\n", 0);
	printf("printf count = %d\n\n\n", count);
	
	//Test 11: p (long address)
	//(long) LONG_MAX: 2147483647  LONG_MIN: -2147483648 
	printf("Test11\n");
	count = ft_printf(" %p %p \n", LONG_MIN, LONG_MAX);
	printf("ft_printf count = %d\n\n", count);
	count = printf(" %p %p \n", LONG_MIN, LONG_MAX);
	printf("printf count = %d\n\n\n", count);
	
	//Test 12: p (unsigned long address)
	printf("Test12\n");
	count = ft_printf(" %p %p \n", ULONG_MAX, -ULONG_MAX);
	printf("ft_printf count = %d\n\n", count);
	count = printf(" %p %p \n", ULONG_MAX, -ULONG_MAX);
	printf("printf count = %d\n\n\n", count);

	//Test 13: p (nil) (sending 0)
	printf("Test13\n");
	count = ft_printf(" %p %p \n", 0, 0);
	printf("ft_printf count = %d\n\n", count);
	count = printf(" %p %p \n", 0, 0);
	printf("printf count = %d\n\n\n", count);

	//Test 14: hex (sending 0)
	printf("Test14\n");
	count = ft_printf(" %x %x \n", 0, 0);
	printf("ft_printf count = %d\n\n", count);
	count = printf(" %x %x \n", 0, 0);
	printf("printf count = %d\n\n\n", count);

	//Test 15: with no arguments
	printf("Test15\n");
	count = ft_printf("hi %d hello\n");
	printf("ft_printf count = %d\n\n", count);
	count = printf("hi %d hello\n");
	printf("printf count = %d\n\n\n", count);

	//Test 16
	//undefined behavior, it can lead to seg fault or crash
	printf("Test16\n");
	count = printf(NULL);
	printf("printf count = %d\n\n", count);
	count = ft_printf(NULL);
	printf("ft_printf count = %d\n\n\n", count);

	//Test 17
	printf("Test17\n");
	count = printf("%s\n", "");
	printf("printf count = %d\n", count);
	count = ft_printf("%s\n", "");
	printf("ft_printf count = %d\n\n", count);

	////////// BONUS //////////

	printf("Test0 BONUS\n");
	count = printf("%#x\n", 456);
	printf("count: %d\n", count);
	count = ft_printf("%#x\n", 456);
	printf("count: %d\n\n", count);

	printf("Test1 BONUS\n");
	count = printf("%#X\n", -456);
	printf("count: %d\n", count);
	count = ft_printf("%#X\n", -456);
	printf("count: %d\n\n", count);

    printf("Test2 BONUS\n");
	count = printf("% d\n", 42);
	printf("count: %d\n", count);
	count = ft_printf("% d\n", 42);
	printf("count: %d\n\n", count);

    printf("Test3 BONUS\n");
	count = printf("%+d\n", 42);
	printf("count: %d\n", count);
	count = ft_printf("%+d\n", 42);
	printf("count: %d\n\n", count);

	printf("Test4 BONUS\n");
	count = printf("% +#d\n", -42);
	printf("count: %d\n", count);
	count = ft_printf("% +#d\n", -42);
	printf("count: %d\n\n", count);

	printf("Test5 BONUS\n");
	count = printf("% +d\n", -42);
	printf("count: %d\n", count);
	count = ft_printf("% +d\n", -42);
	printf("count: %d\n\n", count);

	printf("Test6 BONUS\n");
	count = printf("% +#x\n", 456);
	printf("count: %d\n", count);
	count = ft_printf("% +#x\n", 456);
	printf("count: %d\n\n", count);

	printf("Test7 BONUS\n");
	count = printf("% +#X\n", -456);
	printf("count: %d\n", count);
	count = ft_printf("% +#X\n", -456);
	printf("count: %d\n\n", count);

    printf("Test8 BONUS\n");
	count = printf("% i\n", 42);
	printf("count: %d\n", count);
	count = ft_printf("% i\n", 42);
	printf("count: %d\n\n", count);

    printf("Test9 BONUS\n");
	count = printf("%+i\n", 42);
	printf("count: %d\n", count);
	count = ft_printf("%+i\n", 42);
	printf("count: %d\n\n", count);

	printf("Test10 BONUS\n");
	count = printf("% +#i\n", -42);
	printf("count: %d\n", count);
	count = ft_printf("% +#i\n", -42);
	printf("count: %d\n\n", count);

	printf("Test11 BONUS\n");
	count = printf("% +i\n", -42);
	printf("count: %d\n", count);
	count = ft_printf("% +i\n", -42);
	printf("count: %d\n\n", count);

    char    *str = "12ozmouse";
    char    *nulo = NULL;
    char    **ptr;
    int     myfunc;
    int     original;
    ptr = &str;

    ft_printf("---------my func-----------\n");
    myfunc = ft_printf("c flag: %c|%c|%c|%c|%c\n", 'r', str[2],
     97 - 32, *str, 48);
    
    ft_printf("\n---------original-----------\n");
	original = printf("c flag: %c|%c|%c|%c|%c\n", 'r', str[2],
     97 - 32, *str, 48);

    ft_printf("\n---------resultado-----------\n");
    printcmp(myfunc, original);

    ft_printf("\n---------my func-----------\n");
    myfunc = ft_printf("s flag: %s|%s|%s|%s|%s|%s\n", "12ozmouse",
     str, str + 2, "", "-", nulo);
    
    ft_printf("\n---------original-----------\n");
    original = printf("s flag: %s|%s|%s|%s|%s|%s\n", "12ozmouse",
     str, str + 2, "", "-", nulo);

    ft_printf("\n---------resultado-----------\n");
    printcmp(myfunc, original);
    
    ft_printf("\n---------my func-----------\n");
    myfunc = ft_printf("p flag: %p|%p|%p|%p|%p|%p\n", str, &str, ptr, &ptr, 
	nulo, &nulo);

    ft_printf("\n---------original-----------\n");
    original = printf("p flag: %p|%p|%p|%p|%p|%p\n", str, &str, ptr, &ptr, 
	nulo, &nulo);

    ft_printf("\n---------resultado-----------\n");
    printcmp(myfunc, original);

    ft_printf("\n---------my func-----------\n");
    myfunc = ft_printf("d flag: %d|%d|%d|%d|%d\n", 7, -7, 0,
     2147483647, -2147483648);

    ft_printf("\n---------original-----------\n");
    original = printf("d flag: %d|%d|%d|%d|%d\n", 7, -7, 0,
     2147483647, -2147483647 - 1);

    ft_printf("\n---------resultado-----------\n");
    printcmp(myfunc, original);

    ft_printf("\n---------my func-----------\n");
    myfunc = ft_printf("i flag: %i|%i|%i|%i|%i\n", 7, -7, 0,
     2147483647, -2147483648);

    ft_printf("\n---------original-----------\n");
    original = printf("i flag: %i|%i|%i|%i|%i\n", 7, -7, 0,
     2147483647, -2147483647 - 1);

    ft_printf("\n---------resultado-----------\n");
    printcmp(myfunc, original);

    ft_printf("\n---------my func-----------\n");
    myfunc = ft_printf("u flag: %u|%u|%u|%u|%u\n", 7, -7, 0,
     2147483647, -2147483648);

    ft_printf("\n---------original-----------\n");
    original = printf("u flag: %u|%u|%u|%u|%u\n", 7, -7, 0,
     2147483647, -2147483647 - 1);

    ft_printf("\n---------resultado-----------\n");
    printcmp(myfunc, original);

    ft_printf("\n---------my func-----------\n");
    myfunc = ft_printf("x flag: %x|%x|%x|%x|%x\n", 7, -7, 0,
     2147483647, -2147483648);

    ft_printf("\n---------original-----------\n");
    original = printf("x flag: %x|%x|%x|%x|%x\n", 7, -7, 0,
     2147483647, -2147483647 - 1);

    ft_printf("\n---------resultado-----------\n");
    printcmp(myfunc, original);

    ft_printf("\n---------my func-----------\n");
    myfunc = ft_printf("X flag: %X|%X|%X|%X|%X\n", 7, -7, 0,
     2147483647, -2147483648);

    ft_printf("\n---------original-----------\n");
    original = printf("X flag: %X|%X|%X|%X|%X\n", 7, -7, 0,
     2147483647, -2147483647 - 1);

    ft_printf("\n---------resultado-----------\n");
    printcmp(myfunc, original);

    ft_printf("\n---------my func-----------\n");
    myfunc = ft_printf("%% flag: %% | %%|%% \n");

    ft_printf("\n---------original-----------\n");
    original = printf("%% flag: %% | %%|%% \n");

    ft_printf("\n---------resultado-----------\n");
    printcmp(myfunc, original);

    ft_printf("\n---------my func-----------\n");
    myfunc = ft_printf(", I've printed %d characters!\n",
     ft_printf("d flag: %d|%d|%d|%d", 0, -37, 37, 187398217));

    ft_printf("\n---------original-----------\n");
    original = printf(", I've printed %d characters!\n",
     printf("d flag: %d|%d|%d|%d", 0, -37, 37, 187398217));

    ft_printf("\n---------resultado-----------\n");
    printcmp(myfunc, original);

    ft_printf("\n---------my func-----------\n");
    myfunc = ft_printf(", I've printed %d characters!\n",
     ft_printf("d flag: %d|%d|%d|%d", 0, -22222, 'n', 0));

    ft_printf("\n---------original-----------\n");
    original = printf(", I've printed %d characters!\n",
     printf("d flag: %d|%d|%d|%d", 0, -22222, 'n', 0));

    ft_printf("\n---------resultado-----------\n");
    printcmp(myfunc, original);

    ft_printf("\n---------my func-----------\n");
    myfunc = ft_printf(", I've printed %d characters!\n",
     ft_printf("INT MIN: %d", -2147483647 - 1));

    ft_printf("\n---------original-----------\n");
    original = printf(", I've printed %d characters!\n",
     printf("INT MIN: %d", -2147483647 - 1));

    ft_printf("\n---------resultado-----------\n");
    printcmp(myfunc, original);

    ft_printf("\n---------my func-----------\n");
    myfunc = ft_printf("MIXED:%c|%s|%p|%d|%i|%u|%x|%X|%%\n", str[6], 
	nulo, str, -912387, 00000, -99, 743, 743);

    ft_printf("\n---------original-----------\n");
    original = printf("MIXED:%c|%s|%p|%d|%i|%u|%x|%X|%%\n", str[6], 
	nulo, str, -912387, 00000, -99, 743, 743);
    
    ft_printf("\n---------resultado-----------\n");
    printcmp(myfunc, original);


    ft_printf("\n---------my func-----------\n");
    myfunc = ft_printf(NULL);

    ft_printf("\n---------original-----------\n");
    original = printf(NULL);
    
    ft_printf("\n---------resultado-----------\n");
    printcmp(myfunc, original);
}
*/