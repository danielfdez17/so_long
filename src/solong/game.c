

#include "../../inc/headers/so_long.h"

t_pos	init_pos(int x, int y)
{
	t_pos	pos;

	pos.x = x;
	pos.y = y;
	return (pos);
}

t_game	*init_game()
{
	t_game	*game;

	game = malloc(sizeof(t_game));
	if (!game)
		return (NULL);
	game->map = NULL;
	game->player_pos = init_pos(-1, -1);
	game->exit_pos = init_pos(-1, -1);
	game->player_number = 0;
	game->exit_number = 0;
	game->collectable_number = 0;
	game->rows = 0;
	game->cols = 0;
	game->mlx = NULL;
	return (game);
}

t_bool	free_map(char **map)
{
	int	i;

	if (!map)
		return (0);
	i = 0;
	while (map && map[i])
		free(map[i++]);
	free(map);
	return (0);
}

void	free_game(t_game *game)
{
	if (game)
	{
		free_map(game->map);
		ft_lstclear(&game->list, free);
		if (game->mlx)
			mlx_terminate(game->mlx);
		free(game);
	}
}