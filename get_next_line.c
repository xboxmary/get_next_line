/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pallyson <pallyson@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/03 21:46:27 by pallyson          #+#    #+#             */
/*   Updated: 2021/01/05 19:25:12 by pallyson         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static int	mfree(char **tail, char **line, char *pnt)
{
	char	*tmp;

	tmp = *tail;
	free(*line);
	*pnt = '\0';
	pnt++;
	if (!(*line = ft_strdup(*tail)))
	{
		free(*tail);
		return (-1);
	}
	if (!(*tail = ft_strdup(pnt)))
	{
		free(tmp);
		free(*line);
		return (-1);
	}
	free(tmp);
	return (1);
}

static int	freetmp(char **line, char *buf)
{
	free(*line);
	free(buf);
	return (-1);
}

static int	readfile(int fd, char **line, char **tail)
{
	char	*buf;
	int		i;
	char	*pnt;
	char	*tmp;

	if (!(buf = (char *)malloc((BUFFER_SIZE + 1))))
		return (-1);
	pnt = NULL;
	while ((!pnt && (i = read(fd, buf, BUFFER_SIZE))))
	{
		buf[i] = '\0';
		if ((pnt = ft_strchr(buf, '\n')))
		{
			*pnt = '\0';
			pnt++;
			*tail = ft_strdup(pnt);
		}
		if (!(tmp = ft_strjoin(*line, buf)))
			return (freetmp(line, buf));
		free(*line);
		*line = tmp;
	}
	free(buf);
	return ((i == 0 && ft_strlen(*tail) == 0) ? 0 : 1);
}

int			get_next_line(int fd, char **line)
{
	static char *tail;
	int			res;
	char		*pnt;

	if (!line || fd < 0 || BUFFER_SIZE <= 0 || (read(fd, NULL, 0) < 0))
		return (-1);
	*line = (char *)malloc(sizeof(char));
	**line = '\0';
	if (tail)
	{
		if ((pnt = ft_strchr(tail, '\n')))
			return (mfree(&tail, line, pnt));
		else
		{
			free(*line);
			*line = ft_strdup(tail);
			free(tail);
			tail = NULL;
			res = readfile(fd, line, &tail);
		}
	}
	else
		res = readfile(fd, line, &tail);
	return (res);
}

/* int main(void)
{
    char    *line;
    int     fd;

    fd = open("text.txt", O_RDONLY);
    while (get_next_line(fd, &line) > 0)
    {
		printf("%s\n", line);
		free(line);
	}
    printf("%s\n", line);
	free(line);
} */
