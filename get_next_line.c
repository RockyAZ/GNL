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

static int 		ft_check_lst(t_list **begin, const int fd)
{
	t_list *first;
	t_list *cp;

	cp = *begin;
	
	while (cp)
	{
		if (cp->content_size == (size_t)fd)
		{
			*begin = cp;
			return (1);
		}
		cp = cp->next;
	}
	cp = ft_lstnew(NULL, 0);
	cp->content_size = fd;
	first = *begin;
	ft_lstadd(&first, cp);
	return (0);
}

static int		ft_del_arr(char **res)
{
	int i;

	i = 0;
	while (!res[i])
		i++;
	free(res[i]);
	res[i] = NULL;
}

static char		*move_arr(char **res)
{
	int i;

	i = 0;
	while (!res[i])
		i++;
	return (res[i]);
}

static int		size_arr(char **res)
{
	int i;

	i = 0;
	while (res[i])
		i++;
	return (i);
}

int				get_next_line(const int fd, char **line)
{
	int				ret;
	char			buf[BUFF_SIZE];
	char 			*cp;
	char			**res;
	static t_list	*begin;

	if ((fd < 0 || line == NULL || read(fd, buf, 0) < 0))
		return (-1);
	if (!ft_check_lst(&begin, fd))
	{
		while ((ret = read(fd, buf, BUFF_SIZE - 1)))
		{
			free(cp);
			buf[ret] = '\0';
			cp = ft_strjoin(cp, buf);
		}
		res = ft_strsplit(cp, '\n');
		free(cp);
		begin->content = res;
		ret = size_arr(res);
		*line = ft_strdup(move_arr(res));
		ft_del_arr(res);
	}
	return (0);
}
