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
	sleep(4);
	puts(mlx_strerror(mlx_errno));
	exit(EXIT_FAILURE);
}

/**
 * Checks if the new rendered image has been rendered correctly
 */
void	check_rendered_img(t_game *game)
{
	if (!game->foreground[game->p_pos.x][game->p_pos.y].texture)
		error();
	game->foreground[game->p_pos.x][game->p_pos.y].img =
	mlx_texture_to_image(game->mlx, game->foreground
		[game->p_pos.x][game->p_pos.y].texture);
	if (!game->foreground[game->p_pos.x][game->p_pos.y].img)
		error();
	mlx_resize_image(game->foreground
		[game->p_pos.x][game->p_pos.y].img,
		IMG_WIDTH, IMG_HEIGHT);
	if (mlx_image_to_window(game->mlx, game->foreground
		[game->p_pos.x][game->p_pos.y].img,
		IMG_WIDTH * game->p_pos.y, IMG_HEIGHT * game->p_pos.x) < 0)
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
	render_image(&game->foreground[i][j], game->map[i][j]);
	if (!game->foreground[i][j].texture)
		error();
	game->foreground[i][j].img =
	mlx_texture_to_image(game->mlx, game->foreground[i][j].texture);
	if (!game->foreground[i][j].img)
		error();
	mlx_resize_image(game->foreground[i][j].img, IMG_WIDTH, IMG_HEIGHT);
	if (mlx_image_to_window(game->mlx, game->foreground[i][j].img,
		IMG_WIDTH * j, IMG_HEIGHT * i) < 0)
		error();
}
