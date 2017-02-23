/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ants.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcervac <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/23 16:18:10 by pcervac           #+#    #+#             */
/*   Updated: 2017/02/23 19:21:33 by pcervac          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

void  show_rooms(t_lem *lems, t_graf *graf, const int nr_lems)
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
