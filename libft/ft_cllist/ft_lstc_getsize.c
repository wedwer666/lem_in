/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstc_getsize.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcervac <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/14 11:43:42 by pcervac           #+#    #+#             */
/*   Updated: 2017/01/14 11:48:47 by pcervac          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_cllist.h"

#define TRUE	1

size_t	ft_lstc_getsize(t_c_list *root)
{
	size_t		size;
	t_c_list	*tmp;

	size = 0;
	if (NULL == root)
		return (size);
	tmp = root;
	while (TRUE)
	{
		size++;
		tmp = tmp->right;
		if (tmp == root)
			break ;
	}
	return (size);
}
