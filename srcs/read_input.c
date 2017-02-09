/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_input.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcervac <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/08 19:05:12 by pcervac           #+#    #+#             */
/*   Updated: 2017/02/09 13:10:19 by pcervac          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

#define READ_ROOMS		0
#define READ_CHANNELS	1

void	error(t_string msg)
{
	ft_putendl_fd(msg, STDERR_FILENO);
	exit(EXIT_FAILURE);
}

int		procces_comment(t_string line, t_status *stat)
{
	if (ft_strequ(line, START_SIGN))
	{
		*stat = START;
		return (0);
	}
	if (ft_strequ(line, END_SIGN))
	{
		*stat = END;
		return (0);
	}
	if ('#' == *line)
		return (1);
	return (0);
}

void	read_room(t_input *inp, t_string line)
{
	t_status	stat;
	t_room		*room;
	t_string	*dates;

	stat = normal;
	if (procces_comment(line, &stat))
		return ;
	room = (t_room*)ft_memalloc(sizeof(t_room));
	NULL == room ? error(strerror(errno)) : DO_NONE;
	NULL == (dates = ft_strsplit(line, ' ')) ? error(INPUT_ER) : DO_NONE;
	dates[0] == NULL ? error(INPUT_ER) : DO_NONE;
	room->name = dates[0];
	dates[1] == NULL ? error(INPUT_ER) : DO_NONE;
	room->cor.x = ft_atoi(dates[1]);
	dates[2] == NULL ? error(INPUT_ER) : DO_NONE;
	room->cor.y = ft_atoi(dates[2]);
	dates[3] != NULL ? error(INPUT_ER) : DO_NONE;
	'L' == *room->name ? error(INPUT_ER) : DO_NONE;
	ft_lstaddb(&inp->rooms, ft_lstnew(room, sizeof(t_room*)));
	ft_memdel((void**)room);
}

t_room	*get_room(t_list *rooms, t_string name)
{
	t_list	*tmp;

	tmp = rooms;
	while (tmp != NULL)
	{
		if (ft_strequ(((t_room)tmp->content)->name, name))
			break ;
		tmp = tmp->next;
	}
	return ((t_room)tmp->content);
}

void	read_link(t_input *inp, t_string line)
{
	t_string	*dates;
	int			pos;
	t_room		*room;
	t_string	name;

	if (process_comment(line, NULL))
		return ;
	room = get_room(inp->rooms, line);
}

void	read_input(t_input *inp)
{
	t_string	line;
	int			ret;
	int			phase;

	phase = READ_ROOMS;
	1 != ft_get_next_line(inp->fd, &line) ? error(INPUT_ER) : DO_NONE;
	!ft_isnbr(line) ? error(INPUT_ER) : DO_NONE;
	(inp->nr_lems = ft_atoi(line)) <= 0 ? error(INPUT_ER) : DO_NONE;
	ft_strdel(&line);
	while (1 == (ret = ft_get_next_line(inp->fd, &line)))
	{
		phase = ft_strchr(line, '-') ? READ_CHANNELS : phase;
		phase == READ_ROOMS ? read_room(inp, line) : read_link(inp, line);
		ft_strdel(&line);
	}
	-1 == ret ? error(INPUT_ER) : DO_NONE;
}
