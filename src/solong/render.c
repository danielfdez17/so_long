/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danfern3 <danfern3@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/30 17:59:55 by danfern3          #+#    #+#             */
/*   Updated: 2025/11/03 09:05:08 by danfern3         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "../../inc/headers/so_long.h"

void	close_window(t_game *game)
{
	mlx_terminate(game->mlx);
}

void	my_keyhook(mlx_key_data_t keydata, void *param)
{
	if (keydata.key == MLX_KEY_W && keydata.action == MLX_PRESS)
		puts("W key pressed!");
	if (keydata.key == MLX_KEY_A && keydata.action == MLX_PRESS)
		puts("A key pressed!");
	if (keydata.key == MLX_KEY_S && keydata.action == MLX_PRESS)
		puts("S key pressed!");
	if (keydata.key == MLX_KEY_D && keydata.action == MLX_PRESS)
		puts("D key pressed!");
	if (keydata.key == MLX_KEY_UP && keydata.action == MLX_PRESS)
		puts("Up key pressed!");
	if (keydata.key == MLX_KEY_LEFT && keydata.action == MLX_PRESS)
		puts("Left key pressed!");
	if (keydata.key == MLX_KEY_DOWN && keydata.action == MLX_PRESS)
		puts("Down key pressed!");
	if (keydata.key == MLX_KEY_RIGHT && keydata.action == MLX_PRESS)
		puts("Right key pressed!");
	if (keydata.key == MLX_KEY_ESCAPE && keydata.action == MLX_PRESS)
		close_window(param);
}

int32_t	render_game(t_game *game)
{
	(void)game;
	game->mlx = mlx_init(WIDTH, HEIGHT, "SO LOOOOOOOOOONG", true);
	if (!game->mlx)
		return (EXIT_FAILURE);
	mlx_key_hook(game->mlx, &my_keyhook, game);
	// if (game->mlx)
	mlx_loop(game->mlx);
	return (EXIT_SUCCESS);
}

// Exit the program as failure.
// static void ft_error(void)
// {
// 	fprintf(stderr, "%s", mlx_strerror(mlx_errno));
// 	exit(EXIT_FAILURE);
// }

// void	my_key_hook(mlx_key_data_t keydata, void *param)
// {
// 	mlx_t	*mlx;

// 	mlx = (mlx_t *)param;
// 	if (keydata.key == MLX_KEY_W && keydata.action == MLX_PRESS)
// 		puts("W key pressed!");
// 	if (keydata.key == MLX_KEY_A && keydata.action == MLX_PRESS)
// 		puts("A key pressed!");
// 	if (keydata.key == MLX_KEY_S && keydata.action == MLX_PRESS)
// 		puts("S key pressed!");
// 	if (keydata.key == MLX_KEY_D && keydata.action == MLX_PRESS)
// 		puts("D key pressed!");
// 	if (keydata.key == MLX_KEY_UP && keydata.action == MLX_PRESS)
// 		puts("Up key pressed!");
// 	if (keydata.key == MLX_KEY_LEFT && keydata.action == MLX_PRESS)
// 		puts("Left key pressed!");
// 	if (keydata.key == MLX_KEY_DOWN && keydata.action == MLX_PRESS)
// 		puts("Down key pressed!");
// 	if (keydata.key == MLX_KEY_RIGHT && keydata.action == MLX_PRESS)
// 		puts("Right key pressed!");
// 	if (keydata.key == MLX_KEY_ESCAPE && keydata.action == MLX_PRESS)
// 	{
// 		puts("Escape key pressed!");
// 		sleep(1);
// 		mlx_close_window(mlx);
// 	}
// }

// int32_t	main(void)
// {
// 	// mlx_set_setting(MLX_MAXIMIZED, true);
// 	mlx_t	*mlx = mlx_init(WIDTH, HEIGHT, "42 MLX", true);
// 	if (!mlx)
// 		ft_error();

// 	// mlx_image_t	*img = mlx_new_image(mlx, WIDTH, HEIGHT);
// 	// if (!img || (mlx_image_to_window(mlx, img, 0, 0) < 0))
// 	// 	ft_error();

// 	// mlx_put_pixel(img, 0, 0, 0xFF0000FF);

// 	mlx_key_hook(mlx, &my_key_hook, mlx);
// 	mlx_loop(mlx);
// 	mlx_terminate(mlx);
// 	return (EXIT_SUCCESS);
// }