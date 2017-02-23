/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcervac <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/08 17:47:29 by pcervac           #+#    #+#             */
/*   Updated: 2017/02/23 20:04:41 by pcervac          ###   ########.fr       */
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

/*
 * This function must be deleted in final version
 */
void	print_input(t_input *inp)
{
	ft_printf("nr_lems: %d\nnr_rooms: %d\nnr_legs: %d\n",
			inp->nr_lems, inp->nr_rooms, inp->nr_conns); 
	for (int i = 0; i < inp->nr_rooms; i++)
		ft_printf("%s%c",
				inp->rooms_tab[i]->name, i != inp->nr_rooms - 1 ? ' ' : '\n');
	for (int i = 0; i < inp->nr_rooms; i++)
		for (int j = 0; j < inp->nr_rooms; j++)
			ft_printf("%-2d %c",
					inp->ad_matr[i][j], j != inp->nr_rooms - 1 ? ' ' : '\n'); 
}

void	print_path(t_graf *graf, t_path *path)
{
	ft_printf("Drumul minim: %d\n", path->dist);
	for (int i = 0; i < path->dist + 1; i++)
		ft_printf("%-3s %c", graf->rooms[path->path[i]]->name,
				i != path->dist ? ' ' : '\n'); 
}

int		main(void)
{
	t_input		*inp;
	t_path		*path;
	t_graf		graf;

	inp = make_input();
	read_input(inp);
	!inp->nr_lems || !inp->nr_rooms || !inp->nr_conns
		? error(INPUT_ER) : DO_NONE;
	print_input(inp);
	graf.rooms = inp->rooms_tab;
	graf.ad_matr = inp->ad_matr;
	graf.nr_rooms = inp->nr_rooms;
	//path = get_path(&graf,
	//		find_room_by_status_tab(graf.rooms, START),
	//		find_room_by_status_tab(graf.rooms, END));
	//print_path(&graf, path);
	move_ant(make_lems(graf.rooms, inp->nr_lems), &graf, inp->nr_lems);
	return (0);
}
