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
	ft_putstr("\n === BOUCLE FILL LINES ===   \n");
	if (*lines == 0)
	{
		ft_putstr("lines NULL\n");
		ft_putstr("BUF =>\n");
		ft_putstr(buf);
		ft_putstr("\n");
		*lines = ft_strnew(ft_strlen(buf));
		ft_strcpy(*lines, buf);
		ft_putstr("lines affichage\n");
		ft_putstr(*lines);
		ft_putstr("\n");
	}
	else
	{
		ft_putstr("lines non NULL\n");
		ft_putstr("BUF =>\n");
		ft_putstr(buf);
		ft_putstr("\n");
		*lines = ft_strjoin(*lines, buf);
		ft_putstr("lines affichage\n");
		ft_putstr(*lines);
		ft_putstr("\n");
	}
}

static void		sendingline(char **lines, char **line)
{	
	int				i;
	
	i = 0;
	*line = ft_strnew(ft_strlen(*lines));
	while ((*lines)[i] != '\n' && (*lines)[i] != '\0')
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
	{
		ft_putstr("STRDEL ========\n");
		ft_strdel(lines);
	}
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
		buf[ret] = '\0';
		ft_putstr("boucle while\n");
		ft_putstr("BUF GNL=>\n");
		ft_putstr(buf);
		ft_putstr("\n");
		filllines(buf, &lines);	
	}
	if (ret == 0)
	{
		ft_putstr("ret = 0\n");
		if (lines == NULL)
			return (0);
		else
		{
			ft_putstr("----avant----\n");
			sendingline(&lines, line);
			ft_putstr("----apre----\n");
			return (1);
		}		
	}
	else
	{
		ft_putstr("----Valeur de RET----\n");
		ft_putnbr(ret);
		ft_putstr("----SERIEUSEMENT----\n");
		filllines(buf, &lines);
		sendingline(&lines, line);
		return (1);
	}
}
