/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By:  <>                                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/01 18:40:52 by                   #+#    #+#             */
/*   Updated: 2016/10/03 18:46:54 by                  ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/header.h"

#include <fcntl.h>

int		main(void)
{
	char	*line;
	int		fd;

	line = NULL;
	fd = open("test.main", O_RDWR | O_APPEND | O_CREAT,
	S_IRWXO | S_IRWXU | S_IRWXG);
	while (get_next_line(0, &line) == 1)
	{
		write(fd, line, ft_strlen(line));
		write(fd, "\n", 1);
		if (line[ft_strlen(line) - 1] == '*')
			ft_putstr("8 1\n");
		ft_memdel((void **)&line);
	}
	close(fd);
	return (0);
}
