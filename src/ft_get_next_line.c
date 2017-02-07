/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_next_line.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmitriuc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/06 14:38:09 by mmitriuc          #+#    #+#             */
/*   Updated: 2017/02/07 14:20:09 by mmitriuc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"
#include <stdlib.h>
#include <unistd.h>
#include "get_next_line.h"

static t_list	*ft_find(t_list **begin, int fd)
{
	t_list *tmp;

	tmp = *begin;
	if (tmp)
	{
		while (tmp)
		{
			if (fd == (int)tmp->content_size)
				return (tmp);
			tmp = tmp->next;
		}
	}
	tmp = ft_lstnew("\0", 1);
	tmp->content_size = fd;
	ft_lstadd(begin, tmp);
	return (tmp);
}

static char		*ft_delete(char *str, char *buff, int ret)
{
	char *tmp;

	tmp = str;
	str = ft_strnjoin(str, buff, ret);
	free(tmp);
	return (str);
}

int				get_next_line(int const fd, char **line)
{
	char			buff[BUFF_SIZE + 1];
	int				i;
	static t_list	*list = NULL;
	t_list			*begin;
	char			*tmp;

	if (fd < 0 || line == NULL || read(fd, buff, 0))
		return (-1);
	begin = list;
	list = ft_find(&begin, fd);
	while (!ft_strchr(list->content, '\n') && (i = read(fd, buff, BUFF_SIZE)))
		list->content = ft_delete(list->content, buff, i);
	i = 0;
	while (((char *)list->content)[i] && ((char *)list->content)[i] != '\n')
		++i;
	*line = ft_strndup(list->content, i);
	if (((char *)list->content)[i] == '\n')
		++i;
	tmp = list->content;
	list->content = ft_strdup(list->content + i);
	free(tmp);
	list = begin;
	return (i ? 1 : 0);
}
