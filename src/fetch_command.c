/*
** EPITECH PROJECT, 2024
** fetch_display
** File description:
** fetch_display
*/

#include <fcntl.h>
#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>
#include "fetch_info.h"
#include "fetch_theme.h"
#include "functions.h"

static char *get_dash(void)
{
    char *dash = NULL;
    char *username = getenv("USER");
    char *hostname = getenv("HOSTNAME");
    int len = 0;

    if (username != NULL && hostname != NULL)
        len = strlen(username) + strlen(hostname) + 1;
    dash = malloc(sizeof(char) * (len + 1));
    for (int i = 0; i < len; ++i)
        dash[i] = '-';
    dash[len] = '\0';
    return dash;
}

static void display_fetch_info(char *color,
    size_t *i, size_t count)
{
    char *data = NULL;

    if (count > 1 && count <= 2 && *i < SIZE_FETCH_INFO) {
        dprintf(1, "\t\t\033%s%s%s@\033%s%s", color,
        getenv("USER"), DEFAULT, color,
        getenv("HOSTNAME"));
    }
    if (count > 2 && count <= 3 && *i < SIZE_FETCH_INFO) {
        data = get_dash();
        dprintf(1, "\t\t%s", data);
    }
    if (count > 3 && *i < SIZE_FETCH_INFO) {
        data = FETCH_INFO[*i].data();
        dprintf(1, "\t\t\033%s%s%s: %s", color,
        FETCH_INFO[*i].var, DEFAULT, (data != NULL ? data : "unknown"));
        *i = *i + 1;
    }
    if (data != NULL)
        free(data);
}

static void display_colors_shell(int first_color)
{
    dprintf(1, "\t\t");
    for (int i = first_color; i <= first_color + 7; ++i) {
        dprintf(1, "\033[%dm   ", i);
    }
    dprintf(1, "%s", DEFAULT);
}

static void display_fetch(char *fetch, char *color)
{
    size_t i = 0;

    for (size_t count = 0; fetch != NULL; count ++) {
        dprintf(1, "%s", fetch);
        if (count > 1 && i < SIZE_FETCH_INFO)
            display_fetch_info(color, &i, count);
        if (count == SIZE_FETCH_INFO + 5)
            display_colors_shell(40);
        if (count == SIZE_FETCH_INFO + 6)
            display_colors_shell(100);
        dprintf(1, "\n");
        fetch = strtok(NULL, "\n");
    }
}

bool fetch_command(char *filepath, char *color)
{
    char *buffer = NULL;
    char *fetch = NULL;

    buffer = create_buffer(filepath);
    if (buffer == NULL) {
        dprintf(2, "Error: File not found.\n");
        return false;
    }
    fetch = strtok(buffer, "\n");
    if (fetch == NULL)
        return false;
    display_fetch(fetch, color);
    free(buffer);
    return true;
}
