/* ************************************************************************** */
/*                                                                            */	
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eaqrabaw <eaqrabaw@student.42amman.com>    +#+  +:+       +#+        */	
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/16 07:11:12 by eaqrabaw          #+#    #+#             */
/*   Updated: 2025/01/16 12:02:03 by eaqrabaw         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>
#include <fcntl.h>

# define BUFFER_SIZE 1

char  *ft_strdup(char *src)
{
	char *dest;
	int i;
	i = 0;
	while (src[i])
		i++;
	dest = malloc(sizeof(char) * (i + 1));
	i = 0;
	while (src[i])
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = '\0';
	return (dest);
}
char *get_next_line(int fd)
{
	static char buffer[BUFFER_SIZE];
	char line[70000];
	static int buffer_read;
	static int buffer_pos;
	int i;
	i = 0;
	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	while (1)
	{
		if (buffer_pos >= buffer_read)
		{
			buffer_read = read(fd, buffer, BUFFER_SIZE);
			buffer_pos = 0;
			if (buffer_read <= 0)
				break ;
		}
		line[i] = buffer[buffer_pos];
		if (line[i] == '\n')
		{
			buffer_pos++;
			i++;
			break;
		}	
		buffer_pos++;	
		i++;
	}
	line[i] = '\0';
	if (i == 0)
		return (NULL);
	return (ft_strdup(line));
}

int		main(){

	int fd = open("test.txt", O_RDONLY);
	char *line;

	line = get_next_line(fd);
	printf("%s", line);
	close(fd);
	return (0);	
}