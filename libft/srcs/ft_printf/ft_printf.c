/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: motuomin <motuomin@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/02 13:12:31 by motuomin          #+#    #+#             */
/*   Updated: 2024/05/07 15:12:09 by motuomin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* Description : The printf() family of functions produces output according to
 * a format as described below.
 *
 * Return value : These functions return the number of characters printed
 * (not including the trailing `\0' && a negative value if an error occurs. */

#include "../../inc/libft.h"

static int	print_variable(char c, t_print_info *p_i, va_list ptr);
static int	go_through_str(const char *str, t_print_info *p_i, va_list ptr);

int	ft_printf(const char *str, ...)
{
	t_print_info	print_info;
	t_print_info	*p_i;
	va_list			ptr;

	p_i = &print_info;
	p_i->i = 0;
	p_i->ret = 0;
	va_start(ptr, str);
	if (go_through_str(str, p_i, ptr) == -1)
	{
		va_end(ptr);
		return (-1);
	}
	va_end(ptr);
	return (p_i->ret);
}

static int	go_through_str(const char *str, t_print_info *p_i, va_list ptr)
{
	size_t	i;

	i = 0;
	while (str[i] != '\0')
	{
		if (str[i] == '%')
		{
			if (str[i + 1] != '\0')
			{
				if (print_variable(str[++i], p_i, ptr) == -1)
					return (-1);
			}
			else
				return (1);
		}
		else
		{
			if (write_to_buf(str[i], p_i) == -1)
				return (-1);
		}
		i++;
	}
	if (print_buf(p_i) == -1)
		return (-1);
	return (p_i->ret);
}

static int	print_variable(char c, t_print_info *p_i, va_list ptr)
{
	if (c == 'c')
		return (write_to_buf(va_arg(ptr, int), p_i));
	else if (c == 's')
		return (write_to_buf_str(va_arg(ptr, char *), p_i));
	else if (c == 'd' || c == 'i')
		return (putnbr_str(va_arg(ptr, int), p_i));
	else if (c == 'u')
		return (put_unsigned_nbr_str(va_arg(ptr, unsigned int), p_i));
	else if (c == '%')
		return (write_to_buf('%', p_i));
	else if (c == 'x')
		return (write_hex(va_arg(ptr, unsigned int), "0123456789abcdef", p_i));
	else if (c == 'X')
		return (write_hex(va_arg(ptr, unsigned int), "0123456789ABCDEF", p_i));
	else if (c == 'p')
	{
		if (write_to_buf_str("0x", p_i) == -1)
			return (-1);
		return (write_hex(va_arg(ptr, t_ull), "0123456789abcdef", p_i));
	}
	return (1);
}
