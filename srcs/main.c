/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcervac <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/08 17:47:29 by pcervac           #+#    #+#             */
/*   Updated: 2017/02/12 19:15:01 by pcervac          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

#define FILE_FL	"-fl"

t_input	*make_input(void)
{
	t_input	*tmp;

	tmp = (t_input*)ft_memalloc(sizeof(t_input));
	NULL == tmp ? error(strerror(errno)) : DO_NONE;
	tmp->nr_lems = 0;
	tmp->rooms = NULL;
	tmp->flags = create_flags();
	tmp->stat = NORMAL;
	return (tmp);
}

void	show(t_list *elem)
{
	t_room	*room;

	room = (t_room*)elem->content;
	ft_printf("%s %d %d stat: %d\n", room->name, room->cor->x, room->cor->y, room->stat);
}

int		main(void)
{
	t_input		*inp;

	inp = make_input();
	read_input(inp);
	ft_printf("\n");
//	ft_lstiter(inp->rooms, show);
	return (0);
}
