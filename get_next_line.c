/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hlabouit <hlabouit@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/24 04:29:45 by hlabouit          #+#    #+#             */
/*   Updated: 2022/12/28 01:17:46 by hlabouit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	get_position(char *join)
{
	int	i;

	i = 0;
	if (!join)
		return (-1);
	while (join[i])
	{
		if (join[i] == '\n')
			return (i);
		i++;
	}
	return (-1);
}

char	*after_line(char *join, int i)
{
	int		len;
	char	*tmp;

	len = ft_strlen(join + i);
	tmp = join;
	join = ft_substr(join, i, len);
	free(tmp);
	return (join);
}

char	*get_myline(char *join)
{
	int		i;
	char	*myline;

	i = get_position(join);
	myline = ft_substr(join, 0, i + 1);
	return (myline);
}

char	*get_next_line_(int fd)
{
	static char	*join;
	int			i;
	char		*buffer;
	char		*myline;

	i = 1;
	buffer = malloc((BUFFER_SIZE + 1) * sizeof(char));
	if (!buffer)
		return (NULL);
	if (!join)
		join = ft_strdup("");
	while (i > 0 && get_position(join) == -1)
	{
		i = read(fd, buffer, BUFFER_SIZE);
		buffer[i] = '\0';
		if (i < 0)
			return (free(join), join = NULL, free(buffer), NULL);
		join = ft_strjoin(join, buffer);
		if (i == 0 && join[0] == '\0')
			return (free(buffer), free(join), join = NULL, NULL);
		if (i == 0 && get_position(join) == -1)
			return (free(buffer), myline = join, join = NULL, myline);
	}
	return (free(buffer), buffer = NULL, myline = get_myline(join),
		join = after_line(join, get_position(join) + 1), myline);
}

char	*get_next_line(int fd)
{
	if (read(fd, NULL, 0) < 0)
		return (NULL);
	return (get_next_line_(fd));
}
