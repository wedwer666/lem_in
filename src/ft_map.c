/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_map.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmitriuc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/07 15:25:12 by mmitriuc          #+#    #+#             */
/*   Updated: 2017/02/07 16:31:46 by mmitriuc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "lem_in.h"

void ft_check_for_map(t_graf *graf)
{
	int start;
	int	end;

	start = 0;
	end = 0;
	while (graf)
	{
		if (graf->start)
			start++;
		if (graf->end)
			end++;
		graf->graf->next;
	}
	if (start != 1 || end != 1)
		ft_error();
}
