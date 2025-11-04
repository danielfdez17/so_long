

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

void	free_single_texture(mlx_t *mlx, t_tex_img *tex_img)
{
	mlx_delete_image(mlx, tex_img->img);
	mlx_delete_texture(tex_img->texture);
}
void	free_textures(t_game *game)
{
	int	i;
	int	j;

	i = 0;
	while (i < game->rows)
	{
		j = 0;
		while (j < game->cols)
		{
			if (game->tex_img[i][j].img)
				free_single_texture(game->mlx, &game->tex_img[i][j]);
			++j;
		}
		free(game->tex_img[i]);
		++i;
	}
	free(game->tex_img);
}

void	free_game(t_game *game)
{
	if (game)
	{
		free_map(game->map);
		ft_lstclear(&game->list, free);
		if (game->tex_img)
			free_textures(game);
		if (game->mlx)
			mlx_terminate(game->mlx);
		free(game);
	}
}