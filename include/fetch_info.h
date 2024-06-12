/*
** EPITECH PROJECT, 2024
** fetch_info
** File description:
** fetch_info
*/

#ifndef FETCH_INFO_H
    #define FETCH_INFO_H
    #include <stddef.h>

    #define RESOLUTION_COMMAND "xdpyinfo | awk '/dimensions/ {print $2}'"
    #define UPTIME_PATH "/proc/uptime"
    #define HOST_PATH "/sys/devices/virtual/dmi/id/product_name"
    #define MEMORY_PATH "/proc/meminfo"
    #define OS_PATH "/etc/os-release"
    #define CPU_PATH "/proc/cpuinfo"
    #define GPU_COMMAND "lspci -mm | grep -i 'vga\\|3d\\|2d'"

char *get_os(void);
char *get_host(void);
char *get_kernel(void);
char *get_uptime(void);
char *get_shell(void);
char *get_resolution(void);
char *get_desktop_environment(void);
char *get_cpu(void);
char *get_gpu(void);
char *get_memory(void);

static const size_t SIZE_FETCH_INFO = 10;

typedef struct fetch_info_s {
    char *var;
    char *(*data)(void);
} fetch_info_t;

static const fetch_info_t FETCH_INFO[] = {
    {"OS", get_os},
    {"Host", get_host},
    {"Kernel", get_kernel},
    {"Uptime", get_uptime},
    {"Shell", get_shell},
    {"Resolution", get_resolution},
    {"DE", get_desktop_environment},
    {"CPU", get_cpu},
    {"GPU", get_gpu},
    {"Memory", get_memory}
};

#endif /* !FETCH_MODEL_H */
