#include "get_next_line.h"

void	manage_rest(char **rest, size_t i)
{
	char *old_rest;

	old_rest = *rest;
	if ((*rest)[i + 1])
	{
		*rest = ft_strsub(*rest, i + 1, ft_strlen(*rest));
		ft_strdel(&old_rest);
	}
	else
		ft_strdel(rest);
}

void	manage_line(int is_join, char **line, char **rest, size_t i)
{
	char *old_line;
	char *eol;

	if (is_join)
	{
		old_line = *line;
		eol = ft_strsub(*rest, 0, i);
		*line = ft_strjoin(*line, eol);
		ft_strdel(&old_line);
		ft_strdel(&eol);
	}
	else
		*line = ft_strdup("");
	manage_rest(rest, i);
}

int		check_rest(t_get *get, char **rest, char **line)
{
	size_t	i;
	char	*tmp;

	i = -1;
	get->ret = 1;
	while (*rest && ++i < ft_strlen(*rest))
	{
		if ((*rest)[i] == '\n')
		{
			if (i == 0 && *line && ft_strlen(*line) == 0)
				manage_line(0, line, rest, i);
			else
				manage_line(1, line, rest, i);
			return (1);
		}
	}
	tmp = *line;
	*line = ft_strjoin(*line, *rest);
	if (*line == NULL)
		*line = ft_strdup(*rest);
	ft_strdel(&tmp);
	ft_strdel(rest);

	return (0);
}

void	ft_read(t_get *get, char **rest, char **line)
{
	char *buf;

	buf = ft_strnew(BUFF_SIZE);
	if (buf == NULL)
	{
		get->ret = -1;
		return ;
	}
	while ((get->ret = read(get->fd, buf, BUFF_SIZE)))
	{
		buf[get->ret] = '\0';
		*rest = ft_strjoin(*rest, buf);
		if (*rest == NULL)
			*rest = ft_strdup(buf);
		if ((get->ret < 0) || check_rest(get, rest, line))
			break ;
	}
	ft_strdel(&buf);
}

int		get_next_line(int const fd, char **line)
{
	t_get		*get;
	static char	**rest = NULL;

	if (fd < 0 || fd >= 1000 || BUFF_SIZE <= 0 || !line)
		return (-1);
	if (!(get = (t_get*)malloc(sizeof(t_get))))
		return (-1);
	get->fd = fd;
	if (rest == NULL)
		if (!(rest = (char **)malloc(sizeof(char *) * 1000)))
			return (-1);
	*line = ft_strnew(0);
	if (rest[fd] == NULL || !check_rest(get, &rest[fd], line))
		ft_read(get, &rest[fd], line);
	if (get->ret == -1)
		return (-1);
	if (get->ret == 0 && rest[fd] == NULL && *line && ft_strlen(*line) == 0)
	{
		ft_strdel(line);
		ft_memdel((void *)&get);
		return (0);
	}
	ft_memdel((void *)&get);
	return (1);
}
