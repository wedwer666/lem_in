/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lem_in.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmitriuc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/27 14:07:19 by mmitriuc          #+#    #+#             */
/*   Updated: 2017/02/12 18:52:21 by pcervac          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LEM_IN_H
# define LEM_IN_H

# include <errno.h>
# include <string.h>

# include "libft.h"

# define NONE		0
# define ELSE_NONE	NONE
# define DO_NONE	0

# define NON_ACTION

# define FALSE		0
# define TRUE		1

# define OFF		0
# define ON			1

# define INPUT_ER	"Error: invalid format of input data"
# define NEROOM_ER	"Error: specifed room doesn\'t exist"
# define EROOM_ER	"Error: specifed room already exist"
# define ECOORD_ER	"Error: specifed coordinates already is used"
# define STAT_ER	"Error: the room with this status already exist"
# define ECONN_ER	"Error: the link which is probed to create already exist"

# define NORMAL		0
# define START		1
# define END		2

# define NR_FLG         2

# define START_SIGNAL   "start"
# define END_SIGNAL     "end"
# define COLOR_SIGNAL   "color"
# define DEBUG_SIGNAL   "debug"

#define READ_ANTS	1
#define READ_ROOMS	2
#define READ_LINKS	3

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
	int				x;
	int				y;
}					t_coord;

typedef struct		s_room
{
	t_string		name;
	t_coord			*cor;
	t_list			*conns;
	t_status		stat;
}					t_room;


typedef struct  	s_flags
{
    t_string    	name;
    void        	(*act)(void *inp, const int *phase);
}               	t_flags;

typedef struct 		s_input
{
	int				nr_lems;
	int				fd;
	t_list			*rooms;
	t_flags			*flags;
	int				stat;
}					t_input;

void				read_input(t_input *inp);
void				error(t_string msg);
t_flags 			*create_flags(void);
t_room				*find_room_by_name(t_list *rooms, const t_string name);
t_room				*find_room_by_coord(t_list *rooms, const t_coord *cor);
t_room				*find_room_by_status(t_list *rooms, int status);
t_room				*make_room(void);

#endif
