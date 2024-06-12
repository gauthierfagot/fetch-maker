/*
** EPITECH PROJECT, 2024
** main
** File description:
** main
*/

#include <stdio.h>
#include "functions.h"
#include "fetch_theme.h"

int main(int argc, char **argv)
{
    if (argc == 1)
        if (!fetch_command(DEFAULT_THEME, DEFAULT_COLOR))
            return EXIT_ERROR;
    if (argc == 2)
        if (!fetch_command(argv[1], (char *)DEFAULT))
            return EXIT_ERROR;
    if (argc == 3)
        if (!fetch_command(argv[1], argv[2]))
            return EXIT_ERROR;
    if (argc > 3) {
        dprintf(2, "Error: Invalid arguments.\n");
        return EXIT_ERROR;
    }
    return EXIT_SUCCESS;
}
