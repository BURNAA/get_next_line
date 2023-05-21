/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.h                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hlabouit <hlabouit@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/26 22:24:24 by hlabouit          #+#    #+#             */
/*   Updated: 2022/12/27 22:37:50 by hlabouit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_BONUS_H
# define GET_NEXT_LINE_BONUS_H

# include <stdio.h>
# include <fcntl.h>
# include <stdlib.h>
# include <unistd.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 42
# endif

char	*get_next_line(int fd);
char	*get_myline(char *join);
char	*after_line(char *join, int i);
int		get_position(char *join);
char	*ft_substr(char *s, int start, int len);
char	*ft_strjoin(char *join, char *buffer);
char	*ft_strdup(char *join);
int		ft_strlen(char *join);
char	*get_next_line_(int fd);

#endif