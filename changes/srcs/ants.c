/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ants.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmitriuc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/21 17:51:56 by mmitriuc          #+#    #+#             */
/*   Updated: 2017/02/21 18:20:29 by mmitriuc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

//function to move ants




// function to show ants

void 	ants(t_lem *lems, int k)
{
	if (nr_lems[i].status == UNMOVED)
		show_rooms(&lems, nr_lems);
	if (nr_lems[i].status == MOVED)
		break;
}

void  show_rooms(int *t_graf,const int nr_lems)
{
	int i;
	
	i = -1;
	if (++i < nr_lems)
	{
		ft_putstr("L");
		ft_putnbr(t_rooms(rooms));
		ft_putchar('-');
		ft_putstr(t_rooms(rooms));
		ft_putchar(' ');
	}
	i = -1;
	if ( ++i == nr_lems)
		ft_putstr(' ');
	else
		break;
}
