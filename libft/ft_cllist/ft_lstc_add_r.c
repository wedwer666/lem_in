/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstc_add_r.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcervac <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/13 15:19:47 by pcervac           #+#    #+#             */
/*   Updated: 2017/01/25 16:56:18 by pcervac          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_cllist.h"

void	ft_lstc_add_r(t_c_list **root, t_c_list *new)
{
	if (!root && !new)
		return ;
	if (NULL == *root)
	{
		*root = new;
		LEFT(*root) = *root;
		RIGHT(*root) = *root;
		return ;
	}
	RIGHT(new) = RIGHT(*root);
	LEFT(RIGHT(*root)) = new;
	RIGHT(*root) = new;
	LEFT(new) = *root;
}
