/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_new_ant.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmitriuc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/07 14:36:22 by mmitriuc          #+#    #+#             */
/*   Updated: 2017/02/07 16:55:55 by mmitriuc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"
#include <unistd.h>
#include <stdlib.h>

void 	ft_eliberam_furnica(t_furn *furn)
{
	t_furn *tmp;

	while (furn)
	{
		tmp = furn;
		furn = furn->next;
		free(tmp);
	}
}

void 	ft_eliberam_graful(t_graf *graf)
{
	t_graf *tmp;
	t_way  *way;

	while (graf)
	{
		while (graf->way)
		{
			way = graf->way;
			graf->way = graf->way->next;
			free(way);
		}
		tmp = graf;
		graf = graf->next;
		ft_strdel(&tmp->name);
		free(tmp);
	}
}		
