

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

void	print_map(char **map, int rows, int cols)
{
	int	i;
	int	j;

	i = 0;
	while (i < rows)
	{
		j = 0;
		while (j < cols)
		{
			ft_putchar_fd(map[i][j], 1);
			j++;
		}
		ft_putchar_fd('\n', 1);
		i++;
	}
	ft_putchar_fd('\n', 1);
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
	return (1);
}

static int	is_border(int rows, int cols, int x, int y)
{
	if (x == 0 || x == rows - 1)
		return (1);
	if (y == 0 || y == cols - 1)
		return (1);
	return (0);
}

t_bool	validate_map(t_game *game)
{
	int		i;
	int		j;
	char	**map;

	map = game->map;
	i = 0;
	while (map && map[i][j] && i < game->rows)
	{
		j = 0;
		while (map && map[i][j] && j < game->cols)
		{
			if (is_border(game->rows, game->cols, i, j) && map[i][j] != '1')
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
	return (1);
}