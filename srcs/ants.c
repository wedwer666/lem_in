/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ants.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcervac <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/23 16:18:10 by pcervac           #+#    #+#             */
/*   Updated: 2017/02/24 18:36:11 by pcervac          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

void	show_rooms(t_lem *lems, t_graf *graf, const int nr_lems)
{
	int i;
	int	moved;

	i = -1;
	moved = false;
	while (++i < nr_lems)
	{
		if (lems[i].status == MOVED)
		{
			ft_printf("%cL%d-%s", moved ? ' ' : '\0', i + 1,
					graf->rooms[lems[i].path->path[lems[i].cam]]->name);
			moved = true;
		}
	}
	ft_putendl("");
}

t_room	*make_room(void)
{
	t_room	*room;

	room = (t_room*)ft_memalloc(sizeof(t_room));
	NULL == room ? error(strerror(errno)) : DO_NONE;
	room->cor = (t_coord*)ft_memalloc(sizeof(t_coord));
	NULL == room->cor ? error(strerror(errno)) : DO_NONE;
	room->conns = NULL;
	room->status = FREE;
	return (room);
}
