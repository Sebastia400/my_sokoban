/*
** EPITECH PROJECT, 2021
** B-PSU-200-BAR-2-1-mysokoban-sebastia.gomez-dolc
** File description:
** movements.c
*/

#include "./../includes/library.h"

void movements(s_var *all, int key)
{
    switch (key) {
        case KEY_UP:
            move_up(all);
            break;
        case KEY_DOWN:
            move_down(all);
            break;
        case KEY_LEFT:
            move_left(all);
            break;
        case KEY_RIGHT:
            move_right(all);
            break;
    }
}

void move_up(s_var *all)
{
    if (all->map[all->p_y - 1][all->p_x] == 'X'
    && all->map[all->p_y - 2][all->p_x] != '#'
    && all->map[all->p_y - 2][all->p_x] != 'X') {
        all->map[all->p_y][all->p_x] = ' ';
        all->map[all->p_y - 1][all->p_x] = 'P';
        all->map[all->p_y - 2][all->p_x] = 'X';
    } else if (all->map[all->p_y - 1][all->p_x] == ' '
    || all->map[all->p_y - 1][all->p_x] == 'O') {
        all->map[all->p_y][all->p_x] = ' ';
        all->map[all->p_y - 1][all->p_x] = 'P';
    }
    find_p(all);
}

void move_down(s_var *all)
{
    if (all->map[all->p_y + 1][all->p_x] == 'X'
    && all->map[all->p_y + 2][all->p_x] != '#'
    && all->map[all->p_y + 2][all->p_x] != 'X') {
        all->map[all->p_y][all->p_x] = ' ';
        all->map[all->p_y + 1][all->p_x] = 'P';
        all->map[all->p_y + 2][all->p_x] = 'X';
    } else if (all->map[all->p_y + 1][all->p_x] == ' '
    || all->map[all->p_y + 1][all->p_x] == 'O') {
        all->map[all->p_y][all->p_x] = ' ';
        all->map[all->p_y + 1][all->p_x] = 'P';
    }
    find_p(all);
}

void move_left(s_var *all)
{
    if (all->map[all->p_y][all->p_x - 1] == 'X'
    && all->map[all->p_y][all->p_x - 2] != '#'
    && all->map[all->p_y][all->p_x - 2] != 'X') {
        all->map[all->p_y][all->p_x] = ' ';
        all->map[all->p_y][all->p_x - 1] = 'P';
        all->map[all->p_y][all->p_x - 2] = 'X';
    } else if (all->map[all->p_y][all->p_x - 1] == ' '
    || all->map[all->p_y][all->p_x - 1] == 'O') {
        all->map[all->p_y][all->p_x] = ' ';
        all->map[all->p_y][all->p_x - 1] = 'P';
    }
    find_p(all);
}

void move_right(s_var *all)
{
    if (all->map[all->p_y][all->p_x + 1] == 'X'
    && all->map[all->p_y][all->p_x + 2] != '#'
    && all->map[all->p_y][all->p_x + 2] != 'X') {
        all->map[all->p_y][all->p_x] = ' ';
        all->map[all->p_y][all->p_x + 1] = 'P';
        all->map[all->p_y][all->p_x + 2] = 'X';
    } else if (all->map[all->p_y][all->p_x + 1] == ' '
    || all->map[all->p_y][all->p_x + 1] == 'O') {
        all->map[all->p_y][all->p_x] = ' ';
        all->map[all->p_y][all->p_x + 1] = 'P';
    }
    find_p(all);
}
