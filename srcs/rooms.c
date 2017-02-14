/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rooms.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcervac <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/12 18:53:04 by pcervac           #+#    #+#             */
/*   Updated: 2017/02/13 18:42:20 by pcervac          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

t_room	*find_room_by_name_list(t_list *rooms, const t_string name)
{
	t_list	*tmp;

	tmp = rooms;
	while (NULL != tmp)
	{
		if (NULL != tmp->content)
			if (ft_strequ(((t_room*)tmp->content)->name, name))
				break ;
		tmp = tmp->next;
	}
	return (NULL == tmp ? NULL : (t_room*)tmp->content);
}

t_room	*find_room_by_coord_list(t_list *rooms, const t_coord *cor)
{
	t_list	*tmp;
	t_coord	*tmp_cor;

	tmp = rooms;
	while (NULL != tmp)
	{
		if (NULL != tmp->content)
		{
			tmp_cor = ((t_room*)tmp->content)->cor;
			if (tmp_cor->x == cor->x && tmp_cor->y == cor->y)
				break ;
		}
		tmp = tmp->next;
	}
	return (NULL == tmp ? NULL : (t_room*)tmp->content);
}

t_room	*find_room_by_status_list(t_list *rooms, int status)
{
	t_list	*tmp;

	tmp = rooms;
	while (NULL != tmp)
	{
		if (NULL != tmp->content)
			if (((t_room*)tmp->content)->stat == status)
				break ;
		tmp = tmp->next;
	}
	return (NULL == tmp ? NULL : (t_room*)tmp->content);
}

t_room	*make_room(void)
{
	t_room	*room;

	room = (t_room*)ft_memalloc(sizeof(t_room));
	NULL == room ? error(strerror(errno)) : DO_NONE;	
	room->cor = (t_coord*)ft_memalloc(sizeof(t_coord));
	NULL == room->cor ? error(strerror(errno)) : DO_NONE;
	room->conns = NULL;
	return (room);
}
