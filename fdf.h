#include "minilibx_macos/mlx.h"
#include "get_next_line/get_next_line.h"
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include "libft/libft.h"

typedef struct t_map
{
    int width;
    int height;
}               s_map;

char    **parse_map(int fd, int line_count);
int     line_len(const char *s);
int     count_lines(int fd);
int     compare_len(int line_len);
void    init_map_data(s_map **map_data, int height, int width);

