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

static t_list	*ft_check_lst(t_list **begin, const int fd)
{
	t_list *cp;
	t_list *first;

	cp = *begin;
	while (cp)
	{
		if (cp->content_size == (size_t)fd)
			return (cp);
		cp = cp->next;
	}
	first = *begin;
	cp = ft_lstnew(NULL, 0);
	cp->content_size = fd;
	ft_lstadd(&first, cp);
	return (cp);
}

static int		ft_check_str(char *str)
{
	int		i;
	char	*pr;

	i = 0;
	pr = str;
	while (i < BUFF_SIZE && *pr != '\0')
	{
		if (*pr == '\n' || *pr == '\0')
			return (i);
		pr++;
		i++;
	}
	return (0);
}

int				get_next_line(const int fd, char **line)
{
	int				i;
	int				ret;
	char			*cp;
	char			buf[BUFF_SIZE];
	static t_list	*begin;

	if ((fd < 0 || line == NULL || read(fd, buf, 0) < 0))
		return (-1);
	begin = ft_check_lst(&begin, fd);
	while ((ret = read(fd, buf, BUFF_SIZE - 1)))
	{
		buf[ret] = '\0';
		if (!(i = ft_check_str(buf)))
		{
			begin->content = ft_strjoin(begin->content, buf);
		}
		else
		{
			cp = ft_strnew(i);
			cp = ft_strncpy(cp, buf, i);
			begin->content = ft_strjoin(begin->content, cp);
			*line = begin->content;
			free (cp);
			return (1);
		}
	}
	return (0);
}
