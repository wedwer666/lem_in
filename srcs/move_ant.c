/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_ant.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmitriuc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/09 16:44:03 by mmitriuc          #+#    #+#             */
/*   Updated: 2017/02/24 20:14:31 by pcervac          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

#define GET_CAM1		arg->lems[arg->i].cam
#define GET_ROOM1		arg->lems[arg->i].path->path[GET_CAM1]	
#define GET_ROOM_STAT1  arg->graf->rooms[GET_ROOM1]->status

#define GET_CAM2		arg.lems[arg.i].cam
#define GET_ROOM2		arg.lems[arg.i].path->path[GET_CAM2]	
#define GET_ROOM_STAT2  arg.graf->rooms[GET_ROOM2]->status

#define GET_ROOM3		arg->lems[arg->i].path->path[GET_CAM1 + 1]
#define GET_NRS			arg->graf->rooms[GET_ROOM3]->status

#define GET_INT2(...)	int __VA_ARGS__
#define GET_MOVE_ANT(...)	t_move_ant	__VA_ARGS__

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
	}
	return (lems);
}

t_path	*get_opt_path(t_graf *graf, const int start, const int end)
{
	return (get_path(graf, start, end));
}

t_bool	move_ant_aux(t_move_ant *arg)
{
	t_bool	moved;

	moved = false;
	if (NULL == arg->lems[arg->i].path)
	{
		if (NULL != (arg->lems[arg->i].path
					= get_opt_path(arg->graf, arg->start, arg->end)))
		{
			moved = true;
			arg->lems[arg->i].status = MOVED;
			arg->lems[arg->i].cam++;
			GET_ROOM_STAT1 = UNFREE;
		}
	}
	else if (FREE == GET_NRS)
	{
		moved = true;
		GET_ROOM_STAT1 = FREE;
		arg->lems[arg->i].status = MOVED;
		arg->lems[arg->i].cam++;
		if (arg->lems[arg->i].path->dist != arg->lems[arg->i].cam)
			GET_ROOM_STAT1 = UNFREE;
	}
	return (moved);
}

void	make_move_ant(t_graf *graf, t_lem *lems, t_move_ant *arg)
{
	arg->graf = graf;
	arg->lems = lems;
}

void	move_ant(t_lem *lems, t_graf *graf, const int nr_lems)
{
	GET_MOVE_ANT(arg);
	make_move_ant(graf, lems, &arg);
	arg.start = find_room_by_status_tab(graf->rooms, START);
	arg.end = find_room_by_status_tab(graf->rooms, END);
	NULL == get_path(arg.graf, arg.start, arg.end) ? error(NOCONN_ER) : DO_NONE;
	while (true)
	{
		arg.moved = false;
		arg.i = -1;
		while (++arg.i != nr_lems)
		{
			arg.lems[arg.i].status = UNMOVED;
			if (NULL != arg.lems[arg.i].path
					&& arg.lems[arg.i].path->dist == arg.lems[arg.i].cam)
			{
				GET_ROOM_STAT2 = FREE;
				continue ;
			}
			if (move_ant_aux(&arg))
				arg.moved = true;
		}
		show_rooms(arg.lems, arg.graf, nr_lems);
		if (!arg.moved)
			break ;
	}
}
