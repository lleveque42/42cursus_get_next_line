/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lleveque <lleveque@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/17 15:33:46 by lleveque          #+#    #+#             */
/*   Updated: 2022/01/17 17:29:42 by lleveque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

int	move_down(t_mlx	*mlx)
{
	mlx->vector.y += 64;
	mlx_put_image_to_window(mlx->ptr, mlx->win, mlx->img, mlx->vector.x, mlx->vector.y);
	return (1);
}

int	move_left(t_mlx	*mlx)
{
	mlx->vector.x -= 64;
	mlx_put_image_to_window(mlx->ptr, mlx->win, mlx->img, mlx->vector.x, mlx->vector.y);
	return (1);
}

int	move_up(t_mlx	*mlx)
{
	mlx->vector.y -= 64;
	mlx_put_image_to_window(mlx->ptr, mlx->win, mlx->img, mlx->vector.x, mlx->vector.y);
	return (1);
}

int	move_right(t_mlx	*mlx)
{
	mlx->vector.x += 64;
	mlx_put_image_to_window(mlx->ptr, mlx->win, mlx->img, mlx->vector.x, mlx->vector.y);
	return (1);
}