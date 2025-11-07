/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danfern3 <danfern3@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/07 14:45:01 by danfern3          #+#    #+#             */
/*   Updated: 2025/11/07 14:45:03 by danfern3         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/headers/so_long.h"

// // TODO: DELETE
// void	print_list(t_list *list)
// {
// 	// TODO: DELETE
// 	ft_putendl_fd(__func__, 1);
// 	if (!list)
// 	{
// 		printf("---MISSING LIST---\n");
// 		return ;
// 	}
// 	while (list)
// 	{
// 		ft_putendl_fd((const char *)list->content, 1);
// 		list = list->next;
// 	}
// 	ft_putendl_fd("\n", 1);
// }

// // TODO: DELETE
// void	print_map(char **map, int rows)
// {
// 	// TODO: DELETE
// 	int	i;

// 	ft_putendl_fd(__func__, 1);
// 	if (!map)
// 	{
// 		printf("---MISSING MAP---\n");
// 		return ;
// 	}
// 	i = 0;
// 	while (i < rows)
// 	{
// 		ft_putendl_fd(map[i], 1);
// 		i++;
// 	}
// }

/**
 * Auxiliary function to reduce number of lines of generate_map function.
 * It just initializes the variables
 */
static t_bool	init_variables(t_game **game, char ***map)
{
	if (!(*game)->list)
		return (0);
	(*game)->map = malloc(sizeof(char *) * ((*game)->list->size + 1));
	if (!(*game)->map)
		return (0);
	*map = (*game)->map;
	(*game)->rows = (*game)->list->size;
	(*game)->cols = (*game)->list->content_size;
	return (1);
}

/**
 * Creates the map stored in the field list of @param game
 */
t_bool	generate_map(t_game **game)
{
	int		i;
	int		line_size;
	char	**map;
	t_list	*list;

	map = NULL;
	if (!init_variables(game, &map))
		return (0);
	i = 0;
	line_size = -1;
	list = (*game)->list;
	while (list)
	{
		map[i] = ft_strdup((char *)list->content);
		if (!map[i])
			return (0);
		if (line_size != -1 && line_size != (int)ft_strlen(map[i]))
			return (0);
		line_size = ft_strlen(map[i]);
		++i;
		list = list->next;
	}
	map[i] = NULL;
	return (1);
}
