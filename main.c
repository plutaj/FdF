#include "fdf.h"

int main(int argc, char **argv)
{
    // void    *mlx_connection;
    // void    *mlx_window;
    // s_map   *map_data;
	int fd;
    char **str;
    int line_count;

    str = NULL;
	fd = open(argv[1], O_RDONLY);
    line_count = count_lines(fd);
    fd = close(fd);
	fd = open(argv[1], O_RDONLY);
    if (fd == -1)
    {
        printf("Open failed");
        exit(1);
    }
    if (argc != 2)
    {
        printf("Wrong number of arguments");
        exit(1);
    }
    str = parse_map(fd, line_count);
    int i = 0;
    while (str[i] != NULL)
    {
        printf("%s", str[i]);
        i++;
    }
    // mlx_connection = mlx_init();
    // mlx_window = mlx_new_window(mlx_connection, 500, 500, "My 1 win");
    // map_data = NULL;
    // mlx_loop(mlx_connection);
    return (0);
}

char **parse_map(int fd, int line_count)
{
    int     i;
    char    *str;
    char    **array;

    i = 0;
    str = get_next_line(fd);
    array = NULL;
    printf("file has %d lines\n", line_count);
    array = (char **)malloc(line_count * sizeof(char *));
    if (!array)
        free(array);
    while (str != NULL)
    {
        array[i] = str;
        i++;
        str = get_next_line(fd);
    }
    return (array);
}

// zisti ci file konci na novom riadku alebo na konci stringu
int count_lines(int fd)
{
    char buffer[1024];
    int line_count = 0;
    ssize_t bytes_read;
    int i = 0;

    while ((bytes_read = read(fd, buffer, sizeof(buffer))) > 0)
    {
        while (i < bytes_read)
        {
            if (buffer[i] == '\n')
                line_count++;
            i++;
        }
        i = 0;
    }
    if (bytes_read == -1)
    {
        perror("Error reading file");
        return (1);
    }
    return (line_count);
}