/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_new.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmitriuc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/06 16:23:15 by mmitriuc          #+#    #+#             */
/*   Updated: 2017/02/07 17:15:51 by mmitriuc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"
#include <stdlib.h>
#include <unistd.h>

void ft_lem(t_lem *lem)
{
	lem->nr_furnici = _UNKNOW_;
	lem->start;
	lem->end;
	lem->end+pondere;
	lem->way;
	lem->graf;
	lem->traseu;
	lem->lstline;
}

//check for diez # or double ##
int ft_diez(char *line)
{
	if (*line == 0)
		ft_error();
	if (*line == '#' && (line + 1) != '#')
		return (1);
	return (0);
}
