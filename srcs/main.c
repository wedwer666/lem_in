/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcervac <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/08 17:47:29 by pcervac           #+#    #+#             */
/*   Updated: 2017/02/09 11:55:13 by pcervac          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

t_input	*make_input()
{
	t_input	*tmp;

	tmp = (t_input*)ft_memalloc(sizeof(t_input));
	NULL == tmp ? error(strerror(errno)) : DO_NONE;
	tmp->nr_lems = 0;
	tmp->rooms = NULL;
	return (tmp);
}

int		main(void)
{
	t_input		*inp;

	inp = make_input();
	inp->fd = STDIN_FILENO;
	return (0);
}
