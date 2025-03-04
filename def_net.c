#include "fdf.h"

void    create_net(void *mlx_connection, 
                    void *mlx_window, s_map *map_size)
{
    create_net_horizontal(mlx_connection, mlx_window, map_size);
    create_net_vertical(mlx_connection, mlx_window, map_size);
}

void    create_net_horizontal(void *mlx_connection, void *mlx_window, s_map *map_size)
{
    int x = MAP_WIDTH * 0.1;
    int y = MAP_HEIGHT * 0.1;
    int iw = 0;
    int ih = 0;
    while (ih != map_size->height)
    {
        while (iw <= (PIXEL_DISTANCE * (map_size->width - 1)))
        {
            mlx_pixel_put(mlx_connection, mlx_window, x + iw, y + (ih * PIXEL_DISTANCE), WHITE_PIX);
            iw++;
        }
        iw = 0;
        ih++;
    }
}

void    create_net_vertical(void *mlx_connection, void *mlx_window, s_map *map_size)
{
    int x = MAP_WIDTH * 0.1;
    int y = MAP_HEIGHT * 0.1;
    int iw = 0;
    int ih = 0;
    while (iw != map_size->width)
    {
        while (ih <= (PIXEL_DISTANCE * (map_size->height - 1)))
        {
            mlx_pixel_put(mlx_connection, mlx_window, x + (iw * PIXEL_DISTANCE), y + ih, WHITE_PIX);
            ih++;
        }
        ih = 0;
        iw++;
    }
}