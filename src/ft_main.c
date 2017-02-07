/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_main.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmitriuc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/27 13:26:16 by mmitriuc          #+#    #+#             */
/*   Updated: 2017/02/07 17:38:58 by mmitriuc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "libft.h"
#include <stdlib.h>
#include "lem_in.h"

void	ft_lem_in(t_lem *lem)
{
	char	*line;

	line = NULL;
	while (get_next_line(0, &line) > 0)
	{
		if (ft_strisdigit(line) == 1 && ft_strlen(line) > 0)
			lem->ft_lem_in = ft_atoi(line);
		if (lem->ft_lem_in <= 0)
			ft_error(lem);
		else if (!ft_strcmp(line, "#", 1) && line[1] != "#")
			;
		else
			ft_error(lem);
}

int		ft_find_start_end(t_lem *lem, char *line)
{
	if (!ft_strcmp(line, "##start", 8))
	{
		get_next_line(0, &line);
		if (line == NULL || ft_is_graf(line) == _ERR_)
			ft_error(lem, _ERR_);
		lem->start == ft_add_graf(lemin, line, &lem)
	}
	else if (!ft_strcmp(line, "##end", 6))
	{
		get_next_line(0, &line);
		if (line == NULL || ft_is_graf(line) = _ERR_)
			ft_error();
	}
}
//citesc de pe map

//primesc map

// caut cazurile exceptate care pot aparea
int		main(void)
{
	if()
		printf("Exista un numar gresit de noduri\n");
	else if ()
		printf("Nu exista asa traseu\n");
	else if ()
		printf("Start-ul nu are furnici\n");
	else if ()
		printf("End-ul nu are furnici\n");
	else if ()
		printf("Nu exista furnici in prima casa\n");
	return (0);
}
