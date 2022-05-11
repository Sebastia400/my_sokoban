/*
** EPITECH PROJECT, 2021
** victor header
** File description:
** lib my_hunterexercise
*/

#ifndef LIBRAY_H_
    #define LIBRAY_H_
    #include <string.h>
    #include <stdio.h>
    #include <unistd.h>
    #include <sys/types.h>
    #include <sys/stat.h>
    #include <stddef.h>
    #include <fcntl.h>
    #include <stdlib.h>
    #include <sys/stat.h>
    #include <ctype.h>
    #include "./structs.h"
    #include <math.h>
    #include <ncurses.h>

int check_corner(s_var *all, int x, int y);
void check_if_lost2(s_var *all, int result);
int find_p(s_var *all);
int search_o(s_var *all);
int check_map(s_var *all);
int my_strlen(char const *str);
int is_on_o(s_var *all, int x, int y);
int error_handeling(s_var *all, int argc, char **argv);
char **save_map(char const *filepath, s_var *all);
void move_up(s_var *all);
void print_o(s_var *all);
void move_down(s_var *all);
void move_left(s_var *all);
void print_map(s_var *all);
void move_right(s_var *all);
void save_o_pos(s_var *all);
void check_if_lost(s_var *all);
void movements(s_var *all, int key);
void check_reset_button(s_var *all, int key);
void print_help(void);

#endif
