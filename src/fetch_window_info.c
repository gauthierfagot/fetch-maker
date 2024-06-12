/*
** EPITECH PROJECT, 2024
** fetch_window_info
** File description:
** fetch_window_info
*/

#include <fcntl.h>
#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include "fetch_info.h"
#include "fetch_theme.h"
#include "functions.h"

char *get_desktop_environment(void)
{
    char *desktop_environment = NULL;
    char *data = getenv("XDG_CURRENT_DESKTOP");

    if (data == NULL)
        return NULL;
    desktop_environment = strdup(data);
    if (desktop_environment == NULL)
        return NULL;
    return desktop_environment;
}

char *get_resolution(void)
{
    char *resolution = NULL;
    char *buffer = NULL;
    char **data = NULL;
    size_t i = 0;
    FILE *cmd = popen(RESOLUTION_COMMAND, "r");

    if (cmd == NULL || getline(&buffer, &i, cmd) == -1)
        return NULL;
    data = format_arguments(buffer, "\n ", "");
    if (data == NULL)
        return NULL;
    resolution = strdup(data[0]);
    free(buffer);
    free_array(data);
    pclose(cmd);
    return resolution;
}
