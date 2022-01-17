/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lleveque <lleveque@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/12 16:38:34 by lleveque          #+#    #+#             */
/*   Updated: 2022/01/17 18:16:49 by lleveque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

// int	ft_exit(t_mlx *mlx)
// {
// 	mlx_clear_window(mlx->ptr, mlx->win);
// 	mlx_destroy_window(mlx->ptr, mlx->win);
// 	mlx_destroy_display(mlx->ptr);
// 	free(mlx->ptr);
// 	exit (0);
// }

// int	keyhook(int keycode, void *mlx)
// {
// 	if (keycode == 65307)
// 		return (ft_exit(mlx));
// 	else if (keycode == 119)
// 		return (move_up(mlx));
// 	else if (keycode == 115)
// 		return (move_down(mlx));
// 	else if (keycode == 97)
// 		return (move_left(mlx));
// 	else if (keycode == 100)
// 		return (move_right(mlx));
// 	return (0);
// }

// int	init_window(t_mlx	*mlx)
// {
// 	mlx->ptr = mlx_init();
// 	mlx->win = mlx_new_window(mlx->ptr, 640, 448, "so_long");
// 	mlx->img = mlx_xpm_file_to_image(mlx->ptr, "sprites/player_01.xpm", &mlx->sprites.width, &mlx->sprites.width);
// 	return (1);
// }

int	main(int ac, char **av)
{
	t_mlx	mlx;
	(void)ac;
	(void)av;

	parse_map(&mlx);
	// init_window(&mlx);
	// mlx_put_image_to_window(mlx.ptr, mlx.win, mlx.img, mlx.vector.x, mlx.vector.y);
	// mlx_key_hook(mlx.win, &keyhook, &mlx);
	// mlx_hook(mlx.win, 17, 17, &ft_exit, &mlx);
	// mlx_loop(mlx.ptr);
}