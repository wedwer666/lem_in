/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   array.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcervac <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/08 19:05:12 by pcervac           #+#    #+#             */
/*   Updated: 2017/02/13 20:54:30 by pcervac          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

void    del(void *content, size_t content_size)
{
	content || content_size ? DO_NONE : DO_NONE;
}

void	make_ad_matr(t_input *inp)
{
	int		i;

	inp->ad_matr = (int**)ft_memalloc(sizeof(int*) * inp->nr_rooms);
	NULL == inp->ad_matr ? error(strerror(errno)) : DO_NONE;
	i = 0;
	while (i != inp->nr_lems)
		inp->ad_matr[i++] = (int*)ft_memalloc(sizeof(int) * inp->nr_rooms);
}

void	list_to_array(t_input *inp)
{
	t_room	**rooms;
	t_list	*tmp;
	int		i;

	rooms = (t_room**)ft_memalloc(sizeof(t_room) * (inp->nr_rooms + 1));
	NULL == rooms ? error(strerror(errno)) : DO_NONE;
	i = 0;
	tmp = inp->rooms_list;
	while (NULL != tmp)
	{
		rooms[i++] = (t_room*)tmp->content;
		tmp = tmp->next;
	}
	ft_lstdel(&inp->rooms_list, del);
	inp->rooms_tab = rooms;
}
