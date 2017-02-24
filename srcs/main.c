/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcervac <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/08 17:47:29 by pcervac           #+#    #+#             */
/*   Updated: 2017/02/24 17:07:36 by pcervac          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

t_input	*make_input(void)
{
	t_input	*tmp;

	tmp = (t_input*)ft_memalloc(sizeof(t_input));
	NULL == tmp ? error(strerror(errno)) : DO_NONE;
	tmp->nr_lems = 0;
	tmp->rooms_list = NULL;
	tmp->flags = create_flags();
	tmp->stat = NORMAL;
	tmp->nr_rooms = 0;
	tmp->nr_conns = 0;
	return (tmp);
}

int		main(void)
{
	t_input		*inp;
	t_graf		graf;

	inp = make_input();
	read_input(inp);
	!inp->nr_lems || !inp->nr_rooms || !inp->nr_conns
		? error(INPUT_ER) : DO_NONE;
	graf.rooms = inp->rooms_tab;
	graf.ad_matr = inp->ad_matr;
	graf.nr_rooms = inp->nr_rooms;
	move_ant(make_lems(graf.rooms, inp->nr_lems), &graf, inp->nr_lems);
	return (0);
}
