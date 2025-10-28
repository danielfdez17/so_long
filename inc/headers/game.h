

#ifndef GAME_H
# define GAME_H

# define PLAYER_CHAR 'P'
# define EXIT_CHAR 'E'
# define COLLECTABLE_CHAR 'C'
# define WALL_CHAR '1'
# define EMPTY_CHAR '0'

typedef struct s_pos
{
	int	x;
	int	y;
} t_pos;

typedef struct s_game
{
	char	**map;
	t_pos	player_pos;
	t_pos	exit_pos;
	t_list	*list;
	int		exit_number;
	int		player_number;
	int		collectable_number;
	int		rows;
	int		cols;
} t_game;

#endif