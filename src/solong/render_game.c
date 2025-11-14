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

#include "../../inc/headers/so_long.h"

/**
 * Allocates memory for the foreground
 */
static void	alloc_foreground(t_game **game)
{
	int	i;

	(*game)->foreground = malloc(sizeof(t_tex_img *) * ((*game)->rows + 1));
	if (!(*game)->foreground)
		return ;
	i = 0;
	while (i <= (*game)->rows)
	{
		(*game)->foreground[i] = malloc(sizeof(t_tex_img) * (*game)->cols);
		if (!(*game)->foreground[i])
			return ;
		++i;
	}
}

/**
 * Allocates memory for the background
 */
static void	alloc_background(t_game **game)
{
	int	i;

	(*game)->background = malloc(sizeof(t_tex_img *) * ((*game)->rows + 1));
	if (!(*game)->background)
		return ;
	i = 0;
	while (i <= (*game)->rows)
	{
		(*game)->background[i] = malloc(sizeof(t_tex_img) * (*game)->cols);
		if (!(*game)->background[i])
			return ;
		++i;
	}
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
	mlx_delete_image(game->mlx, game->background[game->rows][0].img);
	game->background[game->rows][0].img = mlx_put_string(game->mlx, msg, 0, \
		IMG_HEIGHT * game->rows);
	free(msg);
	if (!game->background[game->rows][0].img)
		return ;
}

/**
 * Renders the full map, creating the window and executing the loop game
 */
int32_t	render_game(t_game *game)
{
	alloc_foreground(&game);
	alloc_background(&game);
	game->mlx = mlx_init(IMG_WIDTH * (game->cols), \
		IMG_HEIGHT * (game->rows + 1), GAME_NAME, true);
	if (!game->mlx)
		return (EXIT_FAILURE);
	mlx_set_window_limit(game->mlx, IMG_WIDTH * game->cols, \
		IMG_HEIGHT * (game->rows), IMG_WIDTH * game->cols, \
		IMG_HEIGHT * (game->rows + 1));
	render_ceils(game);
	mlx_key_hook(game->mlx, &my_keyhook, game);
	mlx_loop(game->mlx);
	return (EXIT_SUCCESS);
}
