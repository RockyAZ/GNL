/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_list.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azaporoz <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/25 16:05:31 by azaporoz          #+#    #+#             */
/*   Updated: 2018/04/26 19:25:19 by azaporoz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_list.h"

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

static char		*reading(const int fd)
{
	int		ret;
	char	buf[BUFF_SIZE];
	char 	*cp;


	if ((fd < 0 || read(fd, buf, 0) < 0))
		return (NULL);
	while ((ret = read(fd, buf, BUFF_SIZE - 1)))
	{
		free(cp);
		buf[ret] = '\0';
		cp = ft_strjoin(cp, buf);
	}
	return (cp);
}

static char		*ft_mover(char *begin, int bul)
{
	if (!bul)
		while (*begin != '\n')
			begin++;
	else
		while (*begin == '\n')
			begin++;
	return (begin);
}
/*ft_memset*/
int				get_next_list(const int fd, char **line)
{
	char 			*end;
	char			*start;
	static t_list	*begin;

	if (line == NULL)
		return (-1);
	res = NULL;
	if (!ft_check_lst(&begin, fd))
		if ((begin->content = reading(fd)) == NULL)
			return (-1);
	start = ft_mover(begin->content, 1);
	end = ft_mover(start, 0);
	*line = ft_strsub(start, 0, end - start);
	ft_memset(start, '\n', end - start);
	return (1);
	/*if == \0 return (0);*/
}
