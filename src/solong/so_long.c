/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danfern3 <danfern3@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/26 13:27:10 by danfern3          #+#    #+#             */
/*   Updated: 2025/11/17 07:39:32 by danfern3         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/headers/so_long.h"

/**
 * Checks if the file extension is correct.
 * If not, it @returns FALSE
 */
static t_bool	check_file_extension(char **av)
{
	char	*file_ext;

	if (!av || !av[1])
	{
		ft_putendl_fd(RED MISSING_FILE_MSG RESET, 2);
		return (FALSE);
	}
	file_ext = ft_strrchr(av[1], '.');
	if (!file_ext || ft_strncmp(file_ext, ".ber", 5) != 0)
	{
		ft_putendl_fd(RED FILE_EXTENSION_MSG RESET, 2);
		return (FALSE);
	}
	return (TRUE);
}

int	main(int ac, char **av)
{
	t_game	*game;
	int		result;

	(void)ac;
	if (!check_file_extension(av))
		return (0);
	game = read_map(av[1]);
	if (!game)
		return (0);
	result = render_game(game);
	free_game(game);
	return (result);
}
