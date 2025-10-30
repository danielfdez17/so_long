
#include "../../inc/headers/so_long.h"

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