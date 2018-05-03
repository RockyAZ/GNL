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

static char		*arr_to_str(char **res)
{
	int		i;
	char	*str;

	i = 0;
	while (res[i])
	{
		free (str);
		str = ft_join(str, res[i]);
	}
	return (str);
}

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

static char		*move_arr(char **res, int bul)
{
	int i;

	i = 0;
	while (!res[i])
		i++;
	if (res[i + 1])
		return (res[i]);
	if (!bul)
		return (NULL);
	return (res[i]);
}

static char		**reading(const int fd)
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
	return (ft_strsplit(cp, '\n'));
		free(cp);
}

int				get_next_list(const int fd, char **line)
{
	char 			*cp;
	char			**res;
	static t_list	*begin;

	if (line == NULL)
		return (-1);
	res = NULL;
	if (!ft_check_lst(&begin, fd))
	{
		if ((res = reading(fd)) == NULL)
			return (-1);
		begin->content	= arr_to_str(res);
	}
	if ((cp = move_arr(res, 0)))
	{
		*line = ft_strdup(cp);
		ft_strdel(&cp);
		return (1);
	}
	cp = strdup(move_arr(res, 1));
	*line = cp;
	ft_strdel(&cp);
	free (res);
	return (0);
}
