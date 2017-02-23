/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cllist.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcervac <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/13 11:42:42 by pcervac           #+#    #+#             */
/*   Updated: 2017/01/25 14:21:03 by pcervac          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_CLLIST_H
# define FT_CLLIST_H

# include <stdlib.h>

# define GET_INT(val)		(*(int*)(val))
# define GET_CONT(val)		(val)->content
# define GET_CONT_SIZE(val)	(val)->content_size
# define RIGHT(root)		(root)->right
# define LEFT(root)			(root)->left

typedef struct		s_c_list
{
	void			*content;
	size_t			content_size;
	struct s_c_list	*right;
	struct s_c_list	*left;
}					t_c_list;

void				ft_lstc_add_r(t_c_list **alst, t_c_list *new);
void				ft_lstc_add_l(t_c_list **alst, t_c_list *new);
void				ft_lstc_del(t_c_list **alst, void (*del)(void*, size_t));
void				ft_lstc_delone(t_c_list **alst, void (*del)(void*, size_t));
void				ft_lstc_iter_r(t_c_list *lst, void (*f)(t_c_list *elem));
void				ft_lstc_iter_l(t_c_list *lst, void (*f)(t_c_list *elem));
t_c_list			*ft_lstc_new(void const *content, size_t content_size);
size_t				ft_lstc_getsize(t_c_list *list);
void				ft_lstc_swap_r(t_c_list **root);
void				ft_lstc_swap_l(t_c_list **root);

#endif
