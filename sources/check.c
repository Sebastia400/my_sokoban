/*
** EPITECH PROJECT, 2021
** B-PSU-200-BAR-2-1-mysokoban-sebastia.gomez-dolc
** File description:
** movements.c
*/

#include "./../includes/library.h"

void check_if_lost2(s_var *all, int result)
{
    if (result != 0 && all->x_nbr != 0) {
        if (result / all->x_nbr >= 1)
            all->return_value = 1;
    }
}

int check_map3(char character)
{
    int i = 0;
    char *valid = "#OPX \n";

    while (valid[i] != '\0') {
        if (valid[i] == character)
            return (0);
        i++;
    }
    return (-1);
}

int check_map2(s_var *all, int x, int y)
{
    while (all->map[y][x] != '\0') {
        if (check_map3(all->map[y][x]) == -1)
            return (84);
        x++;
    }
    return (0);
}

int check_map(s_var *all)
{
    int y = 0;
    int x = 0;

    while (all->map[y] != NULL) {
        x = 0;
        if (check_map2(all, x, y) == 84)
            return (84);
        y++;
    }
    return (0);
}
