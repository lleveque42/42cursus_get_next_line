/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lleveque <lleveque@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/09 12:11:09 by lleveque          #+#    #+#             */
/*   Updated: 2021/12/11 17:03:42 by lleveque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

# ifndef BUFFER_SIZE
#define BUFFER_SIZE 2
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
	// printf("out = %s\n", out);
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
	printf("next_str = %s\n", out);
	free(str);
	printf("next_str = %s\n", out);
	return (out);
}

char	*read_line(int fd, char *str)
{
	int		count;
	char	*buff;

	count = 1;
	if (fd <= 0)
		return (NULL);
	while (!(ft_strchr(str, '\n')) && count != 0)
	{
		buff = malloc(sizeof(char) * BUFFER_SIZE + 1);
		if (!buff)
		{
			free(str);
			return (NULL);
		}
		count = read(fd, buff, BUFFER_SIZE);
		buff[count] = '\0';
		if (count == -1)
		{
			free(str);
			free(buff);
			return (NULL);
		}
		str = ft_strjoin(str, buff);
	}
	return (str);
}

char	*get_next_line(int fd)
{
	printf("--- DEBUT BOUCLE ---\n\n");
	char 		*out;
	static char	*str;

	if (!fd)
		return (NULL);
	if (!str)
	{
		str = malloc(sizeof(char) * 1);
		if (!str)
			return (NULL);
		str[0] = '\0';
	}
	printf("str au debut = %s\n", str);
	str = read_line(fd, str);
	printf("str apres read line = %s\n", str);
	out = str_to_out(str);
	str = next_str(str);
	printf("next_str = %s\n\n---- FIN BOUCLE --- \n\n", str);
	return (out);
}
