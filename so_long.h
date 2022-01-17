/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lleveque <lleveque@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/12 12:04:41 by lleveque          #+#    #+#             */
/*   Updated: 2022/01/17 18:20:30 by lleveque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "mlx/mlx.h"
# include "mlx/mlx_int.h"
# include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>

typedef struct s_sprites
{
	int	width;
	int	height;
}	t_sprites;

typedef struct s_vector
{
	int	x;
	int	y;
}	t_vector;

typedef struct s_mlx
{
	void		*ptr;
	void		*win;
	void		*img;
	int			width;
	int			height;
	t_sprites	sprites;
	t_vector	vector;
}	t_mlx;

void	parse_map(t_mlx *mlx);
int		move_down(t_mlx *mlx);
int		move_left(t_mlx *mlx);
int		move_up(t_mlx *mlx);
int		move_right(t_mlx *mlx);

#endif