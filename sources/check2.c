/*
** EPITECH PROJECT, 2021
** B-PSU-200-BAR-2-1-mysokoban-sebastia.gomez-dolc
** File description:
** movements.c
*/

#include "./../includes/library.h"

int check_corner3(s_var *all, int x, int y, int i)
{
    if ((all->map[y][x - 1] == '#' || all->map[y][x - 1] == 'X')
    && (all->map[y - 1][x] == '#' || all->map[y - 1][x] == 'X'))
        i++;
    return (i);
}

int check_corner2(s_var *all, int x, int y, int i)
{
    if ((all->map[y][x + 1] == '#' || all->map[y][x + 1] == 'X')
    && (all->map[y + 1][x] == '#' || all->map[y + 1][x] == 'X'))
        i++;
    if ((all->map[y][x - 1] == '#' || all->map[y][x - 1] == 'X')
    && (all->map[y + 1][x] == '#' || all->map[y + 1][x] == 'X'))
        i++;
    if ((all->map[y][x + 1] == '#' || all->map[y][x + 1] == 'X')
    && (all->map[y - 1][x] == '#' || all->map[y - 1][x] == 'X'))
        i++;
    return (check_corner3(all, x, y, i));
}

int check_corner(s_var *all, int x, int y)
{
    int i = 0;

    if (all->map[y][x] == 'X') {
        all->x_nbr++;
        if (is_on_o(all, x, y) == 0) {
            return (check_corner2(all, x, y, i));
        }
    }
    return (0);
}
