/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_input.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcervac <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/08 19:05:12 by pcervac           #+#    #+#             */
/*   Updated: 2017/02/08 21:01:05 by pcervac          ###   ########.fr       */
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

void	read_rooms(t_input *inp, t_string line)
{
	
}

void	read_channels(t_input *inp, t_string line)
{
	
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
		phase == READ_ROOMS ? read_rooms(inp, line) : read_channels(inp, line);
		ft_strdel(&line);
	}
	-1 == ret ? error(INPUT_ER) : DO_NONE;
}
