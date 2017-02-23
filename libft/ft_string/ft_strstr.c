/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcervac <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/20 16:59:10 by pcervac           #+#    #+#             */
/*   Updated: 2016/12/22 20:06:53 by pcervac          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_stdlib.h"
#include "ft_string.h"

char	*ft_strstr(const char *big, const char *little)
{
	size_t	i;
	size_t	j;

	if (*little == '\0')
		return ((char *)big);
	i = 0;
	while (big[i] != '\0')
	{
		if (big[i] == *little)
		{
			j = 1;
			while (little[j] != '\0' && big[i + j] == little[j])
				j++;
			if (little[j] == big[i + j] || little[j] == '\0')
				return ((char *)(big + i));
		}
		i++;
	}
	return (NULL);
}
