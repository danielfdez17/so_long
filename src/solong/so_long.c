/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danfern3 <danfern3@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/26 13:27:10 by danfern3          #+#    #+#             */
/*   Updated: 2025/10/30 15:38:22 by danfern3         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/headers/so_long.h"

// int main(int ac, char **av)
// {
// 	(void)ac;
// 	char	*file_ext = NULL;
// 	if (!av || !av[1])
// 	{
// 		ft_putendl_fd(MISSING_FILE_MSG, 2);
// 		return (0);
// 	}
// 	file_ext = ft_strrchr(av[1], '.');
// 	if (!file_ext || ft_strncmp(file_ext, ".ber", 4) != 0)
// 	{
// 		ft_putendl_fd(FILE_EXTENSION_MSG, 2);
// 		return (0);
// 	}
// 	// ft_putendl_fd("Archivo correcto", 1);
// 	read_map(av[1]);
// 	return (0);
// }

// static void	ft_error(void)
// {
// 	fprintf(stderr, "%s", mlx_strerror(mlx_errno));
// 	exit(EXIT_FAILURE);
// }

// static void	ft_hook(void *param)
// {
// 	const	mlx_t* mlx = param;
// 	printf("WIDTH: %d | HEIGHT: %d\n", mlx->width, mlx->height);
// }

void	my_keyhook(mlx_key_data_t keydata, void *param)
{
	(void)param;
	if (keydata.key == MLX_KEY_W && keydata.action == MLX_PRESS)
		puts("W key pressed!");
	if (keydata.key == MLX_KEY_A && keydata.action == MLX_PRESS)
		puts("A key pressed!");
	if (keydata.key == MLX_KEY_S && keydata.action == MLX_PRESS)
		puts("S key pressed!");
	if (keydata.key == MLX_KEY_D && keydata.action == MLX_PRESS)
		puts("D key pressed!");
	if (keydata.key == MLX_KEY_UP && keydata.action == MLX_PRESS)
		puts("Up key pressed!");
	if (keydata.key == MLX_KEY_LEFT && keydata.action == MLX_PRESS)
		puts("Left key pressed!");
	if (keydata.key == MLX_KEY_DOWN && keydata.action == MLX_PRESS)
		puts("Down key pressed!");
	if (keydata.key == MLX_KEY_RIGHT && keydata.action == MLX_PRESS)
		puts("Right key pressed!");
	if (keydata.key == MLX_KEY_ESCAPE && keydata.action == MLX_PRESS)
	{
		puts("Escape key pressed!");
		sleep(1);
		exit(EXIT_SUCCESS);
	}
}

// int32_t	main(void)
// {
// 	mlx_set_setting(MLX_MAXIMIZED, true);
// 	mlx_t	*mlx = mlx_init(WIDTH, HEIGHT, "42 MLX", true);
// 	if (!mlx)
// 		ft_error();

// 	mlx_image_t	*img = mlx_new_image(mlx, WIDTH, HEIGHT);
// 	if (!img || (mlx_image_to_window(mlx, img, 0, 0) < 0))
// 		ft_error();

// 	mlx_put_pixel(img, 0, 0, 0xFF0000FF);

// 	mlx_loop_hook(mlx, ft_hook, mlx);
// 	mlx_loop(mlx);
// 	mlx_terminate(mlx);
// 	return (EXIT_SUCCESS);
// }

int32_t	main(void)
{
	mlx_t* mlx;

	if (!(mlx = mlx_init(WIDTH, HEIGHT, "MLX42", true)))
		return (EXIT_FAILURE);

	mlx_key_hook(mlx, &my_keyhook, NULL);
	mlx_loop(mlx);
	mlx_terminate(mlx);
	return (EXIT_SUCCESS);
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