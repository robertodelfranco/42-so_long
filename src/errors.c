/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdel-fra <rdel-fra@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/04 15:45:35 by rdel-fra          #+#    #+#             */
/*   Updated: 2025/02/04 15:58:26 by rdel-fra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	message_error(short error_code)
{
	if (error_code == EXIT_FAILURE)
		ft_putstr_fd("Error\n", STDERR_FILENO);
	if (error_code == EXIT_INVALID_ARGS)
		ft_putstr_fd("Error\nInvalid Args\n", STDERR_FILENO);
	if (error_code == EXIT_INVALID_FILE)
		ft_putstr_fd("Error\nInvalid File\n", STDERR_FILENO);
	if (error_code == EXIT_INVALID_MAP)
		ft_putstr_fd("Error\nInvalid Map\n", STDERR_FILENO);
	exit(error_code);
}
