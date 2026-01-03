/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_game.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danfern3 <danfern3@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/07 12:59:28 by danfern3          #+#    #+#             */
/*   Updated: 2025/11/14 10:04:44 by danfern3         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

/**
 * Allocates memory for the foreground
 */
static void	alloc_foreground(t_game **game)
{
	int	i;

	(*game)->foreground = malloc(sizeof(t_tex_img *) * ((*game)->rows));
	if (!(*game)->foreground)
		return ;
	i = 0;
	while (i < (*game)->rows)
	{
		(*game)->foreground[i] = malloc(sizeof(t_tex_img) * (*game)->cols);
		if (!(*game)->foreground[i])
			return ;
		++i;
	}
	(*game)->movements = malloc(sizeof(t_tex_img));
	if (!(*game)->movements)
		return ;
}

void	render_movs(t_game *game)
{
	char	*msg;
	char	*itoa;

	itoa = ft_itoa(game->movs);
	if (!itoa)
		return ;
	msg = ft_strjoin("Movements count: ", itoa);
	free(itoa);
	if (!msg)
		return ;
	mlx_delete_image(game->mlx, game->movements->img);
	game->movements->img = mlx_put_string(game->mlx, msg, 0, IMG_HEIGHT * game->rows);
	free(msg);
}

void	replace_enemy_sprite(t_game *game, t_pos pos)
{
	(void)game, (void)pos;
	struct timeval	tv;

	gettimeofday(&tv, NULL);
	// free_single_texture(game->mlx, &game->foreground[pos.x][pos.y]);
	if (tv.tv_sec % MAX_SPRITES == 0)
		game->foreground[pos.x][pos.y].texture = mlx_load_png("./images/G_0.png");
	else if (tv.tv_sec % MAX_SPRITES == 1)
		game->foreground[pos.x][pos.y].texture = mlx_load_png("./images/G_1.png");
	else if (tv.tv_sec % MAX_SPRITES == 2)
		game->foreground[pos.x][pos.y].texture = mlx_load_png("./images/G_2.png");
	else if (tv.tv_sec % MAX_SPRITES == 3)
		game->foreground[pos.x][pos.y].texture = mlx_load_png("./images/G_3.png");
	else if (tv.tv_sec % MAX_SPRITES == 4)
		game->foreground[pos.x][pos.y].texture = mlx_load_png("./images/G_4.png");
	else if (tv.tv_sec % MAX_SPRITES == 5)
		game->foreground[pos.x][pos.y].texture = mlx_load_png("./images/G_5.png");
	else if (tv.tv_sec % MAX_SPRITES == 6)
		game->foreground[pos.x][pos.y].texture = mlx_load_png("./images/G_6.png");
	else if (tv.tv_sec % MAX_SPRITES == 7)
		game->foreground[pos.x][pos.y].texture = mlx_load_png("./images/G_7.png");
	else
		game->foreground[pos.x][pos.y].texture = mlx_load_png("./images/G_8.png");
	if (!game->foreground[pos.x][pos.y].texture)
		error();
	game->foreground[pos.x][pos.y].img
		= mlx_texture_to_image(game->mlx, game->foreground
		[pos.x][pos.y].texture);
	if (!game->foreground[pos.x][pos.y].img)
		error();
	mlx_resize_image(game->foreground
		[pos.x][pos.y].img, IMG_WIDTH, IMG_HEIGHT);
	if (mlx_image_to_window(game->mlx, game->foreground
		[pos.x][pos.y].img,
		IMG_WIDTH * pos.y, IMG_HEIGHT * pos.x) < 0)
		error();
}

/**
 * 
 */
void	update_enemies_sprite(void *param)
{
	int		i;
	int		j;
	t_game	*game;

	game = (t_game *)param;
	i = -1;
	while (++i < game->rows)
	{
		j = -1;
		while (++j < game->cols)
		{
			if (game->map[i][j] == GHOST_CHAR)
				replace_enemy_sprite(game, init_pos(i, j));
		}
	}
}

/**
 * Renders the full map, creating the window and executing the loop game
 */
int32_t	render_game(t_game *game)
{
	alloc_foreground(&game);
	game->mlx = mlx_init(IMG_WIDTH * (game->cols),
		IMG_HEIGHT * (game->rows + 1), GAME_NAME, true);
	if (!game->mlx)
		return (EXIT_FAILURE);
	mlx_set_window_limit(game->mlx, IMG_WIDTH * game->cols,
		IMG_HEIGHT * (game->rows), IMG_WIDTH * game->cols,
		IMG_HEIGHT * (game->rows + 1));
	render_ceils(game);
	mlx_key_hook(game->mlx, &my_keyhook, game);
	mlx_loop_hook(game->mlx, update_enemies_sprite, game);
	mlx_loop(game->mlx);
	return (EXIT_SUCCESS);
}
