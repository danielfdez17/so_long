

#include "../../inc/headers/so_long.h"

void	print_err_msg(t_bool err)
{
	if (err == PLAYER_NUMBER_ERROR)
		ft_putendl_fd(PLAYER_NUMBER_MSG, 2);
	else if (err == EXIT_NUMBER_ERROR)
		ft_putendl_fd(EXIT_NUMBER_MSG, 2);
	else if (err == COLLECTABLE_NUMBER_ERROR)
		ft_putendl_fd(COLLECTABLE_NUMBER_MSG, 2);
	else if (err == BORDER_ERROR)
		ft_putendl_fd(BORDER_MSG, 2);
	else if (err == INVALID_CHAR_ERROR)
		ft_putendl_fd(INVALID_CHAR_MSG, 2);
	else if (err == INVALID_PATH_ERROR)
		ft_putendl_fd(INVALID_PATH_MSG, 2);
	else if (err == FILE_EXTENSION_ERROR)
		ft_putendl_fd(FILE_EXTENSION_MSG, 2);
}