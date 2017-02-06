/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_additional_functions.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmitriuc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/06 14:40:18 by mmitriuc          #+#    #+#             */
/*   Updated: 2017/02/06 15:28:02 by mmitriuc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>
#include "lem_in.h"

void 	ft_putchar(char c)
{
	write(1, &c, 1);
}

void 	ft_error(void)
{
	write(1, G_1, 4);
	write(1, "Error\n", 6);
	write(1, G_2, 4);
	exit(0);
}

size_t 	ft_strlen(const char *str)
{
	int	i;

	i = 0;
	while (*(str + i))
		i++;
	return (i);
}

void 	*ft_memcpy(void *s1, const void *s2, size_t n)
{
	size_t 	i;

	i = 0;
	while (i < n)
	{
		((char*)s1)[i] = ((char*)s2)[i];
		i++;
	}
	return (s1);
}

void	ft_putstr(const char *s)
{
	int	i;

	if (!s)
		return ;
	i = 0;
	while (s[i])
		ft_putchar(s[i++]);
}


