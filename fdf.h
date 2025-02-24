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
    int colour;
    int x;
    int y;
    int z;
}               s_map;

char    **parse_map(int fd, int line_count);
int     line_len(const char *s);
void    create_array(int *i, char *str, char **array, int fd);
int     count_lines(int fd);
