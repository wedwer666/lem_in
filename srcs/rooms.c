/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rooms.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcervac <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/12 18:53:04 by pcervac           #+#    #+#             */
/*   Updated: 2017/02/24 18:36:15 by pcervac          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

int		find_room_by_status_tab(t_room **rooms, t_status status)
{
	int		i;

	i = 0;
	while (NULL != rooms[i])
		if (rooms[i++]->type == status)
			return (i - 1);
	return (-1);
}

int		find_room_by_name_tab(t_room **rooms, const t_string name)
{
	int		i;

	i = 0;
	while (NULL != rooms[i])
		if (ft_strequ(rooms[i++]->name, name))
			return (i - 1);
	return (-1);
}

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
			if (((t_room*)tmp->content)->type == status)
				break ;
		tmp = tmp->next;
	}
	return (NULL == tmp ? NULL : (t_room*)tmp->content);
}
