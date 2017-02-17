/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dijkstra.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmitriuc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/09 16:12:42 by mmitriuc          #+#    #+#             */
/*   Updated: 2017/02/17 19:42:01 by pcervac          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

#define MARK	1
#define UNMARK	0

// we are super bravo!!
t_tmp	*make_tmp(t_graf *graf)
{
	t_tmp	*tmp;
	int		i;

	tmp = (t_tmp*)ft_memalloc(sizeof(t_tmp) * graf->nr_rooms);
 	i = -1;
	while (++i < graf->nr_rooms)
	{
		tmp[i].lenght = INF;
		tmp[i].state = UNMARK;
	}
	return (tmp);
}

t_path	*make_path(t_tmp *tmp, int end)
{
	t_path		*path;
	int			i;

	ft_putendl("1");
	path = (t_path*)ft_memalloc(sizeof(t_path));
	ft_putendl("2");
	ft_printf("lenght = %d\n", tmp[end].lenght);
	path->path = (int*)ft_memalloc(sizeof(int) * tmp[end].lenght);
	ft_putendl("2");
	i = tmp[end].lenght;
	ft_putendl("3");
	while (--i >= 0)
	{
	ft_putendl("4");
		path->path[i] = tmp[end].begin;
		end = tmp[end].begin;
	}
	ft_putendl("5");

//	ft_memdel((void**)&tmp);
	return (path);
}

t_path 	*get_path(t_graf *graf, int start, int end)
{
	int		k;
	t_tmp	*tmp;
	int 	w;
	int		prec;
	int		min;

	tmp = make_tmp(graf);
	k = -1;
	while (++k < graf->nr_rooms)
	{
		min = INF;
		w = 1;
		prec = start;
		while (w <= graf->nr_rooms)
		{
			if (tmp[start].lenght < min && !tmp[w].state)
			{
				min = tmp[w].lenght;
				start = w;
			}
			w++;
		}
		tmp[start].state = 1;
		tmp[start].begin = prec;
		k++;
		w = 1;
		while (w <= graf->nr_rooms)
		{
			if ((tmp[start].lenght + 1 < tmp[w].lenght) && !tmp[w].state)
				tmp[w].lenght = tmp[start].lenght + 1;
			w++;
		}
	}
	return (make_path(tmp, end));
}
