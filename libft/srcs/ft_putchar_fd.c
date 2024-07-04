/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putchar.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: motuomin <motuomin@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/14 12:39:08 by motuomin          #+#    #+#             */
/*   Updated: 2024/04/22 16:17:49 by motuomin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* Desription : Outputs the character ’c’ to the given file descriptor.*/

#include <unistd.h>

void	ft_putchar_fd(char c, int fd)
{
	write(fd, &c, 1);
}
