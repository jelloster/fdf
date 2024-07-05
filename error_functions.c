/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_functions.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: motuomin <motuomin@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/04 14:55:31 by motuomin          #+#    #+#             */
/*   Updated: 2024/07/04 14:55:32 by motuomin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	ft_error(void)
{
		ft_putstr_fd((char *)mlx_strerror(mlx_errno), STDERR_FILENO);
		exit(EXIT_FAILURE);
}
