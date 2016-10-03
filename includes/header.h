/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   header.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By:  <>                                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/01 18:41:04 by                   #+#    #+#             */
/*   Updated: 2016/10/03 18:48:35 by                  ###   ########.fr       */
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

typedef struct	s_filler
{
	t_bool		player_id;
	int			size_x;
	int			size_y;
	char		**tab;
}				t_filler;


#endif
