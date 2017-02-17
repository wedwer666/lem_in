/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flags.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcervac <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/08 19:05:12 by pcervac           #+#    #+#             */
/*   Updated: 2017/02/17 18:50:51 by pcervac          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

void    mark_start(void *inp, const int *phase)
{
    static t_bool  once = false;

	*phase != READ_ROOMS ? error(INPUT_ER) : DO_NONE; 
    once ? error(INPUT_ER) : DO_NONE;
	((t_input*)inp)->stat != NORMAL ? error(INPUT_ER) : DO_NONE;
    ((t_input*)inp)->stat = START;
	once = true;
}

void    mark_end(void *inp, const int *phase)
{
    static t_bool   once = false;

	*phase != READ_ROOMS ? error(INPUT_ER) : DO_NONE; 
    once ? error(INPUT_ER) : DO_NONE;    
	((t_input*)inp)->stat != NORMAL ? error(INPUT_ER) : DO_NONE;
	((t_input*)inp)->stat = END;
	once = true;
}

t_flags *create_flags(void)
{
	t_flags     *tmp;

	tmp = (t_flags*)ft_memalloc(sizeof(t_flags) * NR_FLG);
    NULL == tmp ? error(strerror(errno)) : DO_NONE;
	tmp[0].name = START_SIGNAL;
	tmp[0].act = &mark_start;
	tmp[1].name = END_SIGNAL;
	tmp[1].act = &mark_end;
	return (tmp);
}
