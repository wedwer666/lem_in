/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_ant.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmitriuc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/09 16:44:03 by mmitriuc          #+#    #+#             */
/*   Updated: 2017/02/23 21:01:01 by pcervac          ###   ########.fr       */
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

	ft_putendl("move_ant");
	start = find_room_by_status_tab(graf->rooms, START);
	end = find_room_by_status_tab(graf->rooms, END);
	ft_printf("start %d end %d\n", start, end);
	while (true)
	{
		ft_putendl("while1");
		moved = false;
		i = -1;
		while (++i != nr_lems)
		{
			ft_putendl("\twhile2");
			lems[i].status = UNMOVED;
			if (NULL != lems[i].path && lems[i].path->dist == lems[i].cam)
			{
				graf->rooms[lems[i].path->path[lems[i].cam]]->status = UNFREE;
				continue ;
			}
			if (NULL == lems[i].path)
			{
				ft_putendl("\tif1");
				if (NULL != (lems[i].path = get_opt_path(graf, start, end)))
				{
					ft_putendl("\t\tif2");
					moved = true;
					lems[i].status = MOVED;
					lems[i].cam++;
					graf->rooms[lems[i].path->path[lems[i].cam]]->status = UNFREE;
				}
			}
			else if (FREE == graf->rooms[lems[i].path->path[lems[i].cam + 1]]->status)
			{
				ft_putendl("\telse if");
				moved = true;
				graf->rooms[lems[i].path->path[lems[i].cam]]->status = FREE;
				lems[i].status = MOVED;
				lems[i].cam++;
				graf->rooms[lems[i].path->path[lems[i].cam]]->status = UNFREE;
			}
			ft_putendl("\tend while");
		}
		show_rooms(lems, graf, nr_lems);	
		if (!moved)
			break ;
	}	
}
