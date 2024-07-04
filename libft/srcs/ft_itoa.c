/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: motuomin <motuomin@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/18 15:02:58 by motuomin          #+#    #+#             */
/*   Updated: 2024/04/19 12:50:35 by motuomin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* Description : Allocates (with malloc(3)) and returns a string representing
 * the integer received as an argument. Negative numbers must be handled. */

#include <stdlib.h>
#include "../inc/libft.h"

static int	numlen(int n);

char	*ft_itoa(int n)
{
	char	*str;
	int		len;
	int		neg;

	len = numlen(n);
	neg = 0;
	if (n == -2147483648)
		return (ft_strdup("-2147483648"));
	str = malloc(sizeof(char) * (len + 1));
	if (!str)
		return (NULL);
	if (n < 0)
	{
		str[0] = '-';
		n = -n;
		neg = 1;
	}
	str[len] = '\0';
	len--;
	while ((len >= 0 && !neg) || (len > 0 && neg))
	{
		str[len--] = (n % 10) + '0';
		n /= 10;
	}
	return (str);
}

static int	numlen(int n)
{
	int	len;

	len = 1;
	if (n < 0)
	{
		n = -n;
		len++;
	}
	while (n >= 10)
	{
		len++;
		n /= 10;
	}
	return (len);
}
