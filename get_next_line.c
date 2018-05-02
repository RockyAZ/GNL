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

void	ft_list_push_back(t_list **begin_list, int fd)
{
	t_list *cursor;

	cursor = *begin_list;
	if (!cursor)
	{
		*begin_list = ft_lstnew(NULL, 0);
		cursor->content_size = fd;
	}
	else
	{
		while (cursor->next != NULL)
			cursor = cursor->next;
		cursor->next = ft_lstnew(NULL, 0);
		cursor->content_size = fd;
	}
}

static t_list	*ft_check_lst(t_list **begin, const int fd)
{
	t_list *cp;

	cp = *begin;
	while (cp)
	{
		if (cp->content_size == fd)
			return (cp);
		cp = cp->next;
	}
	ft_list_push_back(&cp, fd);
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
	int				ret;
	char			buf[BUFF_SIZE];
	static t_list	*begin;

	if ((fd < 0 || line == NULL || read(fd, buf, 0) < 0))
		return (-1);
	begin = ft_check_lst(&begin, fd);
	while ((ret = read(fd, buf, BUFF_SIZE)))
	{
		if (!ft_check_str(buf))
		{
			begin->content = ft_strjoin(begin->content, buf);
			free(begin->content);
		}
		else
		{
			
		}
	}
	return (1);
}
