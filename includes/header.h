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

# define	P_ID_1 O
# define	P_ID_2 X

# define	MARGIN 4

typedef struct	s_piece
{
	int		size_x;
	int		size_y;
	char	**tab;
}				t_piece;

typedef struct	s_tray
{
	int		size_x;
	int		size_y;
	char	**tab;
}				t_tray;

typedef struct	s_filler
{
	char		ally;
	char		ennemy;
	t_piece		piece;
	t_tray		tray;
	t_tray		last_tray;
	t_pt		ally_pos;
	t_pt		ennemy_pos;
}				t_filler;

void	filler(t_filler *f);

void	apply_first_round(t_filler *f);


#endif
