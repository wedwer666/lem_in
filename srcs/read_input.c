/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_input.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcervac <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/08 19:05:12 by pcervac           #+#    #+#             */
/*   Updated: 2017/02/23 17:11:52 by pcervac          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

t_bool	read_diez(t_input *inp, t_string line, const int *phase)
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
		list_to_array(inp);
		return (false);
	}
	NULL == (space2 = ft_strchr(space1 + 1, ' ')) ? error(INPUT_ER) : DO_NONE;
	ft_isnbr(space2 + 1) ? room->cor->y = ft_atoi(space2) : error(INPUT_ER);
	*space2 = '\0';
	ft_isnbr(space1 + 1) ? room->cor->x = ft_atoi(space1) : error(INPUT_ER);
	*space1 = '\0';
	NULL != find_room_by_name_list(inp->rooms_list, line)
		? error(EROOM_ER) : DO_NONE;
	NULL != find_room_by_coord_list(inp->rooms_list, room->cor)
		? error(ECOORD_ER) : DO_NONE;
	room->name = ft_strdup(line);
	room->type = inp->stat;
	ft_lstadd(&inp->rooms_list, ft_lstnew(NULL, 0));
	(inp->rooms_list)->content = (void*)room;
	inp->stat = NORMAL;
	inp->nr_rooms++;
	return (true);
}

t_bool	read_connections(t_input *inp, t_string line)
{
	t_string	delimiter;
	int			room1_ind;
	int			room2_ind;

	NULL == (delimiter = ft_strchr(line, '-')) ? error(INPUT_ER) : DO_NONE;
	*delimiter++ = '\0';
	-1 == (room1_ind = find_room_by_name_tab(inp->rooms_tab, line))
		? error(NEROOM_ER) : DO_NONE;
	-1 == (room2_ind = find_room_by_name_tab(inp->rooms_tab, delimiter))
		? error(NEROOM_ER) : DO_NONE;
	inp->ad_matr[room1_ind][room2_ind] != INF || inp->ad_matr[room2_ind][room1_ind] != INF
		? error(ECONN_ER) : DO_NONE;
	inp->ad_matr[room1_ind][room2_ind] = 1;
	inp->ad_matr[room2_ind][room1_ind] = 1;
	inp->nr_conns++;
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
		*line == '\0' ? error(INPUT_ER) : DO_NONE;
		if (read_diez(inp, line, &phase))
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
