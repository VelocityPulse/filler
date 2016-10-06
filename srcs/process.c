/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   process.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By:  <>                                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/04 18:12:38 by                   #+#    #+#             */
/*   Updated: 2016/10/06 19:02:41 by                  ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/header.h"

static t_pt		get_most_close(t_filler *f)
{
	char	**tab;
	t_pt	tmp;
	int		i;
	int		j;

	tab = f->tray.tab;
	tmp = ft_make_pt(f->tray.size_x, f->tray.size_y);
	j = -1;
	while (++j < f->tray.size_y)
	{
		i = MARGIN - 1;
		while (++i < f->tray.size_x)
		{
			if (tab[j][i] == f->ennemy)
			{
				if (i - f->ally_pos.x <= tmp.x && j - f->ally_pos.y <= tmp.y)
					tmp = ft_make_pt(i, j);
			}
		}
	}
	return (ft_make_pt(-1, -1));
}

static t_pt		get_spawn(t_filler *f, char player)
{
	int		i;
	int		j;

	j = -1;
	while (++j < f->tray.size_y)
	{
		i = MARGIN - 1;
		while (++i < f->tray.size_x)
		{
			if (f->tray.tab[j][i] == player)
				return (ft_make_pt(i, j));
		}
	}
	return (ft_make_pt(-1, -1));
}

void			apply_first_round(t_filler *f)
{
	t_pt	most_close;

	f->ally_pos = get_spawn(f, f->ally);
	f->ennemy_pos = get_spawn(f, f->ennemy);
	most_close = get_most_close(f);
	
}
