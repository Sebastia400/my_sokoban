/*
** EPITECH PROJECT, 2021
** B-PSU-200-BAR-2-1-mysokoban-sebastia.gomez-dolc
** File description:
** main.c
*/

#include "./../includes/library.h"

int error_handeling(s_var *all, int argc, char **argv)
{
    int i = -1;

    if (argc != 2)
        return (84);
    all->filename = argv[1];
    all->map = save_map(all->filename, all);
    if (all->map == NULL)
        return (84);
    i = find_p(all);
    if (i == -1)
        return (84);
    return (check_map(all));
}

int my_strlen(char const *str)
{
    int i = 0;

    while (str[i] != '\0') {
        i++;
    }
    i--;
    return (i);
}

void my_putstr(char *str)
{
    int i = 0;

    while (str[i] != '\0') {
        write(1, &str[i], 1);
        i++;
    }
}

void print_help(void)
{
    my_putstr("USAGE\n");
    my_putstr("     ./my_sokoban map\n");
    my_putstr("DESCRIPTION\n");
    my_putstr("     map  file representing the warehouse map, \
    containing ‘#’ for walls,\n");
    my_putstr("          ‘P’ for the player, ‘X’ for boxes and \
    ‘O’ for storage locations.\n");
}
