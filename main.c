#include "fdf.h"

// ZATIAL PROGRAM FUNGUJE TAK ZE RATAM ZE MAPA JE ZAKONCENA NULL NA NEWLINE

int main(int argc, char **argv)
{
    void    *mlx_connection;
    void    *mlx_window;
	int fd;
    char **str;
    int line_count;

    if (argc != 2)
        exit(1);
    str = NULL;
	fd = open(argv[1], O_RDONLY);
    if (fd == -1)
        exit(1);
    line_count = count_lines(fd);
    fd = close(fd);
	fd = open(argv[1], O_RDONLY);
    if (fd == -1)
        exit(1);
    str = parse_map(fd, line_count);
    int i = 0; 
    printf("there is a %d points in 1st line", count_points(*str));
    printf("there is a %d points in 1st line", line_count);
    // test code 
    // while (str[i] != NULL)
    // {
    //     printf("%s", str[i]);
    //     i++;
    // }
    // test code
    mlx_connection = mlx_init();
    mlx_window = mlx_new_window(mlx_connection, MAP_WIDTH, MAP_HEIGHT, "FdF");
    s_map *map_size;
    map_size = (s_map *)malloc(sizeof(s_map));
    if (!map_size)
        exit(1);
    map_size->width = count_points(*str);
    map_size->height = line_count;
    create_net(mlx_connection, mlx_window, map_size);
    mlx_loop(mlx_connection);
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
// line_len += 1; because Iam counting spaces
int count_lines(int fd)
{
    char buffer[1024];
    int line_count;
    ssize_t bytes_read;
    int i;
    int line_len;

    i = 0;
    line_count = 0;
    line_len = 0;
    while ((bytes_read = read(fd, buffer, sizeof(buffer))) > 0)
    {
        while (i < bytes_read)
        {
            if (buffer[i] == '\n')
            {
                line_len++;
                line_count++;
                line_len = compare_len(line_len);
                line_len = 0;
            }
            else if (buffer[i] == ' ' || buffer[i - 1] == ' ')
                line_len++;
            i++;
        }
        i = 0;
    }
    if (bytes_read == -1)
        return (1);
    return (line_count);
}

int compare_len(int line_len)
{
    static int longest_line;

    if (line_len > longest_line)
    {
        longest_line = line_len;
        return (line_len);
    }
    return (longest_line);
}

int    count_points(char *line)
{
    int points;

    points = 0;
    while (*line)
    {
        if (*line != ' ')
        {
            points++;
            while(*line != ' ' && *line)
                line++;
        }
        while (*line == ' ' || *line == '\n')
            line++;
    }
    return (points);
}