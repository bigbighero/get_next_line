/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: roferrei <roferrei@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/22 01:00:04 by roferrei          #+#    #+#             */
/*   Updated: 2022/08/12 17:36:40 by roferrei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*str;

	if (!s)
		return (NULL);
	if (ft_strlen(s) < start + 1)
		return (ft_strdup(""));
	if (ft_strlen(&s[start]) < len)
		len = ft_strlen(&s[start]);
	str = (char *)malloc(sizeof(*s) * (len + 1));
	if (!str)
		return (NULL);
	ft_strlcpy(str, s + start, len + 1);
	return (str);
}

static char	*read_txt(char *rest, int fd)
{
	char	*buffer;
	ssize_t	text_read;
	char	*aux;

	buffer = malloc(sizeof(char) * (BUFFER_SIZE + 1));
	while (ft_strchr(rest, '\n') == NULL)
	{
		text_read = read(fd, buffer, BUFFER_SIZE);
		if (text_read <= 0)
			break ;
		buffer[text_read] = '\0';
		aux = rest;
		rest = ft_strjoin(rest, buffer);
		free (aux);
	}
	free (buffer);
	return (rest);
}

static void	save_me(char **rest)
{
	if (**rest == '\0')
	{
		free(*rest);
		*rest = NULL;
	}
}

static char	*get_line(char **rest)
{
	char	*i;
	char	*temp;
	char	*aux;

	i = ft_strchr(*rest, '\n');
	save_me(rest);
	if (i == NULL)
	{
		temp = *rest;
		*rest = NULL;
	}
	else
	{
		aux = *rest;
		temp = ft_substr(*rest, 0, (i - *rest + 1));
		if (i[1] != '\0')
			*rest = ft_strdup(&i[1]);
		else
			*rest = NULL;
		free(aux);
	}
	return (temp);
}

char	*get_next_line(int fd)
{
	static char	*rest[1024];
	char		*line;

	if (fd < 0 || BUFFER_SIZE <= 0) //verificar fd não existir, retornar NULL / testar se fd é arbitrário ou inexistente e retornar NULL
		return (0);
	if (rest[fd] == NULL)
		rest[fd] = ft_strdup("");
	rest[fd] = read_txt(rest[fd], fd);
	line = get_line(&rest[fd]);
	return (line);
}
