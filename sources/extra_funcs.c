/*
** EPITECH PROJECT, 2021
** B-PSU-200-BAR-2-1-mysokoban-sebastia.gomez-dolc
** File description:
** movements.c
*/

#include "./../includes/library.h"

void check_reset_button(s_var *all, int key)
{
    if (key == ' ') {
        all->map = save_map(all->filename, all);
        find_p(all);
    }
}

void print_map(s_var *all)
{
    int i = 0;

    while (all->map[i] != NULL) {
        mvprintw((LINES - all->map_lines) / 2 + i, (COLS -
        my_strlen(all->map[i])) / 2, all->map[i]);
        i++;
    }
}

void check_if_lost(s_var *all)
{
    int y = 0;
    int x = 0;
    int result = 0;

    all->x_nbr = 0;
    while (all->map[y] != NULL) {
        x = 0;
        while (all->map[y][x] != '\0') {
            result += check_corner(all, x, y);
            x++;
        }
        y++;
    }
    check_if_lost2(all, result);
}
