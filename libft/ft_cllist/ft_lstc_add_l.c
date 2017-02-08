/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstc_add_l.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcervac <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/13 15:20:16 by pcervac           #+#    #+#             */
/*   Updated: 2017/01/20 16:38:45 by pcervac          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_cllist.h"

void	ft_lstc_add_l(t_c_list **root, t_c_list *new)
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
	LEFT(new) = LEFT(*root);
	RIGHT(LEFT(*root)) = new;
	LEFT(*root) = new;
	RIGHT(new) = *root;
}
