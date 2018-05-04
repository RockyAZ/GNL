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
	cp->content_size = (size_t)fd;
	first = *begin;
	ft_lstadd(&first, cp);
	*begin = first;
	return (0);
}

static int		ft_move_end(char *begin, char **end)
{
	while (*begin != '\n' && *begin != '\0')
		begin++;
	*end = begin;
	if (*end == '\0')
		return (0);
	return (1);
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
	int				bul;

	if (line == NULL)
		return (-1);
	if (!ft_check_lst(&begin, fd))
	{
		begin->content = (void*)reading(fd);
		if (begin->content == NULL)
			return (-1);
	}
	bul = ft_move_end((char*)begin->content, &end);
	*line = ft_strsub(begin->content, 0, end - (char*)begin->content);
	begin->content = ft_strsub(end + 1, 0, ft_strlen(end));
	if (bul)
		return (1);
	return (0);
}
