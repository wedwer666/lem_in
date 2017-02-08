/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lem_in.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmitriuc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/27 14:07:19 by mmitriuc          #+#    #+#             */
/*   Updated: 2017/02/08 20:53:39 by pcervac          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LEM_IN_H
# define LEM_IN_H

# include "libft.h"

# define NONE		0
# define ELSE_NONE	NONE
# define DO_NONE	NONE

# define FALSE		0
# define TRUE		1

# define INPUT_ER	"invalid format of input data"

typedef char*		t_string;

typedef enum		e_bool
{
	false = FALSE,
	true = TRUE
}					t_bool;

typedef enum		e_status
{
	normal = 0,
	start = 1,
	end = 2
}					t_status;

typedef struct		s_coord
{
	unsigned		x;
	unsigned		y;
}					t_coord;

typedef struct		s_room
{
	t_string		name;
	t_coord			cor;
	struct s_room	*legs;
	t_status		stat;
}					t_room;

typedef struct 		s_input
{
	int				nr_lems;
	int				fd;
	t_list			*rooms;
}					t_input;

void				read_input(t_input *inp);
void				error(t_string msg);

#endif
