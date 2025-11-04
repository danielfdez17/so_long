/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danfern3 <danfern3@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/26 13:27:10 by danfern3          #+#    #+#             */
/*   Updated: 2025/11/04 10:38:50 by danfern3         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/headers/so_long.h"

static t_bool	check_file_extension(char **av)
{
	char	*file_ext;

	if (!av || !av[1])
	{
		ft_putendl_fd(MISSING_FILE_MSG, 2);
		return (false);
	}
	file_ext = ft_strrchr(av[1], '.');
	if (!file_ext || ft_strncmp(file_ext, ".ber", 5) != 0)
	{
		ft_putendl_fd(FILE_EXTENSION_MSG, 2);
		return (false);
	}
	return (true);
}

int main(int ac, char **av)
{
	t_game	*game;
	int		result;

	while (true)
		malloc(sizeof(t_game *) * WIDTH);
	(void)ac;
	if (!check_file_extension(av))
		return (0);
	game = read_map(av[1]);
	// result = render_game(game);
	free_game(game);
	return (result);
}

// ! DEBUGGING/TESTING MAIN
// int	main(void)
// {
// 	// read_map("./files/bad_extension.berro");
// 	// read_map("./files/border_error.ber");
// 	// read_map("./files/collectable_number_error.ber");
// 	// read_map("./files/exit_number_error.ber");
// 	// read_map("./files/invalid_char_error.ber");
// 	// read_map("./files/player_number_error.ber");
//  read_map("./files/test.ber");
// 	return (0);
// }