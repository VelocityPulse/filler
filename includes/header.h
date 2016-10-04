/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   header.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By:  <>                                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/01 18:41:04 by                   #+#    #+#             */
/*   Updated: 2016/10/04 21:32:52 by                  ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HEADER_H
# define HEADER_H

#include "debug.h"

# include <unistd.h>

# include "../libft/libft.h"
# include "get_next_line.h"

# define	P_ID_1 0
# define	P_ID_2 1

# define	MARGIN 4

typedef struct	s_piece
{
	int		size_x;
	int		size_y;
	char	**tab;
}				t_piece;

typedef struct	s_filler
{
	t_bool		player_id;
	t_piece		piece;
	int			size_x;
	int			size_y;
	char		**tab;
	t_pt		p1_pos;
	t_pt		p2_pos;
}				t_filler;

void	filler(t_filler *f);


#endif
