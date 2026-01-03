/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   file.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danfern3 <danfern3@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/07 10:18:07 by danfern3          #+#    #+#             */
/*   Updated: 2025/11/17 07:52:00 by danfern3         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

/**
 * Replaces the endlines with NULL values in the @param s
 */
static void	clear_new_lines(char **s)
{
	int		i;
	char	*str;

	str = *s;
	i = 0;
	while (str && str[i])
	{
		if (str[i] == '\n')
			str[i] = 0;
		++i;
	}
}

/**
 * Auxiliary function to reduce numbers of lines of generate_list function.
 */
static void	free_list(t_list *list, int *res)
{
	ft_lstclear(&list, free);
	*res = 0;
}

/**
 * Auxiliary function to reduce numbers of lines of generate_list function.
 */
static	t_list	*create_elem(char *line, t_list *list, int *res)
{
	t_list	*elem;

	elem = ft_lstnew(line);
	if (!elem)
	{
		free(line);
		free_list(list, res);
		return (NULL);
	}
	return (elem);
}

/**
 * Generates a list in which every node contains one single line
 * of the file @param fd
 */
bool	generate_list(int fd, t_game **game)
{
	char	*line;
	t_list	*new_elem;
	int		res;
	t_list	*list;

	res = 1;
	list = NULL;
	line = get_next_line(fd, 0);
	while (line)
	{
		clear_new_lines(&line);
		new_elem = create_elem(line, list, &res);
		if (!new_elem)
			break ;
		ft_lstadd_back(&list, new_elem);
		if (line && list->content_size != (int)ft_strlen(line))
		{
			res = 0;
			break ;
		}
		line = get_next_line(fd, 0);
	}
	line = get_next_line(fd, 1);
	(*game)->list = list;
	return (res);
}

/**
 * Reads the map stored in the file @param filename.
 * If the map couldn have been either generated or validated, 
 * it prints an error message.
 */
t_game	*read_map(char *filename)
{
	int		fd;
	t_game	*game;
	bool	err;

	fd = open(filename, O_RDONLY);
	if (fd == -1)
	{
		ft_putendl_fd(RED "Error when opening file" RESET, 2);
		return (NULL);
	}
	game = init_game();
	if (!generate_list(fd, &game) || !generate_map(&game))
		return (print_and_free(game, LINE_NUMBER_ERROR));
	t_list *aux = game->list;
	while (aux)
	{
		printf("%s\n", (char *)aux->content);
		aux = aux->next;
	}
	err = validate_map(&game);
	close(fd);
	if (err <= 0)
		return (print_and_free(game, err));
	return (game);
}
