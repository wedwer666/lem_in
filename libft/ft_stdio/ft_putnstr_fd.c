/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnstr_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcervac <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/30 18:34:12 by pcervac           #+#    #+#             */
/*   Updated: 2016/12/22 21:01:27 by pcervac          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

#include "ft_stdio.h"
#include "ft_string.h"

void	ft_putnstr_fd(const char *str, size_t start, size_t nr, int fd)
{
	if (fd > 0 && str != NULL)
		if (start < ft_strlen(str) && start + nr < ft_strlen(str))
			write(fd, &str[start], nr);
}
