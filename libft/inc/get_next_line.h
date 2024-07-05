/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: motuomin <motuomin@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/25 16:48:43 by motuomin          #+#    #+#             */
/*   Updated: 2024/07/04 16:08:54 by motuomin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <unistd.h>
# include <stdlib.h>

//Function prototypes
char	*get_next_line(int fd);
char	*find_line(char *buf);
char	*trim_buf(char *buf, int c_g);
char	*read_until_line(int fd, char *buf);

// Utils
void	*ft_memdel(char **ptr);
char	*gnl_strjoin(char *s1, char *s2);

# ifndef GNL_BUFFER_SIZE
#  define GNL_BUFFER_SIZE 3
# endif

#endif
