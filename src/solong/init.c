/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danfern3 <danfern3@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/07 11:30:51 by danfern3          #+#    #+#             */
/*   Updated: 2025/11/14 10:02:38 by danfern3         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

/**
 * @returns an instance of t_pos with the given @param x and @param y
 */
t_pos	init_pos(int x, int y)
{
	t_pos	pos;

	pos.x = x;
	pos.y = y;
	return (pos);
}

/**
 * Allocates and @returns a pointer to a t_game structure
 */
t_game	*init_game(void)
{
	t_game	*game;

	game = malloc(sizeof(t_game));
	if (!game)
		return (NULL);
	game->map = NULL;
	game->p_pos = init_pos(-1, -1);
	game->e_pos = init_pos(-1, -1);
	game->player_number = 0;
	game->exit_number = 0;
	game->collectable_number = 0;
	game->list = NULL;
	game->rows = 0;
	game->cols = 0;
	game->movs = 0;
	game->mlx = NULL;
	game->foreground = NULL;
	// game->background = NULL;
	return (game);
}

/**
 * Copies the information of @param game into the @param copy
 */
void	copy_game(t_game *copy, t_game *game)
{
	copy->p_pos = init_pos(game->p_pos.x, game->p_pos.y);
	copy->e_pos = init_pos(game->e_pos.x, game->e_pos.y);
	copy->player_number = game->player_number;
	copy->exit_number = game->exit_number;
	copy->collectable_number = game->collectable_number;
	copy->rows = game->rows;
	copy->cols = game->cols;
}
