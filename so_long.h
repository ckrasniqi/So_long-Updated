

#ifndef SO_LONG_H
# define SO_LONG_H

# define PXL 32

# include "MLX42/include/MLX42/MLX42.h"
# include "libft/libft.h"
# include <fcntl.h>
# include <stdbool.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>

typedef struct s_point
{
	int				x;
	int				y;
}					t_point;

typedef struct s_game
{
	mlx_t			*mlx;
	char			**map;
	char			**map_copy;
	int				steps;
	int				rows;
	int				columns;
	int				coins_left;
	int				p_count;
	int				c_count;
	int				e_count;
	t_point			player_coords;
	mlx_image_t		*floor;
	mlx_image_t		*leprechaun;
	mlx_image_t		*exit;
	mlx_image_t		*wall;
	mlx_image_t		*coin;
}					t_game;

// Key functions

void				key_set(mlx_key_data_t paramkey, t_game *game);
void				go_up(t_game *game);
void				go_down(t_game *game);
void				go_left(t_game *game);
void				go_right(t_game *game);

// Load .png files

void				add_images(t_game *game);
void				flood_fill_floor_wall(t_game *game);
void				flood_fill_collectibles(t_game *game);

// Map reading functions

char				**read_map(char *argv);
void				check_map_validity(t_game *game);
t_point				find_player(char **map, char c);
int					check_double_nl(char *map);

// Map checking functions

int					check_walls(t_game *game);
int					check_invalid_chars(t_game *game);
int					check_valid_path(t_game *game);
void				fill_map(t_game *game, int x, int y);
int					check_elements(t_game *game);

// Map utility functions

char				*join_strings(char *buffer, char *temp);
char				**copy_map(char **map);
void				ft_flood_fill(char **map, int x, int y, t_game *game);
void				load_player(t_game *game);
void				refill_floor(t_game *game, int x, int y);

// Utility functions

void				error_exit(char *error);
int					count_rows(char **map);
int					count_columns(char **map);
void				free_arr_of_arr(char **arr);
void				free_the(t_game *game);

#endif