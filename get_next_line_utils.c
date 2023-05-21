/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hlabouit <hlabouit@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/24 04:31:47 by hlabouit          #+#    #+#             */
/*   Updated: 2022/12/26 22:37:24 by hlabouit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_substr(char *s, int start, int len)
{
	char	*substr;
	int		i;

	i = 0;
	if (!s)
		return (NULL);
	if (start > ft_strlen(s))
		return (ft_strdup(""));
	if (len > ft_strlen(s))
		len = ft_strlen(s);
	substr = (char *)malloc((len + 1) * sizeof(char));
	if (!substr)
		return (NULL);
	while (s[start + i] && i < len)
	{
		substr[i] = s[start + i];
		i++;
	}
	substr[i] = '\0';
	return (substr);
}

char	*ft_strjoin(char *join, char *buffer)
{
	char	*jn_bf;
	int		i;
	int		j;
	int		len;

	if (!join || !buffer)
		return (NULL);
	i = 0;
	len = ft_strlen(join) + ft_strlen(buffer);
	jn_bf = (char *)malloc((len + 1) * sizeof(char));
	if (!jn_bf)
		return (NULL);
	while (join[i])
	{
		jn_bf[i] = join[i];
		i++;
	}
	j = i;
	i = 0;
	while (buffer[i])
		jn_bf[j++] = buffer[i++];
	jn_bf[j] = '\0';
	free(join);
	return (jn_bf);
}

char	*ft_strdup( char *join)
{
	int		i;
	int		len;
	char	*to_fill;

	i = 0;
	len = ft_strlen(join);
	to_fill = malloc((len + 1) * sizeof(char));
	if (!to_fill)
		return (NULL);
	while (join[i])
	{
		to_fill[i] = join[i];
		i++;
	}
	to_fill[i] = '\0';
	return (to_fill);
}

int	ft_strlen(char *join)
{
	int	i;

	i = 0;
	while (join[i])
		i++;
	return (i);
}
