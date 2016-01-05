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
	static char		**lines;
	char			buf[BUFF_SIZE + 1];
	int				start;

	if (fd == -1)
		return (-1);
	while ((ret = read(fd, buf, BUFF_SIZE)) > 0)
	{
		buf[ret] = '\0';
		if (!lines)
			lines = ft_strnew();
		while (buf[i] != '\0')
		{
			if (buf[i] == '\n')
				start = i;
			i++;
		}
		if ((start = ft_strchr(buf, '\n')) != 0)


	}
}
/*int		get_next_line(int const fd, char **line)
{
	static t_dbllist	lst = {0, NULL, NULL};
	char				buf[BUFF_SIZE + 1];
	int					i;
	int					j;
	char				*next;
	char				*unfinished;
	int					*finished;
	char				**lines;
	char				**begin;
	char				**toline;

	i = 0;
	j = 0;
	next = NULL;
	unfinished = NULL;
	lines = NULL;
	begin = NULL;
	*finished = 1;
	toline = 0;
	if (fd == -1)
		return (-1);
	while ((ret = read(fd, buf, BUFF_SIZE)) > 0)
	{
		buf[ret] = '\0';
		if (next = ft_strchr(buf, '\n')) == NULL) //pas de \n dans le ligne
		{
			if (*finished == 1) //ligne davant fini
			{
				*unfinished = ft_strnew(BUFF_SIZE + 1);
				ft_strcpy(unfinished, buf);
				ft_lstdbladd(&lst, unfinished, ft_strlen(unfinished));
				finished = 0;
			}
			else
				lst.tail.content = ft_strjoin(unfinished, buf);
		}
		else  // contient un ou plusieurs \n
		{
			if (*finished == 1) //ligne d'avant fini
			{
				lines = ft_strsplit(buf, '\n');
				while (*lines)
				{
					ft_lstdbladd(&lst, (*lines)[i], ft_strlen((*lines)[i]));
					i++;
				}
				if (lines != NULL)
				{
					*line = lines[0];
					if (lines[1])
						lines = lines[1];
					else
					{
						free(lines);
						lines = ft_strsplit(buf, '\n');
						begin = lines;
						*line = lines[0];
						if (lines[1])
							lines = lines[1];
						else
							free(lines);

				}
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
*/
// return (1) : ligne lue
// return (-1 ) : erreur lecture fichier
// return (0) : lecture terminee

// resultat renvoye sans le \n

//utilisation des variables static preconise