/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_stdio.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcervac <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/22 20:38:07 by pcervac           #+#    #+#             */
/*   Updated: 2016/12/23 19:11:36 by pcervac          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_STDIO_H
# define FT_STDIO_H

# include <stdio.h>

# define BUFF_SIZE 32
# define MAX_FD 1025
# define ER -1

typedef struct	s_buff
{
	char		*bf;
	int			rf;
}				t_buff;

void			ft_putchar(char c);
void			ft_putchar_fd(char c, int fd);
void			ft_putstr(char const *s);
void			ft_putstr_fd(char const *s, int fd);
void			ft_putnstr(const char *str, size_t start, size_t nr);
void			ft_putnstr_fd(const char *str, size_t start, size_t nr, int fd);
void			ft_putendl(char const *s);
void			ft_putendl_fd(char const *s, int fd);
void			ft_putnendl(const char *str, size_t start, size_t nr);
void			ft_putnendl_fd(const char *str, size_t strt, size_t nr, int fd);
void			ft_putnbr(int n);
void			ft_putnbr_fd(int n, int fd);
int				ft_get_next_line(const int fd, char **line);

#endif
