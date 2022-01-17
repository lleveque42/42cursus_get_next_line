/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lleveque <lleveque@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/17 17:31:42 by lleveque          #+#    #+#             */
/*   Updated: 2022/01/17 18:21:31 by lleveque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

int	get_map_depth(t_mlx *mlx)
{
	int		fd;
	char	*buff;
	int		depth;
	int		count;
	(void)mlx;

	fd = open("map.ber", O_RDONLY);
	buff = "\0";
	depth = 0;
	count = 1;
	while (count)
	{
		count = read(fd, buff, count);
		if (buff[0] == '\0' || buff[0] == '\n')
			depth++;
	}
	printf("%d\n", depth);
	return (depth);
}

void	parse_map(t_mlx *mlx)
{
	get_map_depth(mlx);
}