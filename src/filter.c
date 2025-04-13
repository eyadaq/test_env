#define _GNU_SOURCE
#ifndef BUFF_SIZE
# define BUFF_SIZE 32  // default if not defined by compiler
#endif
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <errno.h> 
#include <string.h>

int		ft_strlen(char *str)
{
	int i = 0;
	while (str[i])
		i++;
	return (i);
}

void ft_filter(char *buffer, char *word)
{
	int i = 0;
	int word_len = ft_strlen(word);

	while (buffer[i])
	{
		int j = 0;

		while (buffer[i + j] && buffer[i + j] == word[j])
			j++;
		if (j == word_len)
		{
			for (int k = 0; k < word_len; k++)
				write(1, "*", 1);
			i += word_len;
			continue;
		}
		write(1, &buffer[i], 1);
		i++;
	}
}

int main(int argc, char *argv[])
{
    if (argc != 2 || ft_strlen(argv[1]) == 0)
    {
        write(2, "Usage: ./filter <word>\n", 24);
        return (1);
    }

    
    char buffer[BUFF_SIZE];
    char *input = NULL;
    int total = 0;

    ssize_t r;
    while ((r = read(0, buffer, BUFF_SIZE)) > 0)
    {
        char *new_input = realloc(input, total + r + 1);
        if (!new_input)
        {
            free(input);
            perror("malloc");
            return (1);
        }
        input = new_input;
        memmove(input + total, buffer, r);
        total += r;
        input[total] = '\0';
    }

    if (r < 0)
    {
        perror("read");
        free(input);
        return (1);
    }

    ft_filter(input, argv[1]);
    free(input);
    return (0);
}