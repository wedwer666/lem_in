/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dijkstra.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmitriuc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/09 16:12:42 by mmitriuc          #+#    #+#             */
/*   Updated: 2017/02/09 17:27:30 by mmitriuc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"
#define INF		9999

// we are super bravo!!
void   dijkstra(**n, *start, *end)
{
	int i, k, count, w, start, marked[n], min;

	k = -1;
	while (++k < n)
	{
		min = INF;
		w  = 1;
		while (w <= n)
		{
			if (dist[start] < min && !marked[w])
				min = dist[w], start = w;
			w++;
		}
		flag[start] = 1;
		k++;
		w = 1;
		while (w <= n)
		{
			if ((dist[start] + 1 < dist[w]) && !marked[w])
				dist[w] = dist[start] + 1;
		}
	}
}
//check for the shortest path
int 	chech_path_1(int start, int end, *link)
{
	if (*path == start && *(path + 1) == end)
		if (n[start][end] == 9999)
			return (0);
	return (1);
}

//check for the second shortest path
int		check_path_2(int start, int end, *link)
{
	if (*(path + 1) == start && *(path + 2) == end)
		if (n[start][end] == 9999)
			return (0);
	return (1);
}

//neew display???
void  reset_display(int *start)
{
	i = -1;
	while ([++i] < g_count)
	start[i] = 0;
	position[i] = 0;
}



