/*
** EPITECH PROJECT, 2021
** BSQ_mio
** File description:
** save_map.c
*/

#include "./../includes/library.h"

int is_on_o(s_var *all, int x, int y)
{
    int i = 0;

    while (i < all->o_nbr) {
        if (x == all->o_pos[i][0] && y == all->o_pos[i][1])
            return (1);
        i++;
    }
    return (0);
}

int ext_save_o_pos(s_var *var, int x, int y, int i)
{
    if (var->map[y][x] == 'O') {
        var->o_pos[i] = malloc(sizeof(int) * 2);
        var->o_pos[i][0] = x;
        var->o_pos[i][1] = y;
        i++;
    }
    return (i);
}

void save_o_pos(s_var *var)
{
    int y = 0;
    int x = 0;
    int i = 0;

    var->o_pos = malloc(sizeof(int *) * 100);
    while (var->map[y] != NULL) {
        x = 0;
        while (var->map[y][x] != '\0') {
            i = ext_save_o_pos(var, x, y, i);
            x++;
        }
        y++;
    }
    var->o_nbr = i;
}

void print_o(s_var *all)
{
    int i = 0;
    int x = 0;
    int y = 0;

    while (i < all->o_nbr) {
        x = all->o_pos[i][0];
        y = all->o_pos[i][1];
        if (all->map[y][x] == ' ')
            all->map[y][x] = 'O';
        i++;
    }
}

char **save_map(char const *filepath, s_var *all)
{
    int i = 0;
    char **map = malloc(sizeof(char *) * 100);
    size_t line_buf_size = 0;
    ssize_t line_size;
    FILE *fp = fopen(filepath, "r");

    if (!fp)
        return NULL;
    map[i] = malloc(sizeof(char) * 100);
    line_size = getline(&map[i], &line_buf_size, fp);
    while (line_size >= 0) {
        map[i + 1] = malloc(sizeof(char) * 100);
        line_buf_size = 0;
        line_size = getline(&map[i + 1], &line_buf_size, fp);
        i++;
    }
    all->map_lines = i;
    map[i] = NULL;
    fclose(fp);
    return (map);
}
