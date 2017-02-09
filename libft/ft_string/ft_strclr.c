/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strclr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcervac <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/20 18:37:02 by pcervac           #+#    #+#             */
/*   Updated: 2016/12/22 19:37:28 by pcervac          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

#include "ft_string.h"

void	ft_strclr(char *s)
{
	int		i;

	i = 0;
	if (s != NULL)
		while (s[i] != '\0')
		{
			s[i] = '\0';
			i++;
		}
}