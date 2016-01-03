/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpaincha <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/03 11:34:39 by mpaincha          #+#    #+#             */
/*   Updated: 2016/01/03 11:34:41 by mpaincha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int		get_next_line(int const fd, char **line)
{
	static t_dbllist	lst = {0, NULL, NULL};
	char				buf[BUFF_SIZE + 1];
	int					i;
	int					j;

	i = 0;
	j = 0;
	if (fd == -1)
		return (-1);
	while ((ret = read(fd, buf, BUFF_SIZE)))
	{
		buf[ret] = '\0';
		while (i < ret && buf[i] != '\n')
			*line[j++] = buf[i++];
		if (buf[i] == '\n')
		{
			ft_lstdbladd(&lst, *line, ft_strlen(*line));
			break ;
		}
	}
	
	 //variale per;ettant de reprendre la lecture du fichier la ou l'on s'etait arrete. puisque lq fonction est appele en boucle dans le main
}

// return (1) : ligne lue
// return (-1 ) : erreur lecture fichier
// return (0) : lecture terminee

// resultat renvoye sans le \n

//utilisation des variables static preconise