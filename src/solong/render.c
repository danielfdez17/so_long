/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danfern3 <danfern3@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/30 17:59:55 by danfern3          #+#    #+#             */
/*   Updated: 2025/11/17 07:42:28 by danfern3         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

/**
 * Terminates the program when an error occurs
 */
void	error(void)
{
	puts(mlx_strerror(mlx_errno));
	exit(EXIT_FAILURE);
}

/**
 * Checks if the new rendered image has been rendered correctly
 */
void	check_rendered_img(t_game *game, t_pos pos)
{
	if (!game->fg[pos.x][pos.y].texture)
		error();
	game->fg[pos.x][pos.y].img
		= mlx_texture_to_image(game->mlx, game->fg
		[pos.x][pos.y].texture);
	if (!game->fg[pos.x][pos.y].img)
		error();
	mlx_resize_image(game->fg
	[pos.x][pos.y].img,
		IMG_WIDTH, IMG_HEIGHT);
	if (mlx_image_to_window(game->mlx, game->fg
			[pos.x][pos.y].img,
		IMG_WIDTH * pos.y, IMG_HEIGHT * pos.x) < 0)
		error();
}

void	render_movement_img(t_game *game)
{
	render_image(game->movements, EMPTY_CHAR);
	if (!game->movements->texture)
		error();
	game->movements->img
		= mlx_texture_to_image(game->mlx, game->movements->texture);
	if (!game->movements->img)
		error();
	mlx_resize_image(game->movements->img, IMG_WIDTH, IMG_HEIGHT);
	if (mlx_image_to_window(game->mlx, game->movements->img,
			IMG_WIDTH, IMG_HEIGHT) < 0)
		error();
}

/**
 * It renders a single ceil in a savely way
 */
void	render_single_ceil(t_game *game, int i, int j)
{
	render_image(&game->fg[i][j], game->map[i][j]);
	if (!game->fg[i][j].texture)
		error();
	game->fg[i][j].img
		= mlx_texture_to_image(game->mlx, game->fg[i][j].texture);
	if (!game->fg[i][j].img)
		error();
	mlx_resize_image(game->fg[i][j].img, IMG_WIDTH, IMG_HEIGHT);
	if (mlx_image_to_window(game->mlx, game->fg[i][j].img,
		IMG_WIDTH * j, IMG_HEIGHT * i) < 0)
		error();
}
