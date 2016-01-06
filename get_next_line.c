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

static	void	filllines(char *buf, char **lines)
{
	int		i;

	i = 0;
	while (buf[i] != '\0')
	{
		ft_putstr("boucle fillines   \n");
		if (*lines == 0)
		{
			ft_putstr("lines NULL\n");
			*lines = ft_strnew(ft_strlen(buf));
			ft_strcpy(*lines, buf);
			ft_putstr("lines affichage\n");
			ft_putstr(*lines);
			ft_putstr("\n");
		}
		else
		{
			ft_putstr("lines non NULL\n");
			*lines = ft_strjoin(*lines, buf);
			ft_putstr("lines affichage\n");
			ft_putstr(*lines);
			ft_putstr("\n");
		}
		i++;
	}
}

static void		sendingline(char **lines, char **line)
{	
	int				i;
	
	i = 0;
	*line = ft_strnew(ft_strlen(*lines));
	while ((*lines)[i] != '\n')
	{
		(*line)[i] = (*lines)[i];
		i++;
	}
	ft_putstr("LINE affichage\n");
	ft_putstr(*line);
	ft_putstr("\n");
	if ((*lines)[i + 1])
		*lines = ft_strsub(*lines, i + 1, ft_strlen(*lines) - (i + 1));
	else
		ft_strdel(lines);
}

int				get_next_line(int const fd, char **line)
{
	static char		*lines = NULL;
	char			buf[BUFF_SIZE + 1];
	int				ret;

	ret = 0;
	if (fd == -1)
		return (-1);
	while ((ret = read(fd, buf, BUFF_SIZE)) > 0 && ft_strchr(buf, '\n') == 0)
	{
		ft_putstr("boucle while\n");
		buf[ret] = '\0';
		filllines(buf, &lines);	
	}
	if (ret == 0)
	{
		if (lines)
		{
			sendingline(&lines, line);
			return (1);
		}
		return (0);
	}
	else
	{
		filllines(buf, &lines);		
		sendingline(&lines, line);
		return (1);
	}
}
