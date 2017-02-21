/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_verify.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmitriuc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/27 13:43:12 by mmitriuc          #+#    #+#             */
/*   Updated: 2017/02/07 16:55:01 by mmitriuc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <unistd.h>
#include "lem_in.h"
#include "libft.h"

//the function where i would like to verify if way exists

int ft_way(char	*line)
{
	int		i;
	int		k;

	k = 1;
	i = -1;
	if (ft_strlen(line) == 0)
		return ft_error();
	while (line[++i])
	{
		if (ft_isalnum(line[i]) == _success_)
			;
		else if (line[i] == '-')
		{
			k++









