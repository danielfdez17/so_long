

#include "../../inc/headers/so_long.h"

void	print_list(t_list *list)
{
	ft_putendl_fd(__func__, 1);
	while (list)
	{
		ft_putstr_fd((const char *)list->content, 1);
		list = list->next;
	}
	ft_putendl_fd("\n", 1);
}

void	print_map(char **map, int rows)
{
	int	i;

	ft_putendl_fd(__func__, 1);
	i = 0;
	while (i < rows)
	{
		ft_putendl_fd(map[i], 1);
		i++;
	}
}

t_bool	generate_map(t_game **game)
{
	int	i;
	int	line_size;
	char	**map;
	t_list	*list;

	if (!(*game)->list)
		return (0);
	line_size = -1;
	(*game)->map = malloc(sizeof(char *) * ((*game)->list->size + 1));
	if (!(*game)->map)
		return (0);
	list = (*game)->list;
	map = (*game)->map;
	(*game)->rows = (*game)->list->size;
	(*game)->cols = (*game)->list->content_size;
	i = 0;
	while (list)
	{
		map[i] = ft_strdup((char *)list->content);
		if (!map[i])
			return (free_map(map));
		if (line_size != -1 && line_size != (int)ft_strlen(map[i]))
			return (free_map(map));
		line_size = ft_strlen(map[i]);
		++i;
		list = list->next;
	}
	map[i] = NULL;
	// print_map(map, (*game)->rows);
	return (1);
}

static t_bool	is_border(int rows, int cols, int x, int y)
{
	if (x == 0 || x == rows - 1)
		return (1);
	if (y == 0 || y == cols - 1)
		return (1);
	return (0);
}

static t_bool	is_valid_char(char c)
{
	return (c == '1' || c == '0' || c == 'E' || c == 'P' || c == 'C');
}

// ! IDEA: devolver un numero de error y asociarlo a un mensaje
t_bool	validate_map(t_game *game)
{
	int		i;
	int		j;
	char	**map;

	map = game->map;
	i = 0;
	printf("game->rows: %d, game->cols: %d\n", game->rows, game->cols);
	while (i < game->rows)
	{
		j = 0;
		while (j < game->cols)
		{
			if (!is_valid_char(map[i][j]))
				return (0);
			if (is_border(game->rows, game->cols, i, j) && map[i][j] != '1')
			{
				printf("i: %d, j: %d, char: %c (int: %d)\n", i, j, map[i][j], (int)map[i][j]);
				return (0);
			}
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
	if (game->player_number > 1 || game->exit_number > 1 ||
		game->player_number == 0 || game->exit_number == 0 ||
		game->collectable_number == 0)
		return (0);
	return (1);
}