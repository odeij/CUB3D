#include "cub3d.h"

int	main(int ac, char **av)
{
	t_game	game;

	(void)ac;
	(void)av;
	ft_bzero(&game, sizeof(game));
	game.config.floor_color = -1;
	game.config.ceiling_color = -1;
	game.mlx = mlx_init();
	if (game.mlx == NULL)
	{
		printf("Error\nFailed to initialize MLX\n");
		return (1);
	}
	game.win = mlx_new_window(game.mlx, WIN_WIDTH, WIN_HEIGHT, "cub3d");
	if (game.win == NULL)
	{
		mlx_destroy_display(game.mlx);
		free(game.mlx);
		printf("Error\nFailed to create window\n");
		return (1);
	}
	mlx_loop(game.mlx);
	return (0);
}
