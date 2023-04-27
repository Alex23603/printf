#ifndef MAIN_H
#define MAIN_H

#include <stdarg.h>
#include <stdlib.h>
#include <unistd.h>

#define BUFF_SIZE 1024

/**
 * struct printer - Struct printer
 *
 * @t: The specifier
 * @f: The function associated
 */
typedef struct printer
{
	char t;
	int (*f)(va_list, char *, int);
} printer_t;

/* main functions */
int _printf(const char *format, ...);

/* format specifier functions */
int print_c(va_list args, char *buffer, int buff_ind);
int print_s(va_list args, char *buffer, int buff_ind);
int print_percent(va_list args, char *buffer, int buff_ind);
int print_i(va_list args, char *buffer, int buff_ind);
int print_d(va_list args, char *buffer, int buff_ind);
int print_u(va_list args, char *buffer, int buff_ind);
int print_b(va_list args, char *buffer, int buff_ind);
int print_o(va_list args, char *buffer, int buff_ind);
int print_x(va_list args, char *buffer, int buff_ind);
int print_X(va_list args, char *buffer, int buff_ind);
int print_p(va_list args, char *buffer, int buff_ind);
int print_r(va_list args, char *buffer, int buff_ind);
int print_R(va_list args, char *buffer, int buff_ind);

/* helper functions */
int handle_print(const char *format, int *i, va_list args,
	char *buffer, int flags, int width, int precision, int size);
void print_buffer(char buffer[], int *buff_ind);
int get_flags(const char *format, int *i);
int get_width(const char *format, int *i, va_list args);
int get_precision(const char *format, int *i, va_list args);
int get_size(const char *format, int *i);

#endif /* MAIN_H */ 
