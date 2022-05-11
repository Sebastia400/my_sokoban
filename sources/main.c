/*
** EPITECH PROJECT, 2021
** B-PSU-200-BAR-2-1-mysokoban-sebastia.gomez-dolc
** File description:
** main.c
*/

#include "./../includes/library.h"

static void init_window(void)
{
    initscr();
    keypad(stdscr, TRUE);
    noecho();
    curs_set(0);
}

s_var *init_struct(void)
{
    s_var *all = malloc(sizeof(s_var));

    all->p_x = 0;
    all->p_x = 0;
    all->map = NULL;
    all->o_nbr = 0;
    all->return_value = 2;
    all->filename = NULL;
    all->x_nbr = 0;
    return (all);
}

void my_sokoban2(s_var *all)
{
    int key = -1;

    print_o(all);
    print_map(all);
    key = getch();
    check_reset_button(all, key);
    movements(all, key);
    search_o(all);
    if (all->return_value != 0)
        check_if_lost(all);
}

void my_sokoban(s_var *all)
{
    char *str = NULL;

    while (all->return_value != 1 && all->return_value != 0) {
        clear();
        if (LINES >= all->map_lines && COLS >= my_strlen(all->map[0])) {
            my_sokoban2(all);
        } else {
            str = "Window too small, please resize it";
            mvprintw(LINES / 2, (COLS - my_strlen(str)) / 2, str);
        }
        refresh();
    }
    clear();
    print_map(all);
    refresh();
}

int main(int argc, char **argv)
{
    int i = 0;
    s_var *all = NULL;

    if (argc > 1) {
        if (argv[1][0] == '-' && argv[1][1] == 'h') {
            print_help();
            return (0);
        }
    }
    all = init_struct();
    if (error_handeling(all, argc, argv) == 84)
        return (84);
    save_o_pos(all);
    init_window();
    my_sokoban(all);
    endwin();
    return (all->return_value);
}
