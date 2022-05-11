/*
** EPITECH PROJECT, 2021
** B-PSU-200-BAR-2-1-mysokoban-sebastia.gomez-dolc
** File description:
** movements.c
*/

#include "./../includes/library.h"

int search_o2(s_var *all, int x, int y)
{
    while (all->map[y][x] != '\0') {
        if (all->map[y][x] == 'X' && is_on_o(all, x, y) == 0)
            return (1);
        x++;
    }
    return (0);
}

int search_o(s_var *all)
{
    int y = 0;
    int x = 0;

    while (all->map[y] != NULL) {
        x = 0;
        if (search_o2(all, x, y) == 1)
            return (0);
        y++;
    }
    all->return_value = 0;
    return (0);
}

int find_p2(s_var *all)
{
    while (all->map[all->p_y][all->p_x] != '\0') {
        if (all->map[all->p_y][all->p_x] == 'P')
            return (1);
        all->p_x++;
    }
    return (0);
}

int find_p(s_var *all)
{
    all->p_y = 0;
    while (all->map[all->p_y] != NULL) {
        all->p_x = 0;
        if (find_p2(all) == 1)
            return (0);
        all->p_y++;
    }
    return (-1);
}
