/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpaincha <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/03 11:34:39 by mpaincha          #+#    #+#             */
/*   Updated: 2016/01/07 12:01:21 by mpaincha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static	void	filllines(char *buf, char **lines)
{
	if (*lines == NULL)
		*lines = ft_strdup(buf);
	else
		*lines = ft_strjoin(*lines, buf);
}

static void		sendingline(char **lines, char **line)
{
	int			i;
	char		*endline;

	i = 0;
	endline = ft_strchr(*lines, '\n');
	if (endline != NULL)
		*line = ft_strnew(endline - (*lines));
	else
		*line = ft_strnew(ft_strlen(*lines));
	while ((*lines)[i] != '\n' && (*lines)[i] != '\0')
	{
		(*line)[i] = (*lines)[i];
		i++;
	}
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

	while (line != NULL && (ret = read(fd, buf, BUFF_SIZE)) > 0
	&& ft_strchr(buf, '\n') == NULL)
	{
		buf[ret] = '\0';
		filllines(buf, &lines);
	}
	if (ret == 0 && line != NULL)
	{
		if (lines == NULL)
			return (0);
		sendingline(&lines, line);
	}
	else if (ft_strchr(buf, '\n') != NULL && line != NULL)
	{
		buf[ret] = '\0';
		filllines(buf, &lines);
		sendingline(&lines, line);
	}
	else
		return (-1);
	return (1);
}
