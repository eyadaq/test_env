#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <errno.h> 

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

int 	main(int argc , char *argv[])
{
	if (argc != 2)
	{
		return (1);
	}
	char buffer[10000];
	int read_bytes = read(0, buffer, 9999);
	if (read_bytes <= 0)
	{
		perror("read");
		return (1);
	}
	buffer[read_bytes] = '\0';
	int i = ft_strlen(argv[1]);
	if (i > read_bytes || i == 0)
		return (1);
	ft_filter(buffer , argv[1]);
	return (0);
}