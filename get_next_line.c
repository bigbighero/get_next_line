/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: roferrei <roferrei@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/22 01:00:04 by roferrei          #+#    #+#             */
/*   Updated: 2022/08/09 02:30:55 by roferrei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static char* read_txt (char *rest, int fd)
{
	char	*buffer;
	size_t	text_read;
	char	*aux;

	buffer = malloc(sizeof(char) * (BUFFER_SIZE + 1));
	while (ft_strchr(rest, '\n') == NULL)
	{
		text_read = read(fd, buffer, BUFFER_SIZE);
		buffer[text_read] = '\0';
		aux = rest;
		rest = ft_strjoin(rest, buffer);
		free(aux);
	}
	free(buffer);
	return (rest);
}

static char get_line(char *rest)
{

}

char	*get_next_line(int fd)
{
	static char	*rest;
	// char		*line;
	if (rest == NULL)
		rest = ft_strdup("");

	rest = read_txt(rest, fd);
	// line = get_line();
	return (rest);
}

int main ()
{
	int fd;
	
	fd = open("teste.txt", O_RDONLY);
	printf ("%s", get_next_line(fd));
	return (0);
}
