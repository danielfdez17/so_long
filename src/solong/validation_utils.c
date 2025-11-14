/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validation_utils.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danfern3 <danfern3@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/07 11:37:25 by danfern3          #+#    #+#             */
/*   Updated: 2025/11/14 10:03:09 by danfern3         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/headers/so_long.h"

/**
 * Increments the value pointed by @param number an @returns a t_pos structure
 * with the given values @param i and @param j
 */
t_pos	char_found(int i, int j, int *number)
{
	*number = *number + 1;
	return (init_pos(i, j));
}

/**
 * @returns if the given char @param c is a valid
 * or not.
 */
t_bool	is_valid_char(char c)
{
	return (c == WALL_CHAR
		|| c == EMPTY_CHAR
		|| c == EXIT_CHAR
		|| c == PLAYER_CHAR
		|| c == COLLECTABLE_CHAR);
}

/**
 * @returns if the given position @param x @param y is
 * in the border of the map or not
 */
t_bool	is_border(int rows, int cols, int x, int y)
{
	if (x == 0 || x == rows - 1)
		return (1);
	if (y == 0 || y == cols - 1)
		return (1);
	return (0);
}

/**
 * @returns a copy of the map pointed by @param game
 */
static char	**duplicate_map(t_game *game)
{
	char	**dup;
	int		i;

	i = 0;
	dup = malloc(sizeof(char *) * (game->rows + 1));
	if (!dup)
		return (NULL);
	while (i < game->rows)
	{
		dup[i] = ft_strdup(game->map[i]);
		if (!dup[i])
		{
			free_map(dup);
			return (NULL);
		}
		i++;
	}
	dup[i] = NULL;
	return (dup);
}

/**
 * @returns 1 if there is no error in the @param game.
 * Otherwise, @returns the corresponding error value
 */
t_bool	is_error(t_game *game)
{
	t_bool	valid_ways;
	t_bool	valid_exit;
	t_game	*g;

	if (game->player_number != 1)
		return (PLAYER_NUMBER_ERROR);
	if (game->exit_number != 1)
		return (EXIT_NUMBER_ERROR);
	if (game->collectable_number < 1)
		return (COLLECTABLE_NUMBER_ERROR);
	g = init_game();
	g->map = duplicate_map(game);
	copy_game(g, game);
	valid_exit = validate_exit(g, g->map, g->p_pos.x, g->p_pos.y);
	g->collectable_number = game->collectable_number;
	free_map(g->map);
	g->map = duplicate_map(game);
	valid_ways = validate_ways(g, g->map, g->p_pos.x, g->p_pos.y);
	if (!valid_exit || !valid_ways)
	{
		free_game(g);
		return (INVALID_PATH_ERROR);
	}
	free_game(g);
	return (1);
}
