/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_end_begin.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmitriuc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/27 13:10:06 by mmitriuc          #+#    #+#             */
/*   Updated: 2017/01/28 15:10:19 by mmitriuc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>

void ft_start(int pas, t_map *map)
{
	//analyze what type of errors we can have
	if (start != map)
		printf("Start-ul nu a fost ales corect\n");

		printf("Ati intrat camera gresita\n");

		printf("Sintaxa gresita\n");
}


void ft_end(int pas, t_map *map)
{
	if (end != map)
		printf("End-ul a fost selectat gresit\n");

		printf("Ati intrat in camera gresita\n");

		printf("Sintaxa gresita\n");

}
