/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danfern3 <danfern3@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/07 17:47:53 by danfern3          #+#    #+#             */
/*   Updated: 2025/11/14 10:01:15 by danfern3         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GAME_H
# define GAME_H

# include "../MLX42/include/MLX42/MLX42.h"

# define GAME_NAME "SO LOOOOOOOOOONG"
# define PLAYER_CHAR 'P'
# define EXIT_CHAR 'E'
# define COLLECTABLE_CHAR 'C'
# define WALL_CHAR '1'
# define EMPTY_CHAR '0'
# define GHOST_CHAR 'G'
# define IMG_WIDTH 64
# define IMG_HEIGHT 64

typedef struct s_pos
{
	int	x;
	int	y;
}	t_pos;

typedef struct s_tex_img
{
	mlx_texture_t	*texture;
	mlx_image_t		*img;
}	t_tex_img;

typedef struct s_game
{
	char			**map;
	t_pos			p_pos;
	t_pos			e_pos;
	t_list			*list;
	int				exit_number;
	int				player_number;
	int				collectable_number;
	int				rows;
	int				cols;
	unsigned int	movs;
	mlx_t			*mlx;
	t_tex_img		**foreground;
	t_tex_img		*movements;
	// t_tex_img		**background;
}	t_game;

#endif