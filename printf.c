#include "main.h"

/**
 * format_parser - produces output according to a format.
 * @format: A string that contains the text to be written to stdout.
 * @args: A list of arguments to replace the format specifiers.
 *
 * Return: The number of characters printed (excluding the null byte used to
 * end output to strings).
 */
int format_parser(const char *format, va_list args)
{
	int index = 0, count = 0;
	print_func_t print_func[] = {
		{'c', print_char},
		{'s', print_string},
		{'d', print_integer},
		{'i', print_integer},
		{'%', print_percent},
		{'\0', NULL}
	};

	while (format != NULL && format[index] != '\0')
	{
		if (format[index] == '%')
		{
			index++;

			if (format[index] == '\0')
				return (-1);

			count += specifier_handler(format[index], args, print_func);
			index++;
		}
		else
		{
			_putchar(format[index]);
			count++;
			index++;
		}
	}

	return (count);
}
