/*
** EPITECH PROJECT, 2024
** functions
** File description:
** functions
*/

#ifndef FUNCTIONS_H_
    #define FUNCTIONS_H_

    #include <stddef.h>

    #define EXIT_ERROR -1
    #define EXIT_SUCCESS 0

    #define CONST_A (char const *const *const)

void free_array(char **array);
int my_arraylen(char const *const *const array);
char **format_arguments(char *line,
    const char *separators, const char *ignorer);

#endif /* !FUNCTIONS_H_ */
