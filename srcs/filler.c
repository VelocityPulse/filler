/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   filler.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cchameyr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/07 15:47:52 by cchameyr          #+#    #+#             */
/*   Updated: 2016/10/07 15:47:59 by cchameyr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/header.h"

void	filler(t_filler *f)
{
	int		i;
	int		j;

	j = -1;
	if (f->last_tray.tab == NULL)
		first_round(f);
	while (++j < f->tray.size_y)
	{
		i = MARGIN - 1;
		while (++i < f->tray.size_x)
		{
			if (f->tray.tab[j][i] == 'o')
				ft_putstr("1 1\n");
			else if (f->tray.tab[j][i] == 'x')
				ft_putstr("2 2\n");
		}
	}
}
