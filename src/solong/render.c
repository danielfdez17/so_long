/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danfern3 <danfern3@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/30 17:59:55 by danfern3          #+#    #+#             */
/*   Updated: 2025/11/04 13:39:56 by danfern3         ###   ########.fr       */
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

/**
 * Checks if the new rendered image has been rendered correctly
 */
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

/**
 * Swaps the images to simulate player's movement
 */
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

/**
 * Custom keyhook to control pressed keys
 */
void	my_keyhook(mlx_key_data_t keydata, void *param)
{
	t_game	*game;

	game = (t_game *)param;
	if ((keydata.key == MLX_KEY_W || keydata.key == MLX_KEY_UP) 
		&& keydata.action == MLX_PRESS 
		&& is_valid_ceil(game, init_pos(game->player_pos.x - 1, game->player_pos.y)))
			replace_img(game, init_pos(game->player_pos.x - 1, game->player_pos.y));
	if ((keydata.key == MLX_KEY_A || keydata.key == MLX_KEY_LEFT) 
		&& keydata.action == MLX_PRESS 
		&& is_valid_ceil(game, init_pos(game->player_pos.x, game->player_pos.y - 1)))
			replace_img(game, init_pos(game->player_pos.x, game->player_pos.y - 1));
	if ((keydata.key == MLX_KEY_S || keydata.key == MLX_KEY_DOWN) 
		&& keydata.action == MLX_PRESS 
		&& is_valid_ceil(game, init_pos(game->player_pos.x + 1, game->player_pos.y)))
			replace_img(game, init_pos(game->player_pos.x + 1, game->player_pos.y));
	if ((keydata.key == MLX_KEY_D || keydata.key == MLX_KEY_RIGHT) 
		&& keydata.action == MLX_PRESS 
		&& is_valid_ceil(game, init_pos(game->player_pos.x, game->player_pos.y + 1)))
			replace_img(game, init_pos(game->player_pos.x, game->player_pos.y + 1));
	if (keydata.key == MLX_KEY_ESCAPE && keydata.action == MLX_PRESS)
		close_window(game);
}

/**
 * 
 */
static void	render_single_ceil(t_game *game, int i, int j)
{
	render_image(game->mlx, &game->tex_img[i][j], game->map[i][j], init_pos(i, j));
	if (!game->tex_img[i][j].texture)
		error();
	game->tex_img[i][j].img = mlx_texture_to_image(game->mlx, game->tex_img[i][j].texture);
	if (!game->tex_img[i][j].img)
		error();
	mlx_resize_image(game->tex_img[i][j].img, IMG_WIDTH, IMG_HEIGHT);
	if (mlx_image_to_window(game->mlx, game->tex_img[i][j].img, IMG_WIDTH * j, IMG_HEIGHT * i) < 0)
		error();
}

static void	render_background(t_game *game, int i, int j)
{
	render_image(game->mlx, &game->background[i][j], EMPTY_CHAR, init_pos(i, j));
	if (!game->background[i][j].texture)
		error();
	game->background[i][j].img = mlx_texture_to_image(game->mlx, game->background[i][j].texture);
	if (!game->background[i][j].img)
		error();
	mlx_resize_image(game->background[i][j].img, IMG_WIDTH, IMG_HEIGHT);
	if (mlx_image_to_window(game->mlx, game->background[i][j].img, IMG_WIDTH * j, IMG_HEIGHT * i) < 0)
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
			render_background(game, i, j);
			render_single_ceil(game, i, j);
			++j;
		}
		++i;
	}
}

// TODO: the 2 following functions can reuse the same function
static void	alloc_textures(t_game **game)
{
	int	i;

	(*game)->tex_img = malloc(sizeof(t_tex_img *) * (*game)->rows);
	if (!(*game)->tex_img)
		return ;
	i = 0;
	while (i < (*game)->rows)
	{
		(*game)->tex_img[i] = malloc(sizeof(t_tex_img) * (*game)->cols);
		if (!(*game)->tex_img[i])
			return ;
		++i;
	}
}

static void	alloc_background(t_game **game)
{
	int	i;

	(*game)->background = malloc(sizeof(t_tex_img *) * (*game)->rows);
	if (!(*game)->background)
		return ;
	i = 0;
	while (i < (*game)->rows)
	{
		(*game)->background[i] = malloc(sizeof(t_tex_img) * (*game)->cols);
		if (!(*game)->background[i])
			return ;
		++i;
	}
}

int32_t	render_game(t_game *game)
{
	alloc_textures(&game);
	alloc_background(&game);
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
