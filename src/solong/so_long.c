/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danfern3 <danfern3@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/26 13:27:10 by danfern3          #+#    #+#             */
/*   Updated: 2025/10/27 12:20:07 by danfern3         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/headers/so_long.h"

static void	print_map(t_list *map)
{
	while (map)
	{
		ft_putstr_fd((const char *)map->content, 1);
		map = map->next;
	}
	ft_putendl_fd("\n", 1);
}

static void	read_map(char *filename)
{
	int		fd;
	char	*line;
	t_list	*new_elem;
	t_list	*list;

	list = NULL;
	fd = open(filename, O_RDONLY);
	if (fd == -1)
	{
		ft_putendl_fd("Error al abrir el archivo", 2);
		return ;
	}
	line = get_next_line(fd);
	while (line)
	{
		new_elem = ft_lstnew(line);
		if (!new_elem)
		{
			ft_lstclear(&list, free);
			break ;
		}
		ft_lstadd_back(&list, new_elem);
		line = get_next_line(fd);
	}
	print_map(list);
	char **map = create_map(list);
	t_game *game = validate_map(map);
	(void)game;
	ft_lstclear(&list, free);
	free_map(map);
	close(fd);
}

int main(int ac, char **av)
{
	(void)ac;
	char	*file_ext = NULL;
	if (!av || !av[1])
	{
		ft_putendl_fd("El programa debe recibir un archivo .ber", 2);
		return (0);
	}
	file_ext = ft_strrchr(av[1], '.');
	if (!file_ext || ft_strncmp(file_ext, ".ber", 4) != 0)
	{
		ft_putendl_fd("El programa debe recibir un archivo .ber", 2);
		return (0);
	}
	ft_putendl_fd("Archivo correcto", 1);
	read_map(av[1]);
	return (0);
}