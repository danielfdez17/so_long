/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danfern3 <danfern3@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/30 17:59:55 by danfern3          #+#    #+#             */
/*   Updated: 2025/11/04 08:25:26 by danfern3         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "../../inc/headers/so_long.h"

void	close_window(t_game *game)
{
	mlx_close_window(game->mlx);
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

static void error(void)
{
	sleep(4);
	puts(mlx_strerror(mlx_errno));
	exit(EXIT_FAILURE);
}

static void	render_single_ceil(t_game *game, int i, int j)
{
	if (game->map[i][j] == '0')
		game->tex_img[i][j].texture = mlx_load_png("./images/0_grass.png");
	else if (game->map[i][j] == '1')
		game->tex_img[i][j].texture = mlx_load_png("./images/1_bush.png");
	else if (game->map[i][j] == 'P')
		game->tex_img[i][j].texture = mlx_load_png("./images/P_witch_idle.png");
	else if (game->map[i][j] == 'E')
		game->tex_img[i][j].texture = mlx_load_png("./images/E_exit.png");
	else
		game->tex_img[i][j].texture = mlx_load_png("./images/C_mushroom.png");
	if (!game->tex_img[i][j].texture)
		error();
	game->tex_img[i][j].img = mlx_texture_to_image(game->mlx, game->tex_img[i][j].texture);
	if (!game->tex_img[i][j].img)
		error();
	mlx_resize_image(game->tex_img[i][j].img, IMG_WIDTH, IMG_HEIGHT);
	if (mlx_image_to_window(game->mlx, game->tex_img[i][j].img, IMG_WIDTH * j, IMG_HEIGHT * i) < 0)
		error();
}

static void	render_ceils(t_game *game)
{
	int	i;
	int	j;

	i = 0;
	while (i < game->rows)
	{
		j = 0;
		while (j < game->cols)
		{
			render_single_ceil(game, i, j);
			++j;
		}
		++i;
	}
}

int32_t	render_game(t_game *game)
{
	game->mlx = mlx_init(IMG_WIDTH * game->cols, IMG_HEIGHT * (game->rows + 1), "SO LOOOOOOOOOONG", true);
	if (!game->mlx)
		return (EXIT_FAILURE);
	mlx_set_window_limit(game->mlx, IMG_WIDTH * game->cols, IMG_HEIGHT * (game->rows + 1), IMG_WIDTH * game->cols, IMG_HEIGHT * (game->rows + 1));
	render_ceils(game);
	mlx_key_hook(game->mlx, &my_keyhook, game);
	mlx_loop(game->mlx);
	return (EXIT_SUCCESS);
}

void	render_map(t_game *game)
{
	mlx_texture_t* texture = mlx_load_png("./images/0_grass.png");
	if (!texture)
		error();

	mlx_image_t* img = mlx_texture_to_image(game->mlx, texture);
	if (!img)
	error();
	
	mlx_resize_image(img, 24, 24);

	if (mlx_image_to_window(game->mlx, img, 0, 0) < 0)
		error();
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