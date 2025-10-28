

#include "../../inc/headers/so_long.h"

static t_pos	init_pos()
{
	t_pos	pos;

	pos.x = -1;
	pos.y = -1;
	return (pos);
}

t_game	*init_game()
{
	t_game	*game;

	game = malloc(sizeof(t_game));
	if (!game)
		return (NULL);
	game->map = NULL;
	game->player_pos = init_pos();
	game->exit_pos = init_pos();
	game->player_number = 0;
	game->exit_number = 0;
	game->collectable_number = 0;
	game->rows = 0;
	game->cols = 0;
	return (game);
}

t_bool	free_map(char **map)
{
	int	i;

	i = 0;
	while (map && map[i])
		free(map[i++]);
	free(map);
	return (0);
}

void	free_game(t_game *game)
{
	free_map(game->map);
	ft_lstclear(&game->list, free);
	free(game);
}