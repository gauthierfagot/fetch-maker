/*
** EPITECH PROJECT, 2024
** fetch_theme
** File description:
** fetch_theme
*/

#ifndef FETCH_THEME_H
    #define FETCH_THEME_H

    #include <stddef.h>
    #include <stdbool.h>

    #define DEFAULT_THEME "assets/fetch_logo/camille.txt"
    #define DEFAULT_COLOR "\033[38;2;6;178;255m"

static const char DEFAULT[] = "\033[0m";

bool fetch_command(char *filepath, char *color);
char *create_buffer(char *filepath);

#endif /* !FETCH_THEME_H */
