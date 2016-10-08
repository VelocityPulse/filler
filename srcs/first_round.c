/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   first_round.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cchameyr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/07 15:48:24 by cchameyr          #+#    #+#             */
/*   Updated: 2016/10/08 18:03:47 by cchameyr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/header.h"

static t_pt		apply_first_round(t_filler *f, t_piece p)
{
	t_pt	pos;
	t_pt	mvmt;
	t_pt	cpt;

	mvmt.x = (f->ally_spawn.x > f->ennemy_spawn.x ? 1 : -1);
	mvmt.y = (f->ally_spawn.y > f->ennemy_spawn.y ? 1 : -1);
	pos.x = (mvmt.x == 1 ? -(p.size_x - 1) : 0);
	pos.y = (mvmt.y == 1 ? -(p.size_y - 1) : 0);
	cpt = ft_make_pt(-1, -1);
	while (++cpt.y < p.size_y)
	{
		cpt.x = -1;
		while (++cpt.x < p.size_x)
		{
			if (check_pos_piece(f, p, ft_add_pt(pos, f->ally_spawn)))
				return (ft_add_pt(pos, f->ally_spawn));
			pos.x += mvmt.x;
		}
		pos.y += mvmt.y;
	}
	return (ft_add_pt(pos, f->ally_spawn));
}

static t_pt		get_spawn(t_filler *f, char player)
{
	int		x;
	int		y;

	y = -1;
	while (++y < f->tray.size_y)
	{
		x = MARGIN - 1;
		while (++x < f->tray.size_x)
		{
			if (f->tray.tab[y][x] == player)
				return (ft_make_pt(x - MARGIN, y));
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
