/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azaporoz <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/09 20:15:12 by azaporoz          #+#    #+#             */
/*   Updated: 2018/05/09 20:15:13 by azaporoz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

void	ft_refresh(char **res, size_t i)
{
	char *old_res;

	old_res = *res;
	if ((*res)[i + 1])
	{
		*res = ft_strsub(*res, i + 1, ft_strlen(*res));
		ft_strdel(&old_res);
	}
	else
		ft_strdel(res);
}

void	ft_solver(int is_join, char **line, char **res, size_t i)
{
	char *old_line;
	char *eol;

	if (is_join)
	{
		old_line = *line;
		eol = ft_strsub(*res, 0, i);
		*line = ft_strjoin(*line, eol);
		ft_strdel(&old_line);
		ft_strdel(&eol);
	}
	else
		*line = ft_strdup("");
	ft_refresh(res, i);
}

int		check_res(t_line *get, char **res, char **line)
{
	size_t	i;
	char	*tmp;

	i = -1;
	get->err = 1;
	while (*res && ++i < ft_strlen(*res))
	{
		if ((*res)[i] == '\n')
		{
			if (i == 0 && *line && ft_strlen(*line) == 0)
				ft_solver(0, line, res, i);
			else
				ft_solver(1, line, res, i);
			return (1);
		}
	}
	tmp = *line;
	*line = ft_strjoin(*line, *res);
	if (*line == NULL)
		*line = ft_strdup(*res);
	ft_strdel(&tmp);
	ft_strdel(res);
	return (0);
}

void	ft_read(t_line *get, char **res, char **line)
{
	char *buf;

	buf = ft_strnew(BUFF_SIZE);
	if (buf == NULL)
	{
		get->err = -1;
		return ;
	}
	while ((get->err = read(get->fd, buf, BUFF_SIZE)))
	{
		buf[get->err] = '\0';
		*res = ft_strjoin(*res, buf);
		if (*res == NULL)
			*res = ft_strdup(buf);
		if ((get->err < 0) || check_res(get, res, line))
			break ;
	}
	ft_strdel(&buf);
}

int		get_next_line(int const fd, char **line)
{
	t_line		*get;
	static char	**res = NULL;

	if (fd < 0 || fd >= 1000 || BUFF_SIZE <= 0 || !line)
		return (-1);
	if (!(get = (t_line*)malloc(sizeof(t_line))))
		return (-1);
	get->fd = fd;
	if (res == NULL)
		if (!(res = (char **)malloc(sizeof(char *) * 1000)))
			return (-1);
	*line = ft_strnew(0);
	if (res[fd] == NULL || !check_res(get, &res[fd], line))
		ft_read(get, &res[fd], line);
	if (get->err == -1)
		return (-1);
	if (get->err == 0 && res[fd] == NULL && *line && ft_strlen(*line) == 0)
	{
		ft_strdel(line);
		ft_memdel((void *)&get);
		return (0);
	}
	ft_memdel((void *)&get);
	return (1);
}
