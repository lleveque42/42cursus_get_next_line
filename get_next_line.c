/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lleveque <lleveque@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/09 12:11:09 by lleveque          #+#    #+#             */
/*   Updated: 2021/12/09 17:09:30 by lleveque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

# ifndef BUFFER_SIZE
#define BUFFER_SIZE 42
#endif
#include <stdio.h>

char	*str_to_out(char *str)
{
	size_t	i;
	size_t	len;
	char 	*out;

	i = 0;
	len = 0;
	while (str && str[len] && str[len] != '\n')
		len++;
	out = malloc(sizeof(char) * (len + 2));
	while (i <= len)
	{
		out[i] = str[i];
		i++;
	}
	out[i] = '\0';
	return (out);
}

char	*next_str(char *str)
{
	char *out;
	size_t	i;
	size_t	j;

	i = 0;
	j = 0;
	if (!str)
		return (NULL);
	while (str[i] && str[i] != '\n')
		i++;
	out = malloc(sizeof(char) * (ft_strlen(str) - i + 1));
	if (!out)
		return (NULL);
	while (str[i])
	{
		out[j] = str[i];
		j++;
		i++;
	}
	out[j] = '\0';
	free(str);
	return (out);
}

char	*get_next_line(int fd)
{
	char 		*buff;
	char 		*out;
	static char	*str;
	int			count;

	if (!fd)
		return (NULL);
	if (!str)
		str = malloc(sizeof(char) * 1);
	str[0] = '\0';
	count = 1;
	while (!(ft_strchr(str, '\n')) && count != 0)
	{
		buff = malloc(sizeof(char) * BUFFER_SIZE + 1);
		if (!buff)
		{
			free(str);
			return (NULL);
		}
		count = read(fd, buff, BUFFER_SIZE);
		if (count == -1)
		{
			free(str);
			free(buff);
			return (NULL);
		}
		str = ft_strjoin(str, buff);
	}
	out = str_to_out(str);
	str = next_str(str);
	return (out);
}
