/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danfern3 <danfern3@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/27 08:12:45 by danfern3          #+#    #+#             */
/*   Updated: 2025/10/28 13:58:17 by danfern3         ###   ########.fr       */
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
	t_list	*list;
	int		exit_number;
	int		player_number;
	int		collectable_number;
	int		rows;
	int		cols;
} t_game;

typedef int	t_bool;

// Todo: DELETE DELETE DELETE
// ! FOR TESTING
void	print_list(t_list *list);
void	print_map(char **map, int rows, int cols);


// * FILES
// * GAME
// * MAP

t_bool	free_map(char **map);
void	free_game(t_game *game);
t_game	*init_game();
t_bool	validate_map(t_game *game);
void	read_map(char *filename);
t_bool	generate_map(t_game **game);
t_bool	generate_list(int fd, t_game **game);



// TODO: DELETE DELETE DELETE
// char **create_map(t_list *list)
// {
// 	char	**map;
// 	int		i;
// 	int	line_size;

// 	line_size = -1;
// 	map = malloc(sizeof(char *) * (list->size + 1));
// 	if (!map)
// 		return (NULL);
// 	i = 0;
// 	while (list)
// 	{
// 		map[i] = ft_strdup((char *)list->content);
// 		if (!map[i])
// 			return (free_map(map));
// 		if (line_size != -1 && line_size != (int)ft_strlen(map[i]))
// 			return (free_map(map));
// 		line_size = ft_strlen(map[i]);
// 		++i;
// 		list = list->next;
// 	}
// 	map[i] = NULL;
// 	return (map);
// }

#endif