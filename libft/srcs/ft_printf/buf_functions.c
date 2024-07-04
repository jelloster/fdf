/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   buf_functions.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: motuomin <motuomin@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/06 11:43:24 by motuomin          #+#    #+#             */
/*   Updated: 2024/05/14 09:36:58 by motuomin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/libft.h"

int	print_buf(t_print_info *p_i)
{
	if (write(1, p_i->buf, p_i->i) < 0)
		return (-1);
	p_i->ret += p_i->i;
	p_i->i = 0;
	return (1);
}

int	write_to_buf(char c, t_print_info *p_i)
{
	if (p_i->i == BUFFER_SIZE)
		if (print_buf(p_i) < 0)
			return (-1);
	p_i->buf[p_i->i++] = c;
	return (1);
}

int	write_to_buf_str(char *str, t_print_info *p_i)
{
	int	i;

	i = 0;
	if (!str)
	{
		if (write_to_buf_str("(null)", p_i) == -1)
			return (-1);
		return (1);
	}
	while (str[i])
	{
		if (write_to_buf(str[i], p_i) < 0)
			return (-1);
		i++;
	}
	return (1);
}
