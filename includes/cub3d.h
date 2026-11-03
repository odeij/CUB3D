#ifndef CUB3D_H
# define CUB3D_H

# include "../libft/libft.h"
# include "../minilibx/mlx.h"

# define WIN_WIDTH 1024
# define WIN_HEIGHT 768

# define TEX_NO 0
# define TEX_SO 1
# define TEX_WE 2
# define TEX_EA 3

# define KEY_W 0
# define KEY_S 1
# define KEY_A 2
# define KEY_D 3
# define KEY_LEFT 4
# define KEY_RIGHT 5

typedef struct s_config
{
	char	*tex_path[4];
	int	floor_color;
	int	ceiling_color;
}		t_config;

typedef struct s_map
{
	char	**grid;
	int	width;
	int	height;
}		t_map;

typedef struct s_player
{
	float	pos_x;
	float	pos_y;
	float	dir_x;
	float	dir_y;
	float	plane_x;
	float	plane_y;
}	t_player;

typedef struct s_img
{
	void	*ptr; //MLX opaque image pointer
	char	*addr; //raw image memory byte_by_byte
	int	bpp; // bits per pixel
	int	line_len; // number of bytes in one image row
	int	endian; //byte order information returned by mlx
	int	width;
	int	height;
}	t_img;

typedef struct s_game
{
	void		*mlx;
	void		*win;
	t_img		frame;
	t_img		textures[4];
	t_config	config;
	t_map		map;
	t_player	player;
	int		keys[8];

}	t_game;
#endif
