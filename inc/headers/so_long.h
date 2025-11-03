/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danfern3 <danfern3@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/27 08:12:45 by danfern3          #+#    #+#             */
/*   Updated: 2025/11/03 08:53:53 by danfern3         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
// #include <math.h>
#include "../libft/libft.h"
#include "../headers/get_next_line.h"
#include "../headers/game.h"
#include "../headers/error.h"
#include "../MLX42/include/MLX42/MLX42.h"

# ifndef WIDTH
#  define WIDTH 512
# endif
# ifndef HEIGHT
#  define HEIGHT 512
# endif
# ifndef true
#  define true 1
# endif
# ifndef false
#  define false 0
# endif

typedef int	t_bool;

// Todo: DELETE DELETE DELETE
// ! TESTING FUNCTIONS
void		print_list(t_list *list);
void		print_map(char **map, int rows);

// TODO: add comments to function definitions (and to static ones also)

// * FILES
t_game		*read_map(char *filename);
t_bool		generate_list(int fd, t_game **game);

// * GAME
// ! No need to allocate memory for a t_game variable (alike t_pos)
t_game		*init_game();
t_pos		init_pos(int x, int y);
void		free_game(t_game *game);
int32_t		render_game(t_game *game);

// * MAP
t_bool		generate_map(t_game **game);
t_bool		validate_map(t_game *game);
t_bool		free_map(char **map);

// * Error
void		print_err_msg(t_bool err);

#endif