/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danfern3 <danfern3@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/07 12:50:32 by danfern3          #+#    #+#             */
/*   Updated: 2025/11/07 17:53:10 by danfern3         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/headers/so_long.h"

/**
 * Assigns the corresponding image to @param tex_img
 */
void	render_image(t_tex_img *tex_img, char c)
{
	if (c == EMPTY_CHAR)
		tex_img->texture = mlx_load_png("./images/0_grass.png");
	else if (c == WALL_CHAR)
		tex_img->texture = mlx_load_png("./images/1_bush.png");
	else if (c == PLAYER_CHAR)
		tex_img->texture = mlx_load_png("./images/P_witch_idle_single.png");
	else if (c == EXIT_CHAR)
		tex_img->texture = mlx_load_png("./images/E_exit_single.png");
	else
		tex_img->texture = mlx_load_png("./images/C_mushroom_single.png");
}

/**
 * Returns true if the new ceil is valid taking into account
 * the remaining collectables and the @param new_pos
 */
t_bool	is_valid_ceil(t_game **game, t_pos new_pos)
{
	char	**map;

	map = (*game)->map;
	if (map[new_pos.x][new_pos.y] == WALL_CHAR)
		return (FALSE);
	if (map[new_pos.x][new_pos.y] == COLLECTABLE_CHAR)
	{
		(*game)->collectable_number--;
		map[new_pos.x][new_pos.y] = EMPTY_CHAR;
	}
	else if (map[new_pos.x][new_pos.y] == EXIT_CHAR)
	{
		if ((*game)->collectable_number > 0)
			return (FALSE);
		else
			mlx_close_window((*game)->mlx);
	}
	return (TRUE);
}

/**
 * Swaps the images to simulate player's movement and update
 * the number of movements
 */
void	replace_img(t_game *game, t_pos new_pos)
{
	free_single_texture(game->mlx, &game->foreground \
		[game->p_pos.x][game->p_pos.y]);
	render_image(&game->foreground \
		[game->p_pos.x][game->p_pos.y], EMPTY_CHAR);
	check_rendered_img(game);
	game->p_pos = init_pos(new_pos.x, new_pos.y);
	game->movs++;
	ft_putnbr_fd((int)game->movs, 0);
	ft_putchar_fd('\n', 0);
	free_single_texture(game->mlx, &game->foreground \
		[game->p_pos.x][game->p_pos.y]);
	render_image(&game->foreground \
		[game->p_pos.x][game->p_pos.y], PLAYER_CHAR);
	check_rendered_img(game);
}

/**
 * Custom keyhook to control pressed keys
 */
void	my_keyhook(mlx_key_data_t keydata, void *param)
{
	t_game	*game;

	game = (t_game *)param;
	if ((keydata.key == MLX_KEY_W || keydata.key == MLX_KEY_UP)
		&& keydata.action == MLX_PRESS
		&& is_valid_ceil(&game, init_pos(game->p_pos.x - 1, game->p_pos.y)))
		replace_img(game, init_pos(game->p_pos.x - 1, game->p_pos.y));
	if ((keydata.key == MLX_KEY_A || keydata.key == MLX_KEY_LEFT)
		&& keydata.action == MLX_PRESS
		&& is_valid_ceil(&game, init_pos(game->p_pos.x, game->p_pos.y - 1)))
		replace_img(game, init_pos(game->p_pos.x, game->p_pos.y - 1));
	if ((keydata.key == MLX_KEY_S || keydata.key == MLX_KEY_DOWN)
		&& keydata.action == MLX_PRESS
		&& is_valid_ceil(&game, init_pos(game->p_pos.x + 1, game->p_pos.y)))
		replace_img(game, init_pos(game->p_pos.x + 1, game->p_pos.y));
	if ((keydata.key == MLX_KEY_D || keydata.key == MLX_KEY_RIGHT)
		&& keydata.action == MLX_PRESS
		&& is_valid_ceil(&game, init_pos(game->p_pos.x, game->p_pos.y + 1)))
		replace_img(game, init_pos(game->p_pos.x, game->p_pos.y + 1));
	if (keydata.key == MLX_KEY_ESCAPE && keydata.action == MLX_PRESS)
		mlx_close_window(game->mlx);
}

/**
 * It renders the whole map of the game
 */
void	render_ceils(t_game *game)
{
	int	i;
	int	j;

	i = 0;
	while (i < game->rows)
	{
		j = 0;
		while (j < game->cols)
		{
			render_background(game, i, j);
			render_single_ceil(game, i, j);
			++j;
		}
		++i;
	}
}
