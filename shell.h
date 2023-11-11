#ifndef SHELL_H
#define SHELL_H

#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <stdbool.h>
#include <stdlib.h>

void _print_stdio(const char *print);
void prompt_entry(void);
void impliment_command(const char *order);




#endif
