/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstc_del.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcervac <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/13 12:26:41 by pcervac           #+#    #+#             */
/*   Updated: 2017/01/25 20:37:32 by pcervac          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_cllist.h"
#include "ft_stdio.h"

void	ft_lstc_del(t_c_list **root, void (*del)(void *, size_t))
{
	t_c_list	*tmp;

	if (!root)
		return ;
	while (*root)
	{
		tmp = NULL;
		if (*root != LEFT(*root))
		{
			RIGHT(LEFT(*root)) = RIGHT(*root);
			LEFT(RIGHT(*root)) = LEFT(*root);
			tmp = RIGHT(*root);
		}
		ft_lstc_delone(root, del);
		*root = tmp;
	}
}
