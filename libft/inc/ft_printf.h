/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: motuomin <motuomin@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/03 15:00:49 by motuomin          #+#    #+#             */
/*   Updated: 2024/05/15 13:28:48 by motuomin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <unistd.h>
# include <stdarg.h>

// -- Typedef --

typedef unsigned long long	t_ull;

// -- Macros --

# define BUFFER_SIZE 1000

// -- Structs --

typedef struct print_info
{
	char	buf[BUFFER_SIZE];
	int		i;
	int		ret;
}			t_print_info;

// --  Function prototypes --

// ft_printf.c
int		ft_printf(const char *str, ...);

// buf_functions.c
int		print_buf(t_print_info *p_i);
int		write_to_buf(char c, t_print_info *p_i);
int		write_to_buf_str(char *str, t_print_info *p_i);

// conversion_functions.c
int		write_hex(unsigned long long nbr, char *base, t_print_info *p_i);
int		putnbr_str(int n, t_print_info *p_i);
int		put_unsigned_nbr_str(unsigned int n, t_print_info *p_i);

#endif
