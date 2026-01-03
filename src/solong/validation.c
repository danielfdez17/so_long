/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validation.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danfern3 <danfern3@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/07 11:32:31 by danfern3          #+#    #+#             */
/*   Updated: 2025/11/07 17:30:54 by danfern3         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

/**
 * @returns true if the given char @param c
 * is a valid character except the wall ('1')
 */
static bool	except_wall(char c)
{
	return (c == PLAYER_CHAR
		|| c == COLLECTABLE_CHAR
		|| c == EXIT_CHAR
		|| c == GHOST_CHAR
		|| c == EMPTY_CHAR);
}

/**
 * @returns true if the player can reach every collectable and the exit
 */
bool	validate_ways(t_game *game, char **map, int x, int y)
{
	if (!map)
		return (false);
	if (x < 0 || x >= game->rows || y < 0 || y >= game->cols)
		return (false);
	if (map[x][y] == 'V' || map[x][y] == WALL_CHAR)
		return (false);
	if (except_wall(map[x][y]))
	{
		if (map[x][y] == COLLECTABLE_CHAR)
			game->collectable_number--;
		else if (map[x][y] == EXIT_CHAR)
			game->exit_number--;
		map[x][y] = 'V';
	}
	validate_ways(game, map, x - 1, y);
	validate_ways(game, map, x + 1, y);
	validate_ways(game, map, x, y + 1);
	validate_ways(game, map, x, y - 1);
	return (game->collectable_number == 0 && game->exit_number == 0);
}

/**
 * @returns true if the player can reach every collectable
 * considering the exit and enemies as a walls
 */
bool	validate_exit(t_game *game, char **map, int x, int y)
{
	if (!map)
		return (false);
	if (x < 0 || x >= game->rows || y < 0 || y >= game->cols)
		return (false);
	if (map[x][y] == 'V' || map[x][y] == WALL_CHAR || map[x][y] == EXIT_CHAR
		|| map[x][y] == GHOST_CHAR)
	if (except_wall(map[x][y]))
	{
		if (map[x][y] == COLLECTABLE_CHAR)
			game->collectable_number--;
		map[x][y] = 'V';
	}
	validate_exit(game, map, x - 1, y);
	validate_exit(game, map, x + 1, y);
	validate_exit(game, map, x, y + 1);
	validate_exit(game, map, x, y - 1);
	return (game->collectable_number == 0);
}

/**
 * Auxiliary function to reduce number of lines of function validate_map
 */
static void	update_chars(t_game *g, char **map, int i, int j)
{
	if (map[i][j] == PLAYER_CHAR)
		g->p_pos = char_found(i, j, &g->player_number);
	else if (map[i][j] == EXIT_CHAR)
		g->e_pos = char_found(i, j, &g->exit_number);
	else if (map[i][j] == COLLECTABLE_CHAR)
		char_found(i, j, &g->collectable_number);
}

int	validate_map(t_game **game)
/**
 * @returns true if the map is valid according to the statement rules
 */
{
	int		i;
	int		j;
	char	**map;
	t_game	*g;

	g = *game;
	map = g->map;
	i = 0;
	while (i < g->rows)
	{
		j = 0;
		while (j < g->cols)
		{
			if (!is_valid_char(map[i][j]))
				return (INVALID_CHAR_ERROR);
			if (is_border(g->rows, g->cols, i, j) && map[i][j] != WALL_CHAR)
				return (BORDER_ERROR);
			update_chars(g, map, i, j);
			j++;
		}
		i++;
	}
	return (is_error(g));
}
