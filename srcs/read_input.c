/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_input.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcervac <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/08 19:05:12 by pcervac           #+#    #+#             */
/*   Updated: 2017/02/12 19:20:24 by pcervac          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

t_bool	process_diez(t_input *inp, t_string line, const int *phase)
{
	int		i;

	if (*line != '#')
		return (false);
	if (*(++line) != '#')
		return (true);
	i = -1;
	line++;
	while (++i != NR_FLG)
		if (ft_strequ(inp->flags[i].name, line))
		{
			inp->flags[i].act(inp, phase);
			break ;
		}
	return (true);
}

t_bool	read_rooms(t_input *inp, t_string line, int *phase)
{
	t_string	space1;
	t_string	space2;
	t_room		*room;

	room = make_room();
	if (NULL == (space1 = ft_strchr(line, ' ')))
	{
		*phase = READ_LINKS;
		return (false);
	}
	NULL == (space2 = ft_strchr(space1 + 1, ' ')) ? error(INPUT_ER) : DO_NONE;
	ft_isnbr(space2 + 1) ? room->cor->y = ft_atoi(space2) : error(INPUT_ER);
	*space2 = '\0';
	ft_isnbr(space1 + 1) ? room->cor->x = ft_atoi(space1) : error(INPUT_ER);
	*space1 = '\0';
	NULL != find_room_by_name(inp->rooms, line) ? error(EROOM_ER) : DO_NONE;
	NULL != find_room_by_coord(inp->rooms, room->cor) ? error(ECOORD_ER) : NONE;
	room->name = ft_strdup(line);
	room->stat = inp->stat;
	ft_lstadd(&inp->rooms, ft_lstnew(NULL, 0));
	inp->rooms->content = (void*)room;
	inp->stat = NORMAL;
	return (true);
}

t_bool	read_connections(t_input *inp, t_string line)
{
	t_string	delimiter;
	t_room		*room1;
	t_room		*room2;

	NULL == (delimiter = ft_strchr(line, '-')) ? error(INPUT_ER) : DO_NONE;
	*delimiter = '\0';
	delimiter++;
	NULL == (room1 = find_room_by_name(inp->rooms, line))
		? error(NEROOM_ER) : 0;
	NULL == (room2 = find_room_by_name(inp->rooms, delimiter))
		? error(NEROOM_ER) : 0;
	NULL != find_room_by_name(room1->conns, room2->name) ? error(ECONN_ER) : 0;
	NULL != find_room_by_name(room2->conns, room1->name) ? error(ECONN_ER) : 0;
	ft_lstadd(&room1->conns, ft_lstnew(NULL, 0));
	ft_lstadd(&room2->conns, ft_lstnew(NULL, 0));
	room1->conns->content = (void*)room2;
	room2->conns->content = (void*)room1;
	return (true);
}

t_bool	read_ants(t_input *inp, t_string line, int *phase)
{
	!ft_isnbr(line) ? error(INPUT_ER) : DO_NONE;
	(inp->nr_lems = ft_atoi(line)) < 0 ? error(INPUT_ER) : DO_NONE;
	*phase = READ_ROOMS;
	return (true);
}

void	read_input(t_input *inp)
{
	t_string	line;
	int			ret;
	int			phase;

	phase = READ_ANTS;
	while (1 == (ret = ft_get_next_line(STDIN_FILENO, &line)))
	{
		ft_printf("line = %s", line);
		*line == '\0' ? error(INPUT_ER) : DO_NONE;
		if (process_diez(inp, line, &phase))
			NON_ACTION;
		else if (phase == READ_ANTS && read_ants(inp, line, &phase))
			NON_ACTION;
		else if (phase == READ_ROOMS && read_rooms(inp, line, &phase))
			NON_ACTION;
		else if (phase == READ_LINKS && read_connections(inp, line))
			NON_ACTION;
		ft_strdel(&line);
	}
}
