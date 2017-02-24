/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_ant.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmitriuc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/09 16:44:03 by mmitriuc          #+#    #+#             */
/*   Updated: 2017/02/24 16:32:28 by pcervac          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

t_lem	*make_lems(t_room **rooms, const int nr_lems)
{
	t_lem	*lems;
	int		i;
	int		start;

	i = -1;
	start = find_room_by_status_tab(rooms, START);
	lems = (t_lem*)ft_memalloc(sizeof(t_lem) * nr_lems);
	while (++i != nr_lems)
	{
		lems[i].path = NULL;
		lems[i].cam = 0;
	};
	return (lems);	
}

t_path	*get_opt_path(t_graf *graf, const int start, const int end)
{
	return (get_path(graf, start, end));
}

void	move_ant(t_lem *lems, t_graf *graf, const int nr_lems)
{
	int		i;
	int		start;
	int		end;
	int		moved;

	start = find_room_by_status_tab(graf->rooms, START);
	end = find_room_by_status_tab(graf->rooms, END);
	NULL == get_path(graf, start, end) ? error(NOCONN_ER) : DO_NONE;
	while (true)
	{
		moved = false;
		i = -1;
		while (++i != nr_lems)
		{
			lems[i].status = UNMOVED;
			if (NULL != lems[i].path && lems[i].path->dist == lems[i].cam)
			{
				graf->rooms[lems[i].path->path[lems[i].cam]]->status = FREE;
				continue ;
			}
			if (NULL == lems[i].path)
			{
				if (NULL != (lems[i].path = get_opt_path(graf, start, end)))
				{
					moved = true;
					lems[i].status = MOVED;
					lems[i].cam++;
					graf->rooms[lems[i].path->path[lems[i].cam]]->status = UNFREE;
				}
			}
			else if (FREE == graf->rooms[lems[i].path->path[lems[i].cam + 1]]->status)
			{
				moved = true;
				graf->rooms[lems[i].path->path[lems[i].cam]]->status = FREE;
				lems[i].status = MOVED;
				lems[i].cam++;
				if (lems[i].path->dist != lems[i].cam)
					graf->rooms[lems[i].path->path[lems[i].cam]]->status = UNFREE;
			}
		}
		show_rooms(lems, graf, nr_lems);	
		if (!moved)
			break ;
	}	
}
