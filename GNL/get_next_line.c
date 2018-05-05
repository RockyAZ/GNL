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

static int		ft_check_lst(t_list **begin, const int fd)
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
	first = *begin;
	ft_lstadd(&first, cp);
	first->content_size = (size_t)fd;
	*begin = first;
	return (0);
}

static char		*ft_move_end(char *end, int bul)
{
	if (bul)
	{
		if (*end == '\n')
			end++;
		else
			while (*end != '\n' && *end != '\0')
				end++;
	}
	else
		while (*end == '\n')
			end++;
	return (end);
}

static char		*reading(const int fd)
{
	int		ret;
	char	buf[BUFF_SIZE];
	char	*res;
	char 	*cp;

	res = NULL;
	if ((read(fd, buf, 0) < 0))
		return (NULL);
	while ((ret = read(fd, buf, BUFF_SIZE)))
	{
		buf[ret] = '\0';
		cp = ft_strjoin(res, buf);
		free(res);
		res = cp;
	}
	return (res);
}

int				get_next_line(const int fd, char **line)
{
	char			*end;
	static t_list	*begin;
	t_list			*cp;

	if (line == NULL || fd < 0)
		return (-1);
	cp = begin;
	if (!ft_check_lst(&cp, fd))
	{
		begin = cp;
		begin->content = (void*)reading(fd);
		if (begin->content == NULL)
			return (-1);
	}
	end = cp->content;
	if (*end == '\0')
	{
		*line = NULL;
		return (0);
	}
	if (*end == '\n')
		*line = NULL;
	else
	{
		end = ft_move_end(end, 1);
		*line = ft_strsub(cp->content, 0, end - (char*)cp->content);
	}
	cp->content = ft_strdup(++end);

	return (1);
}
