/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danfern3 <danfern3@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/27 08:12:45 by danfern3          #+#    #+#             */
/*   Updated: 2025/10/27 12:19:38 by danfern3         ###   ########.fr       */
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

	map = malloc(sizeof(char *) * (list->size + 1));
	if (!map)
		return (NULL);
	i = 0;
	while (list)
	{
		map[i] = ft_strdup((char *)list->content);
		if (!map[i])
			return (free_map(map));
		++i;
		list = list->next;
	}
	map[i] = NULL;
	return (map);
}

t_game	*validate_map(char **map)
{
	t_game	*game;
	int i = 0;
	game = malloc(sizeof(t_game));
	if (!game)
		return (game);
	while (map && map[i])
	{
		ft_putstr_fd(map[i], 1);
		i++;
	}
	// free(map);
	// free(game->map);
	free(game);
	return (NULL);
}

#endif