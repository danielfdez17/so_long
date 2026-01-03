/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danfern3 <danfern3@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/07 10:17:56 by danfern3          #+#    #+#             */
/*   Updated: 2025/11/17 07:38:26 by danfern3         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	*print_and_free(t_game	*game, int err)
{
	print_err_msg(err);
	free_game(game);
	return (NULL);
}

void	print_err_msg(int err)
{
	if (err == PLAYER_NUMBER_ERROR)
		ft_putendl_fd(RED PLAYER_NUMBER_MSG RESET, 2);
	else if (err == EXIT_NUMBER_ERROR)
		ft_putendl_fd(RED EXIT_NUMBER_MSG RESET, 2);
	else if (err == COLLECTABLE_NUMBER_ERROR)
		ft_putendl_fd(RED COLLECTABLE_NUMBER_MSG RESET, 2);
	else if (err == BORDER_ERROR)
		ft_putendl_fd(RED BORDER_MSG RESET, 2);
	else if (err == INVALID_CHAR_ERROR)
		ft_putendl_fd(RED INVALID_CHAR_MSG RESET, 2);
	else if (err == INVALID_PATH_ERROR)
		ft_putendl_fd(RED INVALID_PATH_MSG RESET, 2);
	else if (err == FILE_EXTENSION_ERROR)
		ft_putendl_fd(RED FILE_EXTENSION_MSG RESET, 2);
	else if (err == LINE_NUMBER_ERROR)
		ft_putendl_fd(RED LINE_NUMBER_MSG RESET, 2);
}
