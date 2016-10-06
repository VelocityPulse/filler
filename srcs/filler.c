/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   filler.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By:  <>                                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/04 18:12:38 by                   #+#    #+#             */
/*   Updated: 2016/10/06 20:03:14 by                  ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/header.h"

void	filler(t_filler *f)
{
	int		i;
	int		j;


	j = -1;
	if (f->last_tray.tab == NULL)
		apply_first_round(f);
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
