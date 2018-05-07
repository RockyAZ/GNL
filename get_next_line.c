/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azaporoz <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/25 16:05:31 by azaporoz          #+#    #+#             */
/*   Updated: 2018/04/26 19:25:19 by azaporoz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static int		ft_check_str(char *str)
{
	int i;

	i = 0;
	while (str[i] != '\n' && str[i] != '\0')
		i++;
	if (str[i] == '\0')
		return (0);
	return (i);
}

static	void	ft_check_lst(t_list **begin, const int fd)
{
	t_list *cp;

	cp = *begin;
	while (cp)
	{
		if (cp->content_size == (size_t)fd)
			*begin = cp;
		cp = cp->next;
	}
	cp = ft_lstnew(NULL, 0);
	cp->content_size = (size_t)fd;
	cp->content = (int*)malloc(sizeof(int));
	*begin = cp;
}

int				get_next_line(const int fd, char **line)
{
	char			*cp;
	static t_list	*begin;
	char			buf[BUFF_SIZE];
	int				ret;
	int				i;

	if (line == NULL || fd < 0 || read(fd, buf, 0) < 0 || BUFF_SIZE <= 0)
		return (-1);
	{
		ft_check_lst(&begin, fd);
		i = (int)begin->content;
		while ((ret = read(fd, buf, BUFF_SIZE)))
		{
			buf[ret] = '\0';
			if (ft_strchr(buf, '\n') && i == 0)
			{
				cp = ft_strsub(buf, 0, ft_check_str(buf));
				cp = ft_strjoin(*line, cp);
				i--;
			}
			else
			{
				cp = ft_strjoin(*line, buf);
				begin->content++;
			}
			free(*line);
			*line = cp;
		}
	}
	return (1);
}
