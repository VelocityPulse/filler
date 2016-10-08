/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_pos_piece.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cchameyr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/08 16:23:12 by cchameyr          #+#    #+#             */
/*   Updated: 2016/10/08 17:58:56 by cchameyr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/header.h"

static int		check_in_tab(t_filler *f, t_piece p, t_pt pos)
{
	int		x;
	int		y;
	int		m_sizex;
	int		m_sizey;

	y = -1;
	m_sizey = f->tray.size_y;
	m_sizex = f->tray.size_x - MARGIN;
	while (++y < p.size_y)
	{
		x = -1;
		while (++x < p.size_x)
		{
			if (p.tab[y][x] == '*')
			{
				if (y + pos.y > m_sizey || x + pos.x > m_sizex)
					return (_FAULT_);
			}
		}
	}
	return (_SUCCESS_);
}

int				check_pos_piece(t_filler *f, t_piece p, t_pt pos)
{
	int		x;
	int		y;
	int		match;

	if (!check_in_tab(f, p, pos))
		return (_FAULT_);
	y = -1;
	match = 0;
	pos.x += MARGIN;
	while (++y < p.size_y)
	{
		x = -1;
		while (++x < p.size_x)
		{
			if (p.tab[y][x] == '*' &&
				f->tray.tab[pos.y + y][pos.x + x] == f->ally)
				match++;
			if (match > 1)
				return (_FAULT_);
		}
	}
	if (match == 0)
		return (_FAULT_);
	return (_SUCCESS_);
}
