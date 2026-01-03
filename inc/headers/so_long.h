/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danfern3 <danfern3@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/27 08:12:45 by danfern3          #+#    #+#             */
/*   Updated: 2025/11/17 07:37:58 by danfern3         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include <stdio.h>
# include <stdlib.h>
# include <fcntl.h>
# include <stdbool.h>
# include "../libft/libft.h"
# include "../headers/get_next_line.h"
# include "../headers/game.h"
# include "../headers/error.h"
# include "../headers/colors.h"
# include "../MLX42/include/MLX42/MLX42.h"

# ifndef WIDTH
#  define WIDTH 512
# endif
# ifndef HEIGHT
#  define HEIGHT 512
# endif

// * FILES
t_game	*read_map(char *filename);
int		generate_list(int fd, t_game **game);

// * GAME
t_game	*init_game(void);
void	copy_game(t_game *copy, t_game *game);
t_pos	init_pos(int x, int y);
void	free_game(t_game *game);
int32_t	render_game(t_game *game);

// * MAP
int		generate_map(t_game **game);
int		validate_map(t_game **game);
void	free_single_texture(mlx_t *mlx, t_tex_img *tex_img);
int		free_map(char **map);

// * Error
void	*print_and_free(t_game	*game, int err);
void	print_err_msg(int err);

// * Validation
int		is_error(t_game *game);
int		validate_ways(t_game *game, char **map, int x, int y);
int		validate_exit(t_game *game, char **map, int x, int y);
t_pos	char_found(int i, int j, int *number);
int		is_valid_char(char c);
int		is_border(int rows, int cols, int x, int y);

// * Window / Renderization
void	render_ceils(t_game *game);
void	my_keyhook(mlx_key_data_t keydata, void *param);
void	replace_img(t_game *game, t_pos new_pos);
void	render_image(t_tex_img *tex_img, char c);
void	render_single_ceil(t_game *game, int i, int j);
void	check_rendered_img(t_game *game);
void	render_movs(t_game *game);
void	render_movs_line(t_game *game, int i, int j);

#endif