

#include "../../inc/headers/so_long.h"

t_bool	generate_list(int fd, t_game **game)
{
	char	*line;
	t_list	*new_elem;
	t_bool	res;
	t_list	*list;

	res = 1;
	list = NULL;
	line = get_next_line(fd, 0);
	while (line)
	{
		new_elem = ft_lstnew(line);
		if (!new_elem)
		{
			free(line);
			ft_lstclear(&list, free);
			res = 0;
			break ;
		}
		ft_lstadd_back(&list, new_elem);
		if (line && list->content_size != (int)ft_strlen(line))
		{
			ft_lstclear(&list, free);
			res = 0;
			break ;
		}
		line = get_next_line(fd, 0);
	}
	line = get_next_line(fd, 1);
	print_list(list);
	(*game)->list = list;
	return (res);
}

void	read_map(char *filename)
{
	int		fd;
	t_game *game;

	fd = open(filename, O_RDONLY);
	if (fd == -1)
	{
		ft_putendl_fd("Error al abrir el archivo", 2);
		return ;
	}
	game = init_game();
	if (!generate_list(fd, &game))
		free_game(game);
	// if (!generate_map(&game))
	// 	free_game(game);
	// print_map(game->map, game->rows, game->cols);
	// if (!validate_map(game))
	// 	free_game(game);
	
	close(fd);
}