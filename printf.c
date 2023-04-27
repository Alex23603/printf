#include "main.h"

void print_buffer(char buf[], int *buf_idx);

/**
 * _printf - Produces output according to a format string.
 * @format: The format string.
 * Return: The number of characters printed.
 */
int _printf(const char *format, ...)
{
	int i, printed = 0, chars_printed = 0;
	int flags, width, precision, size, buf_idx = 0;
	va_list args;
	char buf[BUFF_SIZE];

	if (format == NULL)
		return (-1);

	va_start(args, format);

	for (i = 0; format && format[i] != '\0'; i++)
	{
		if (format[i] != '%')
		{
			buf[buf_idx++] = format[i];
			if (buf_idx == BUFF_SIZE)
				print_buffer(buf, &buf_idx);
			chars_printed++;
		}
		else
		{
			print_buffer(buf, &buf_idx);
			flags = get_flags(format, &i);
			width = get_width(format, &i, args);
			precision = get_precision(format, &i, args);
			size = get_size(format, &i);
			++i;
			printed = handle_print(format, &i, args, buf,
				flags, width, precision, size);
			if (printed == -1)
				return (-1);
			chars_printed += printed;
		}
	}

	print_buffer(buf, &buf_idx);

	va_end(args);

	return (chars_printed);
}

/**
 * print_buffer - Prints the contents of a buffer if it is not empty.
 * @buf: The buffer to print.
 * @buf_idx: A pointer to the current index of the buffer.
 */
void print_buffer(char buf[], int *buf_idx)
{
	if (*buf_idx > 0)
		write(1, &buf[0], *buf_idx);

	*buf_idx = 0;
}
