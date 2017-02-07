/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_coordinates.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmitriuc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/06 16:19:27 by mmitriuc          #+#    #+#             */
/*   Updated: 2017/02/06 16:22:50 by mmitriuc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

void ft_ver_coord(t_room *tmp, char *str, int x, int y)
{
	while (tmp)
	{
		if (x == tmp->x && y == tmp->y)
		{
			if (ft_strcmp(str, tmp->good))
				ft_error();
		}
		tmp = tmp->next;
	}
}
