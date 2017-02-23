/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstc_iter_l.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcervac <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/13 15:18:10 by pcervac           #+#    #+#             */
/*   Updated: 2017/01/15 19:04:44 by pcervac          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_cllist.h"

void	ft_lstc_iter_l(t_c_list *root, void (*f)(t_c_list *elem))
{
	t_c_list	*temp;

	temp = root;
	if (NULL == root)
		return ;
	if (root == root->right)
		f(root);
	else
	{
		while (temp->left != root)
		{
			f(temp);
			temp = temp->left;
		}
		f(temp);
	}
}
