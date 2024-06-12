/*
** EPITECH PROJECT, 2024
** used_functions
** File description:
** used_functions
*/

#include <stdlib.h>
#include <stdio.h>
#include <stddef.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>

static int buffer_size(char const *filepath)
{
    struct stat sb;

    if (stat(filepath, &sb) == -1) {
        perror("stat");
        return -1;
    }
    return sb.st_size;
}

char *create_buffer(char *filepath)
{
    int buf_size = 0;
    char *buffer = NULL;
    int file = open(filepath, O_RDONLY);

    if (file == -1)
        return NULL;
    buf_size = buffer_size(filepath);
    if (buf_size == -1)
        return NULL;
    buffer = malloc(sizeof(char) * (buf_size + 1));
    if (buffer == NULL)
        return NULL;
    if (read(file, buffer, buf_size) == -1)
        return NULL;
    buffer[buf_size] = '\0';
    close(file);
    return buffer;
}

void free_array(char **array)
{
    if (array == NULL)
        return;
    for (int i = 0; array[i] != NULL; i++)
        free(array[i]);
    free(array);
}

int my_arraylen(char const *const *const array)
{
    int i = 0;

    if (array == NULL)
        return 0;
    for (i = 0; array[i] != NULL; i++);
    return i;
}
