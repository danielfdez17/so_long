/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danfern3 <danfern3@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/07 15:00:21 by danfern3          #+#    #+#             */
/*   Updated: 2025/11/10 17:54:03 by danfern3         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/headers/so_long.h"

t_bool	free_map(char **map)
/**
 * Frees the memory allocated by the @param map
 */
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

/**
 * Frees the memory allocated by a single texture @param tex_img
 */
void	free_single_texture(mlx_t *mlx, t_tex_img *tex_img)
{
	if (!tex_img)
		return ;
	mlx_delete_image(mlx, tex_img->img);
		mlx_delete_texture(tex_img->texture);
}

/**
 * Frees the map of textures used to render the map given to main function
 */
void	free_textures(t_game *game)
{
	int	i;
	int	j;

	i = 0;
	if (!game->mlx)
		return ;
	while (i < game->rows)
	{
		j = 0;
		while (j < game->cols)
		{
			if (game->foreground[i][j].img)
				free_single_texture(game->mlx, &game->foreground[i][j]);
			if (game->background[i][j].img && game->background[i][i].img)
				free_single_texture(game->mlx, &game->background[i][j]);
			++j;
		}
		if (game->foreground)
			free(game->foreground[i]);
		if (game->background)
			free(game->background[i]);
		++i;
	}
	free(game->foreground);
	free(game->background);
}

/**
 * Frees the whole memory allocated needed to the program to run properly.
 */
void	free_game(t_game *game)
{
	if (game)
	{
		free_map(game->map);
		if (game->list)
			ft_lstclear(&game->list, free);
		// if (game->movements)
		// {
		// 	// mlx_delete_image(game->mlx, game->movements);
		// 	free(game->movements);
		// }
		// if (game->background && game->background[game->rows])
		if (game->foreground)
			free_textures(game);
		if (game->mlx)
			mlx_terminate(game->mlx);
		free(game);
	}
}
