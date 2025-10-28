

#include "../../inc/headers/so_long.h"

// TODO: DELETE
void	print_list(t_list *list)
{
	// TODO: DELETE
	ft_putendl_fd(__func__, 1);
	while (list)
	{
		ft_putstr_fd((const char *)list->content, 1);
		list = list->next;
	}
	ft_putendl_fd("\n", 1);
}

// TODO: DELETE
void	print_map(char **map, int rows)
{
	// TODO: DELETE
	int	i;

	ft_putendl_fd(__func__, 1);
	i = 0;
	while (i < rows)
	{
		ft_putendl_fd(map[i], 1);
		i++;
	}
}

// void	set_game(t_game **game, t_list **list, char ***map)
// {
// 	(*list) = (*game)->list;
// 	(*map) = (*game)->map;
// 	(*game)->rows = (*list)->size;
// 	(*game)->rows = (*list)->content_size;
// }

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
	// set_game(game, &list, &map);
	i = 0;
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
	print_map(map, (*game)->rows);
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
	return (c == WALL_CHAR || c == EMPTY_CHAR || c == EXIT_CHAR || c == PLAYER_CHAR || c == COLLECTABLE_CHAR);
}

static t_bool	is_error(t_game *game)
{
	if (game->player_number != 1)
		return (PLAYER_NUMBER_ERROR);
	if (game->exit_number != 1)
		return (EXIT_NUMBER_ERROR);
	if (game->collectable_number < 1)
		return (COLLECTABLE_NUMBER_ERROR);
	return (1);
}

static t_pos char_found(int i, int j, int *number)
{
	t_pos	pos;

	*number = *number + 1;
	pos.x = i;
	pos.y = j;
	return (pos);
}

// ! IDEA: devolver un numero de error y asociarlo a un mensaje
t_bool	validate_map(t_game *game)
{
	int		i;
	int		j;
	char	**map;

	map = game->map;
	i = 0;
	// printf("game->rows: %d, game->cols: %d\n", game->rows, game->cols);
	while (i < game->rows)
	{
		j = 0;
		while (j < game->cols)
		{
			if (!is_valid_char(map[i][j]))
				return (0);
			if (is_border(game->rows, game->cols, i, j) && map[i][j] != '1')
			{
				// printf("i: %d, j: %d, char: %c (int: %d)\n", i, j, map[i][j], (int)map[i][j]);
				return (BORDER_ERROR);
			}
			if (map[i][j] == 'P')
			{
				game->player_pos = char_found(i, j, &game->player_number);
				// game->player_pos = init_pos(i, j);
				// game->player_number++;
			}
			else if (map[i][j] == 'E')
			{
				game->exit_pos = char_found(i, j, &game->exit_number);
				// game->exit_pos = init_pos(i, j);
				// game->exit_number++;
			}
			else if (map[i][j] == 'C')
				game->collectable_number++;
			j++;
		}
		i++;
	}
	return (is_error(game));
}