/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: motuomin <motuomin@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/25 16:48:43 by motuomin          #+#    #+#             */
/*   Updated: 2024/05/02 12:11:46 by motuomin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_BONUS_H
# define GET_NEXT_LINE_BONUS_H

# include <unistd.h>
# include <limits.h>
# include <stdlib.h>

//Function prototypes
char	*get_next_line(int fd);
char	*find_line(char *buf);
char	*trim_buf(char *buf, int c_g);
char	*read_until_line(int fd, char *buf);

// Utils
size_t	ft_strlen(const char *s);
char	*ft_strjoin(char *s1, char *s2);
char	*ft_strchr(const char *s, int c);
void	*ft_memdel(char **ptr);
char	*ft_strdup(const char *s1);

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 3
# endif

#endif
