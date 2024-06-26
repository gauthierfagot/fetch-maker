/*
** EPITECH PROJECT, 2024
** fetch_hardware
** File description:
** fetch_hardware
*/

#include <fcntl.h>
#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/utsname.h>
#include "fetch_info.h"
#include "fetch_theme.h"
#include "functions.h"

static char *search_gpu(char *buffer)
{
    char **data = NULL;
    char *gpu = NULL;
    int len = 0;

    data = format_arguments(buffer, " \n", "\"");
    if (data == NULL)
        return NULL;
    if (my_arraylen(CONST_A(data)) >= 4) {
        len = strlen(data[2]) + strlen(data[3]) + 2;
        gpu = malloc(sizeof(char) * len);
        if (gpu == NULL)
            return NULL;
        sprintf(gpu, "%s %s", data[2], data[3]);
    }
    free_array(data);
    return gpu;
}

char *get_gpu(void)
{
    char *gpu = NULL;
    char *buffer = NULL;
    size_t i = 0;
    FILE *cmd = popen(GPU_COMMAND, "r");

    if (cmd == NULL)
        return NULL;
    if (getline(&buffer, &i, cmd) == -1) {
        pclose(cmd);
        return NULL;
    }
    gpu = search_gpu(buffer);
    free(buffer);
    pclose(cmd);
    return gpu;
}

static char *search_cpu(char *const *data)
{
    char *cpu = NULL;

    for (int i = 0; data[i] != NULL; i++) {
        if (strcmp(data[i], "model name") == 0 && data[i + 1] != NULL) {
            cpu = strdup(data[i + 1] + 1);
            return cpu;
        }
    }
    return cpu;
}

char *get_cpu(void)
{
    char *buffer = NULL;
    char *cpu = NULL;
    char **data = NULL;
    size_t i = 0;
    FILE *file = fopen(CPU_PATH, "r");

    if (file == NULL)
        return NULL;
    while (getline(&buffer, &i, file) != -1 && cpu == NULL) {
        data = format_arguments(buffer, ":\t\n", "");
        if (data == NULL)
            return NULL;
        cpu = search_cpu(data);
        free_array(data);
    }
    free(buffer);
    fclose(file);
    return cpu;
}

char *get_kernel(void)
{
    struct utsname name;
    char *kernel = NULL;

    uname(&name);
    kernel = strdup(name.release);
    if (kernel == NULL)
        return NULL;
    return kernel;
}

static char *search_os(char *const *data)
{
    char *os = NULL;
    bool next = false;

    for (int i = 0; data[i] != NULL; i++) {
        if (next) {
            os = strdup(data[i]);
            return os;
        }
        if (strcmp(data[i], "PRETTY_NAME") == 0)
            next = true;
    }
    return os;
}

char *get_os(void)
{
    char *buffer = NULL;
    char *os = NULL;
    char **data = NULL;

    buffer = create_buffer(OS_PATH);
    data = format_arguments(buffer, "=\"\n", "");
    if (data == NULL)
        return NULL;
    os = search_os(data);
    free_array(data);
    free(buffer);
    return os;
}
