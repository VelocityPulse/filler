/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_most_close.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cchameyr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/07 15:49:55 by cchameyr          #+#    #+#             */
/*   Updated: 2016/10/07 18:28:11 by cchameyr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/header.h"

t_pt			get_most_close(t_filler *f, t_pt ally_pos)
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
			if (tab[j][i] == f->ennemy && ft_abs(ally_pos.x - i) <= tmp.x &&
				ft_abs(ally_pos.y - j) <= tmp.y)
				tmp = ft_make_pt(i, j);
		}
	}
	return (tmp);
}
