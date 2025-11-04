/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danfern3 <danfern3@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/30 17:59:55 by danfern3          #+#    #+#             */
/*   Updated: 2025/11/04 12:21:27 by danfern3         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "../../inc/headers/so_long.h"

void	close_window(t_game *game)
{
	mlx_close_window(game->mlx);
}

static void error(void)
{
	sleep(4);
	puts(mlx_strerror(mlx_errno));
	exit(EXIT_FAILURE);
}

static void render_image(mlx_t *mlx, t_tex_img *tex_img, char c, t_pos pos)
{
	(void)mlx; 
	(void)pos;
	if (c == EMPTY_CHAR)
	{
		tex_img->texture = mlx_load_png("./images/0_grass.png");
	}
	else if (c == WALL_CHAR)
	{
		tex_img->texture = mlx_load_png("./images/1_bush.png");
	}
	else if (c == PLAYER_CHAR)
	{
		tex_img->texture = mlx_load_png("./images/P_witch_idle.png");
	}
	else if (c == EXIT_CHAR)
	{
		tex_img->texture = mlx_load_png("./images/E_exit.png");
	}
	// else if (c == COLLECTABLE_CHAR)
	else
	{
		tex_img->texture = mlx_load_png("./images/C_mushroom.png");
	}

}

static t_bool	is_valid_ceil(t_game *game, t_pos new_pos)
{
	char	**map;

	map = game->map;
	
	if (map[new_pos.x][new_pos.y] == WALL_CHAR)
		return (false);
	return (true);
}

static void check_rendered_img(t_game *game)
{
	if (!game->tex_img[game->player_pos.x][game->player_pos.y].texture)
		error();
	game->tex_img[game->player_pos.x][game->player_pos.y].img = mlx_texture_to_image(game->mlx, game->tex_img[game->player_pos.x][game->player_pos.y].texture);
	if (!game->tex_img[game->player_pos.x][game->player_pos.y].img)
		error();
	mlx_resize_image(game->tex_img[game->player_pos.x][game->player_pos.y].img, IMG_WIDTH, IMG_HEIGHT);
	if (mlx_image_to_window(game->mlx, game->tex_img[game->player_pos.x][game->player_pos.y].img, IMG_WIDTH * game->player_pos.y, IMG_HEIGHT * game->player_pos.x) < 0)
		error();
}

static void	replace_img(t_game *game, t_pos new_pos)
{
	free_single_texture(game->mlx, &game->tex_img[game->player_pos.x][game->player_pos.y]);
	render_image(game->mlx, &game->tex_img[game->player_pos.x][game->player_pos.y], EMPTY_CHAR, game->player_pos);
	check_rendered_img(game);
	game->player_pos = init_pos(new_pos.x, new_pos.y);
	free_single_texture(game->mlx, &game->tex_img[game->player_pos.x][game->player_pos.y]);
	render_image(game->mlx, &game->tex_img[game->player_pos.x][game->player_pos.y], PLAYER_CHAR, game->player_pos);
	check_rendered_img(game);
}

void	my_keyhook(mlx_key_data_t keydata, void *param)
{
	t_game	*game;

	game = (t_game *)param;
	//todo: REUSABLE CODE SNIPPET
	if ((keydata.key == MLX_KEY_W || keydata.key == MLX_KEY_UP) && keydata.action == MLX_PRESS)
	{
		if (is_valid_ceil(game, init_pos(game->player_pos.x - 1, game->player_pos.y)))
		{
			replace_img(game, init_pos(game->player_pos.x - 1, game->player_pos.y));
			// printf("(%d, %d) -> ", game->player_pos.x--, game->player_pos.y);	
			// printf("(%d, %d)", game->player_pos.x, game->player_pos.y);	
		}
	}
	if ((keydata.key == MLX_KEY_A || keydata.key == MLX_KEY_LEFT) && keydata.action == MLX_PRESS)
	{
		if (is_valid_ceil(game, init_pos(game->player_pos.x, game->player_pos.y - 1)))
		{
			replace_img(game, init_pos(game->player_pos.x, game->player_pos.y - 1));
			// printf("(%d, %d) -> ", game->player_pos.x, game->player_pos.y--);	
			// printf("(%d, %d)", game->player_pos.x, game->player_pos.y);	
		}
	}
	if ((keydata.key == MLX_KEY_S || keydata.key == MLX_KEY_DOWN) && keydata.action == MLX_PRESS)
	{
		if (is_valid_ceil(game, init_pos(game->player_pos.x + 1, game->player_pos.y)))
		{
			replace_img(game, init_pos(game->player_pos.x + 1, game->player_pos.y));
			// printf("(%d, %d) -> ", game->player_pos.x++, game->player_pos.y);	
			// printf("(%d, %d)", game->player_pos.x, game->player_pos.y);	
		}
	}
	if ((keydata.key == MLX_KEY_D || keydata.key == MLX_KEY_RIGHT) && keydata.action == MLX_PRESS)
	{
		if (is_valid_ceil(game, init_pos(game->player_pos.x, game->player_pos.y + 1)))
		{
			replace_img(game, init_pos(game->player_pos.x, game->player_pos.y + 1));
			// printf("(%d, %d) -> ", game->player_pos.x, game->player_pos.y++);	
			// printf("(%d, %d)", game->player_pos.x, game->player_pos.y);	
		}	
	}
	if (keydata.key == MLX_KEY_ESCAPE && keydata.action == MLX_PRESS)
		close_window(game);
}

static void	render_single_ceil(t_game *game, int i, int j)
{
	t_pos	pos;

	pos = init_pos(i, j);
	render_image(game->mlx, &game->tex_img[i][j], game->map[i][j], pos);
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