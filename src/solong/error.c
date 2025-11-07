/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danfern3 <danfern3@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/07 10:17:56 by danfern3          #+#    #+#             */
/*   Updated: 2025/11/07 10:18:00 by danfern3         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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
