/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcervac <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/10 18:44:14 by pcervac           #+#    #+#             */
/*   Updated: 2016/12/22 20:58:15 by pcervac          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_stdio.h"

static void	rec(int n, int fd)
{
	if (n == 0)
		return ;
	rec(n / 10, fd);
	ft_putchar_fd("0123456789"[n % 10 * (1 - 2 * (n < 0))], fd);
}

void		ft_putnbr_fd(int nb, int fd)
{
	if (nb == 0)
		ft_putchar_fd('0', fd);
	if (nb < 0)
		ft_putchar_fd('-', fd);
	rec(nb, fd);
}
