/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcervac <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/18 10:20:19 by pcervac           #+#    #+#             */
/*   Updated: 2017/01/21 17:01:42 by pcervac          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_get_next_line(const int fd, char **line)
{
	static char		*tmp;
	int				bol;
	int				res;
	char			temp[2];

	res = read(-1, temp, BUFF_SIZE);
	bol = 0;
	if (fd < 0 || line == NULL)
		return (-1);
	*line = ft_strnew(1);
	while ((res = read(fd, temp, 1)) > 0)
	{
		bol = 1;
		if (temp[0] == '\n')
			break ;
		tmp = *line;
		*line = ft_strjoin(*line, temp);
		ft_strdel(&tmp);
	}
	return (res < 0 ? -1 : bol);
}
