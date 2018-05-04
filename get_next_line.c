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
	
	while (*begin)
	{
		if ((*begin)->content_size == (size_t)fd)
			return (1);
		*begin = (*begin)->next;
	}
	*begin = cp;
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
		while (*end != '\n' && *end != '\0')
			end++;
	else
		while (*end == '\n')
			end++;
	return (end);
}

static char		*reading(const int fd)
{
	int		ret;
	char	buf[BUFF_SIZE];
	char 	*cp;

	cp = NULL;
	if ((fd < 0 || read(fd, buf, 0) < 0))
		return (NULL);
	while ((ret = read(fd, buf, BUFF_SIZE)))
	{
		buf[ret] = '\0';
		cp = ft_strjoin(cp, buf);
	}
	return (cp);
}

int				get_next_line(const int fd, char **line)
{
	char 			*end;
	static t_list	*begin;

	if (line == NULL)
		return (-1);
	if (!ft_check_lst(&begin, fd))
	{
		begin->content = (void*)reading(fd);
		if (begin->content == NULL)
			return (-1);
	}
	end = begin->content;
	if (*end == '\0')
		return (0);
	end = ft_move_end(end, 1);
	*line = ft_strsub(begin->content, 0, end - (char*)begin->content);
	end = ft_move_end(end, 0);
	begin->content = ft_strsub(end, 0, ft_strlen(end));
	return (1);
}
