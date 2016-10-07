/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   first_round.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cchameyr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/07 15:48:24 by cchameyr          #+#    #+#             */
/*   Updated: 2016/10/07 19:48:57 by cchameyr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/header.h"

static t_pt		apply_first_round(t_filler *f, t_piece p)
{
	t_pt	c;
	t_pt	m;
	t_pt	cpt;

	m.x = (f->ally_spawn.x > f->ennemy_spawn.x ? -1 : 1);
	m.y = (f->ally_spawn.y > f->ennemy_spawn.y ? -1 : 1);
	c.x = (m.x == -1 ? p.size_x + 1 : -1);
	c.y = (m.y == -1 ? p.size_y + 1 : -1);
	cpt = ft_make_pt(-1, -1);
	while (++cpt.y < p.size_y)
	{
		cpt.x = -1;
		while (++cpt.x < p.size_x)
		{
			if (check_pos_piece(f, p, c))
				return (c);
			c.x += m.x;
		}
		c.y += m.y;
	}
	return (c);
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

void			first_round(t_filler *f)
{
	t_pt	most_close;
	t_pt	coordinate;

	f->ally_spawn = get_spawn(f, f->ally);
	f->ennemy_spawn = get_spawn(f, f->ennemy);
	most_close = get_most_close(f, f->ally_spawn);
	coordinate = apply_first_round(f, f->piece);
	ft_printf("%d %d\n", coordinate.x, coordinate.y);
}
