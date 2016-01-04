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
	char				*next;
	char				*unfinished;
	char				**lines;
	char				**begin;

	i = 0;
	j = 0;
	next = NULL;
	unfinished = NULL;
	lines = NULL;
	begin = NULL;
	if (fd == -1)
		return (-1);
	while ((ret = read(fd, buf, BUFF_SIZE)) > 0)
	{
		buf[ret] = '\0';
		if (lines != NULL)
		{
			*line = lines[0];
			if (lines[1])
				lines = lines[1];
			else
				free(lines);
			
			return (1);
		}
		if (next = ft_strchr(buf, '\n')) == NULL)
		{
			if (*unfinished == 0)
			{
				*unfinished = ft_strnew(BUFF_SIZE + 1);
				ft_strcpy(unfinished, buf);
			}
			else
				unfinished = ft_strjoin(unfinished, buf);
		}
		else
		{
			if (*unfinished == 0)
			{
				lines = ft_strsplit(buf, '\n');
				begin = lines;
				*line = lines[0];
				if (lines[1])
					lines = lines[1];
				else
					free(lines);
				return (1);
			}
			else
			{
				//a traiter : ft_strncat(unfinished, buf,);
			}
		}
	}
	ft_lstdbladd(&lst, *line, ft_strlen(*line));
	next++;
	if (ret == -1)
		return (-1);
	else if (ret == 0)
		return (0);
	
	 //variable permettant de reprendre la lecture du fichier la ou l'on s'etait arrete. puisque lq fonction est appele en boucle dans le main
}

// return (1) : ligne lue
// return (-1 ) : erreur lecture fichier
// return (0) : lecture terminee

// resultat renvoye sans le \n

//utilisation des variables static preconise