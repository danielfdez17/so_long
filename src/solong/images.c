

#include "../../inc/headers/so_long.h"


#include <unistd.h>
#include <memory.h>

// static void error(void)
// {
// 	puts(mlx_strerror(mlx_errno));
// 	exit(EXIT_FAILURE);
// }

// void	my_keyhook(mlx_key_data_t keydata, void *param)
// {
// 	mlx_image_t	*img = (mlx_image_t *)param;
// 	if ((keydata.key == MLX_KEY_W || keydata.key == MLX_KEY_UP) && (keydata.action == MLX_PRESS || keydata.action == MLX_REPEAT))
// 	{
// 		puts("W key pressed!");
// 		img->instances[0].y -= 5;
// 	}
// 	if ((keydata.key == MLX_KEY_A || keydata.key == MLX_KEY_LEFT) && (keydata.action == MLX_PRESS || keydata.action == MLX_REPEAT))
// 	{
// 		puts("A key pressed!");
// 		img->instances[0].x -= 5;
// 	}
// 	if ((keydata.key == MLX_KEY_S || keydata.key == MLX_KEY_DOWN) && (keydata.action == MLX_PRESS || keydata.action == MLX_REPEAT))
// 	{
// 		puts("S key pressed!");
// 		img->instances[0].y += 5;
// 	}
// 	if ((keydata.key == MLX_KEY_D || keydata.key == MLX_KEY_RIGHT) && (keydata.action == MLX_PRESS || keydata.action == MLX_REPEAT))
// 	{
// 		puts("D key pressed!");
// 		img->instances[0].x += 5;
// 	}
// 	if (keydata.key == MLX_KEY_ESCAPE && keydata.action == MLX_PRESS)
// 	{
// 		puts("Escape key pressed!");
// 		sleep(1);
// 		// mlx_close_window(mlx);
// 	}
// }

// int32_t	main(void)
// {
// 	// Start mlx
// 	mlx_t* mlx = mlx_init(WIDTH, HEIGHT, "Test", true);
// 	if (!mlx)
// 		error();

// 	// Create a new image
// 	mlx_image_t* img = mlx_new_image(mlx, 512, 512);
// 	if (!img)
// 		error();

// 	// Set every pixel to white
// 	memset(img->pixels, 255, img->width * img->height * sizeof(int32_t));

// 	// Display an instance of the image
// 	if (mlx_image_to_window(mlx, img, 0, 0) < 0)
// 		error();

// 	mlx_key_hook(mlx, &my_keyhook, img);
// 	mlx_loop(mlx);

// 	// Optional, terminate will clean up any leftovers, this is just to demonstrate.
// 	mlx_delete_image(mlx, img);
// 	mlx_terminate(mlx);
// 	return (EXIT_SUCCESS);
// }