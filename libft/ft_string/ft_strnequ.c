/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnequ.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcervac <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/12 16:58:59 by pcervac           #+#    #+#             */
/*   Updated: 2016/12/22 19:53:23 by pcervac          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_stdlib.h"
#include "ft_string.h"

int		ft_strnequ(char const *s1, char const *s2, size_t n)
{
	size_t		i;

	i = 0;
	if (s1 != NULL && s2 != NULL)
		while (((s1[i] != '\0') || (s2[i] != '\0')) && i != n)
		{
			if (s1[i] - s2[i] != 0)
				return (0);
			i++;
		}
	return (1);
}
