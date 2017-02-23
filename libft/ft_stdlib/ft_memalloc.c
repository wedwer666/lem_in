/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memalloc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcervac <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/10 19:21:51 by pcervac           #+#    #+#             */
/*   Updated: 2016/12/23 18:19:56 by pcervac          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_stdlib.h"

void	*ft_memalloc(size_t size)
{
	void	*temp;

	if (NULL == (temp = malloc(size)))
		return (NULL);
	return (ft_memset(temp, 0, size));
}
