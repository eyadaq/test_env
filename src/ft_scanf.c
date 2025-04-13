#include <unistd.h>
#include <stdarg.h>
#include <stdio.h>
#include <stdlib.h>

void 	ft_skip_whitespace(char *buffer, int *i)
{
	while (buffer[*i] == ' ' || buffer[*i] == '\t' || buffer[*i] == '\n')
		(*i)++;
}

void ft_string(char *dest, char *buffer, int *i)
{
	int j = 0;
	ft_skip_whitespace(buffer, i);
	while (buffer[*i] && buffer[*i] != ' ' && buffer[*i] != '\t' && buffer[*i] != '\n')
		dest[j++] = buffer[(*i)++];
	dest[j] = '\0';
}


void	ft_char(char *c, char *buffer, int *i)
{
	ft_skip_whitespace(buffer, i);
	*c = buffer[*i];
	(*i)++;
}

void     ft_atoi(int 	*str, char *buffer, int *i)
{
	ft_skip_whitespace(buffer, i);
	int num = 0;
	int sign = 1;

	if (buffer[*i] == '-')
	{
		sign = -1;
		(*i)++;
	}
	while (buffer[*i] >= '0' && buffer[*i] <= '9')
	{
		num = num * 10 + (buffer[*i] - '0');
		(*i)++;
	}
	(*str) = sign * num;
}

int     ft_scanf(const char *format, ...)
{
	int i = 0;
	char  buffer[1000];
	int		r = read(0, buffer, 999);
	if (r <= 0)
		return (0);
	buffer[r] = '\0';
	va_list list;
	va_start(list, format);

	while (*format){
		if (*format == '%')
		{
			if (*(format + 1) == 's')
			{
				ft_string(va_arg(list, char *), buffer, &i);
			}
			else if (*(format + 1) == 'c')
			{
				ft_char(va_arg(list, char *), buffer , &i);
			}
			else if (*(format + 1) == 'd')
			{
				ft_atoi(va_arg(list, int *), buffer, &i);
			}
			else 
			{
				printf("Unsupported Format\n");
			}
		}
		format++;
	}
	va_end(list);
	return (0);
}
int main(void)
{
    int number;
    char letter;
    char word[100];

    printf("Enter a number, a character, and a word (e.g., 42 A Hello):\n");

    // Example input: 42 A Hello
    ft_scanf("%d %c %s", &number, &letter, word);

    printf("\nResults:\n");
    printf("Integer: %d\n", number);
    printf("Character: %c\n", letter);
    printf("String: %s\n", word);

    return 0;
}