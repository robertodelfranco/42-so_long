/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putendl_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdel-fra <rdel-fra@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/17 11:12:36 by rdel-fra          #+#    #+#             */
/*   Updated: 2024/11/29 17:21:08 by rdel-fra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fcntl.h>
#include "../Includes/libft.h"

void	ft_putendl_fd(char *s, int fd)
{
	int		i;

	i = 0;
	while (s[i] != '\0')
	{
		write(fd, &s[i], 1);
		i++;
	}
	write(fd, "\n", 1);
}

/*
int	main(void)
{
	ft_putendl_fd("Hello, 42!", 1);

	int fd = open("output.txt", O_WRONLY | O_CREAT | O_TRUNC, 0644);
	if (fd == -1)
	{
		printf("Erro ao abrir o arquivo.\n");
		return (1);
	}
	ft_putendl_fd("Escrevendo em um arquivo com ft_putendl_fd.", fd);

	printf("Testando com fd = -1 (inválido):\n");
	ft_putendl_fd("Isto não deve ser impresso.", -1);

	close(fd);
	return (0);
}
*/