/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memrealloc.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcervac <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/19 18:39:34 by pcervac           #+#    #+#             */
/*   Updated: 2017/02/19 19:50:38 by pcervac          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_stdlib.h"

void	*ft_memrealloc(void *ptr, size_t size)
{
	void	*tmp;

	if (NULL == ptr)
		return (ft_memalloc(size));
	tmp = ft_memcpy(ft_memalloc(size), ptr, size);
	ft_memdel(&tmp);
	return (ptr = tmp);
}
