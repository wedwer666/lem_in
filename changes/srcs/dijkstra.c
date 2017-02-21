/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dijkstra.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmitriuc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/09 16:12:42 by mmitriuc          #+#    #+#             */
/*   Updated: 2017/02/19 17:25:12 by pcervac          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

#define MARK	1
#define UNMARK	0

// we are super bravo!!
t_path	*make_path(t_node *nodes, int end)
{
	t_path		*path;
	int			i;

	path = (t_path*)ft_memalloc(sizeof(t_path));
	path->path = (int*)ft_memalloc(sizeof(int) * (nodes[end].dist + 1));
	path->dist = nodes[end].dist;
	i = nodes[end].dist + 1;
	while (--i >= 0)
	{
		path->path[i] = end;
		end = nodes[end].prec;
	}
	ft_memdel((void**)&nodes);
	return (path);
}

t_node	*make_nodes(t_graf *graf, int start)
{
	t_node	*nodes;
	int		i;

	nodes = (t_node*)ft_memalloc(sizeof(t_node) * graf->nr_rooms);
	NULL == nodes ? error(strerror(errno)) : DO_NONE;
	i = -1;
	while (++i < graf->nr_rooms)
	{
		nodes[i].dist = i == start ? 0 : INF;
		nodes[i].stat = i == start ? MARK : UNMARK;
	}
	return (nodes);
}

t_path	*get_path(t_graf *graf, int start, int end)
{
	int		cur;
	t_node	*nodes;

	nodes = make_nodes(graf, start);
	while (true)
	{
		nodes[start].stat = MARK;
		cur = -1;
		while (++cur != graf->nr_rooms)
			if (graf->ad_matr[start][cur] != INF
					&& nodes[cur].stat == UNMARK
					&& nodes[cur].dist > graf->ad_matr[start][cur] + nodes[start].dist)
			{
				nodes[cur].dist = graf->ad_matr[start][cur] + nodes[start].dist;
				nodes[cur].prec = start;
			}
				start = -1;
		while (cur-- != 0)
		{
			if (nodes[cur].stat == UNMARK
					&& (-1 == start || (nodes[cur].dist < nodes[start].dist)))
				start = cur;
		}
		if (-1 == start)
			break ;
	}
	return (make_path(nodes, end));
}
