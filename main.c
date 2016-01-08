/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpaincha <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/03 13:38:36 by mpaincha          #+#    #+#             */
/*   Updated: 2016/01/03 13:38:40 by mpaincha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int		main(int argc, char const *argv[])
{
	int		fd;
	char	*line;

	if (argc == 4)
	{
		fd = open(argv[1], O_RDONLY);
		if (fd == -1 || fd1 == -1 || fd2 == -1)
			return (-1);
		while (get_next_line(fd, &line))
		{
			ft_putstr(line);
			free(line);
			ft_putstr("\n");
		}
	}
	return (0);
}
