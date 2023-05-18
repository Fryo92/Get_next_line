
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abiddane <abiddane@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/29 11:28:40 by abiddane          #+#    #+#             */
/*   Updated: 2022/11/29 19:03:21 by abiddane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strlen(char *s)
{
	size_t	i;

	i = 0;
	if (!s)
		return (0);
	while (s[i])
		i++;
	return (i);
}

char	*ft_strchr(char *str, int c)
{
	int	i;

	i = 0;
	if (!str)
		return (NULL);
	while (str[i])
	{
		if (str[i] == (char)c)
			return ((char *)&str[i]);
		i++;
	}
	if (c == 0)
		return ((char *)&str[i]);
	return (NULL);
}

char	*ft_strjoin(char *str, char *buf)
{
	size_t		i;
	size_t		j;
	char		*dest;

	i = 0;
	if (!str)
	{
		str = ft_calloc(1, sizeof(char));
		str[0] = '\0';
	}
	dest = ft_calloc((ft_strlen(str) + ft_strlen(buf) + 1), sizeof(char));
	if (!dest)
		return (NULL);
	while (str[i])
	{
		dest[i] = str[i];
		i++;
	}
	j = 0;
	while (buf[j])
		dest[i++] = buf[j++];
	free(str);
	dest[i] = '\0';
	return (dest);
}

char	*ft_get_line(char *str)
{
	int		i;
	char	*dest;

	i = 0;
	if (!str[i])
		return (NULL);
	while (str[i] && str[i] != '\n')
		i++;
	dest = ft_calloc((i + 2), sizeof(char));
	if (!dest)
		return (NULL);
	i = 0;
	while (str[i] && str[i] != '\n')
	{
		dest[i] = str[i];
		i++;
	}
	if (str[i] && str[i] == '\n')
	{
		dest[i] = str[i];
		i++;
	}
	dest[i] = '\0';
	return (dest);
}

char	*ft_get_new_line(char *str)
{
	int		i;
	int		j;
	char	*dest;

	i = 0;
	while (str[i] && str[i] != '\n')
		i++;
	if (!str[i])
	{
		free(str);
		return (NULL);
	}
	dest = ft_calloc((ft_strlen(str) - i + 1), sizeof(char));
	if (!dest)
		return (NULL);
	i++;
	j = 0;
	while (str[i])
		dest[j++] = str[i++];
	dest[j] = '\0';
	free(str);
	return (dest);
}
