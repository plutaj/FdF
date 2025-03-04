#include "minilibx_macos/mlx.h"
#include "get_next_line/get_next_line.h"
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include "libft/libft.h"

#define WHITE_PIX 0xFFFFFF
#define MAP_WIDTH 500
#define MAP_HEIGHT 500
#define PIXEL_DISTANCE 50

typedef struct t_map
{
    int width;
    int height;
}               s_map;

char    **parse_map(int fd, int line_count);
int     count_lines(int fd);
int     compare_len(int line_len);
int     count_points(char *line);
void    create_net(void *mlx_connection, void *mlx_window, s_map *map_size);
void    create_net_vertical(void *mlx_connection, void *mlx_window, s_map *map_size);
void    create_net_horizontal(void *mlx_connection, void *mlx_window, s_map *map_size);



