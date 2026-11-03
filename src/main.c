#include "cub3d.h"

/*
the high level flow will go through main() -> parse_scene() -> init_game() -> setup_hooks() -> mlx_loop()
for main the mental model is:
create t_game -> initalize its fields -> initialize mlx -> create window -> enter mlx_loop
*/
int main(int ac, char **av)
{
  t_game  game;

  (void)ac;
  (void)av;

  ft_bzero(&game, sizeof(game));
  game.config.floor_color = -1;
  game.config.ceiling_color = -1;
  game.mlx = mlx_init();

  if (!game.mlx)
  {
    //error and cleanup path
    printf("Failed to initialize MLX\n");
    return (1);
  }
  game.win = mlx_new_window(game.mlx, WIN_WIDTH, WIN_HEIGHT, "cub3D");
  if (!game.win)
  {
    printf("Failed to create window\n");
    return (1);
    //handle the failure
  }

