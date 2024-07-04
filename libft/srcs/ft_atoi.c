/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: motuomin <motuomin@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/16 16:41:24 by motuomin          #+#    #+#             */
/*   Updated: 2024/04/22 14:46:16 by motuomin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* Description : converts the initial portion of the string pointed to by str
 * to int representation. */

#include <limits.h>

int	ft_atoi(const char *str)
{
	int	res;
	int	sign;

	res = 0;
	sign = 1;
	while (*str == ' ' || *str == '\t' || *str == '\n'
		|| *str == '\f' || *str == '\r' || *str == '\v')
		str++;
	if (*str == '-' || *str == '+')
	{
		if (*(str++) == '-')
			sign = -1;
	}
	while (*str >= '0' && *str <= '9')
	{
		if (res - (1 / 10) > INT_MAX / 10 && sign == -1)
			return (0);
		else if (res > (INT_MAX / 10) && sign == 1)
			return (-1);
		res = res * 10 + (*str - '0');
		str++;
	}
	return (res * sign);
}
