/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putendl_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: motuomin <motuomin@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/18 17:32:49 by motuomin          #+#    #+#             */
/*   Updated: 2024/04/22 16:07:44 by motuomin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* Description : Outputs the string ’s’ to the given file descriptor followed
 * by a newline. */

#include <unistd.h>

void	ft_putendl_fd(char *s, int fd)
{
	unsigned int	i;

	i = 0;
	while (s[i] != '\0')
	{
		write(fd, &s[i], 1);
		i++;
	}
	write(fd, "\n", 1);
}
