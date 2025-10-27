/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danfern3 <danfern3@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/27 08:12:45 by danfern3          #+#    #+#             */
/*   Updated: 2025/10/27 14:09:44 by danfern3         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
// #include <math.h>
#include "../libft/libft.h"
#include "../headers/get_next_line.h"

typedef struct s_pos
{
	int	x;
	int	y;
} t_pos;

typedef struct s_game
{
	char	**map;
	t_pos	player_pos;
	t_pos	exit_pos;
	int		exit_number;
	int		player_number;
	int		collectable_number;
	int		rows;
	int		cols;
} t_game;

char	**free_map(char **map)
{
	int	i;

	i = 0;
	while (map && map[i])
		free(map[i++]);
	free(map);
	return (NULL);
}

char **create_map(t_list *list)
{
	char	**map;
	int		i;
	ssize_t	line_size;

	line_size = -1;
	map = malloc(sizeof(char *) * (list->size + 1));
	if (!map)
		return (NULL);
	i = 0;
	while (list)
	{
		map[i] = ft_strdup((char *)list->content);
		if (!map[i])
			return (free_map(map));
		if (line_size != -1 && line_size != ft_strlen(map[i]))
			return (free_map(map));
		line_size = ft_strlen(map[i]);
		++i;
		list = list->next;
	}
	map[i] = NULL;
	return (map);
}

int	is_border(int rows, int cols, int x, int y)
{
	if (x == 0 || x == rows - 1)
		return (1);
	if (y == 0 || y == cols - 1)
		return (1);
	return (0);
}

t_pos	init_pos()
{
	t_pos	pos;

	pos.x = -1;
	pos.y = -1;
	return (pos);
}

t_game	*init_game()
{
	t_game	*game;

	game = malloc(sizeof(t_game));
	if (!game)
		return (NULL);
	game->map = NULL;
	game->player_pos = init_pos();
	game->exit_pos = init_pos();
	game->player_number = 0;
	game->collectable_number = 0;
	game->rows = 0;
	game->cols = 0;
	return (game);
}

t_game	*validate_map(char **map, int rows, int cols)
{
	t_game	*game;
	int i = 0;
	int	j;
	game = malloc(sizeof(t_game));
	if (!game)
		return (game);
	while (map && map[i][j] && i < rows)
	{
		j = 0;
		while (map && map[i][j] && j < cols)
		{
			if (is_border(rows, cols, i, j) && map[i][j] != '1')
				break ;
			if (map[i][j] == 'P')
			{
				game->player_pos.x = i;
				game->player_pos.y = j;
				game->player_number++;
			}
			else if (map[i][j] == 'E')
			{
				game->exit_pos.x = i;
				game->exit_pos.y = j;
				game->exit_number++;
			}
			else if (map[i][j] == 'C')
				game->collectable_number++;
			j++;
		}
		i++;
	}
	// free(game);
	return (game);
}

#endif