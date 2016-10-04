/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By:  <>                                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/03 15:15:03 by                   #+#    #+#             */
/*   Updated: 2016/10/04 21:51:53 by                  ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/header.h"

static void		process_first_line(t_filler *f)
{
	char	*line;

	line = NULL;
	get_next_line(0, &line);
	if (ft_strncmp(line, "$$$ exec p1", 11))
		f->player_id = P_ID_1;
	else if (ft_strncmp(line, "$$$ exec p2", 11))
		f->player_id = P_ID_2;
	ft_memdel((void **)&line);
}

static void		process_sizes(t_filler *f)
{
	char	*line;
	int		i;

	line = NULL;
	get_next_line(0, &line);
	i = 8;
	f->size_y = ft_atoi(&line[i]);
	while (line[++i] != ' ')
		;
	f->size_x = ft_atoi(&line[++i]) + MARGIN;
	ft_memdel((void **)&line);
}

static void		process_tab(t_filler *f)
{
	char	*line;
	int		i;

	line = NULL;
	i = -1;
	get_next_line(0, &line);
	ft_memdel((void **)&line);
	f->tab = (char **)ft_memalloc(sizeof(char *) * f->size_y);
	while (++i < f->size_y)
		get_next_line(0, &f->tab[i]);
}

static void		process_piece(t_filler *f)
{
	char	*line;
	int		i;

	line = NULL;
	get_next_line(0, &line);
	i = 6;
	f->piece.size_y = ft_atoi(&line[i]);
	while (line[++i] != ' ')
		;
	f->piece.size_x = ft_atoi(&line[++i]);
	ft_memdel((void **)&line);
	f->piece.tab = (char **)ft_memalloc(sizeof(char *) * (f->piece.size_y + 1));
	i = -1;
	while (++i < f->piece.size_y)
		get_next_line(0, &f->piece.tab[i]);
}

int				main(void)
{
	t_filler	f;

	process_first_line(&f);
	while (1)
	{
		process_sizes(&f);
		process_tab(&f);
		process_piece(&f);
		filler(&f);
		ft_memdel2((void ***)&f.tab);
		ft_memdel2((void ***)&f.piece.tab);
	}
	return (0);
}
