/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpaincha <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/03 11:34:39 by mpaincha          #+#    #+#             */
/*   Updated: 2016/01/08 15:49:08 by mpaincha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static	t_list	*findfd(int const fd, t_list *lst)
{
	int		found;
	t_list	*tmp;

	tmp = lst;
	found = 0;
	while (tmp != NULL && !found)
	{
		if (((t_lines *)(tmp->content))->fd == fd)
			found = 1;
		else
			tmp = tmp->next;
	}
	if (found == 0)
		tmp = NULL;
	return (tmp);
}

static	void	filllines(char *buf, int const fd, t_list **lst)
{
	t_lines		stlines;
	t_list		*tmp;
	char		*tmplines;

	stlines.lines = NULL;
	stlines.fd = 0;
	if ((tmp = findfd(fd, *lst)))
	{
		if (((t_lines *)(tmp->content))->lines)
		{
			tmplines = ((t_lines *)(tmp->content))->lines;
			((t_lines *)(tmp->content))->lines = ft_strjoin(tmplines, buf);
			free(tmplines);
		}
		else
			((t_lines *)(tmp->content))->lines = ft_strdup(buf);
	}
	else
	{
		stlines.lines = ft_strdup(buf);
		stlines.fd = fd;
		ft_lstadd(lst, ft_lstnew(&stlines, sizeof(t_lines)));
	}
}

static void		ft_delelem(t_list **lst, t_list *to_del)
{
	t_list		*tmp;
	t_list		*next;
	t_list		*prev;

	tmp = *lst;
	prev = NULL;
	while (tmp)
	{
		if (tmp == to_del)
		{
			next = tmp->next;
			ft_strdel(&(((t_lines *)(tmp->content))->lines));
			ft_memdel((void **)tmp);
			if (prev == NULL)
				*lst = next;
			else
				prev->next = next;
		}
		prev = tmp;
		tmp = tmp->next;
	}
}

static void		sendingline(t_list **lst, int const fd, char **line)
{
	int		i;
	char	*endline;
	t_list	*tmp;
	char	*tmplines;

	i = 0;
	tmp = findfd(fd, *lst);
	endline = ft_strchr(((t_lines *)(tmp->content))->lines, '\n');
	if (endline != NULL)
		*line = ft_strnew(endline - (((t_lines *)(tmp->content))->lines));
	else
		*line = ft_strnew(ft_strlen(((t_lines *)(tmp->content))->lines));
	while ((((t_lines *)(tmp->content))->lines)[i] != '\n'
	&& (((t_lines *)(tmp->content))->lines)[i] != '\0')
	{
		(*line)[i] = (((t_lines *)(tmp->content))->lines)[i];
		i++;
	}
	if ((((t_lines *)(tmp->content))->lines)[i + 1])
	{
		tmplines = ((t_lines *)(tmp->content))->lines;
		((t_lines *)(tmp->content))->lines = ft_strsub(tmplines, i + 1,
			ft_strlen(tmplines) - (i + 1));
		free(tmplines);
	}
	else
		ft_delelem(lst, tmp);
}

int				get_next_line(int const fd, char **line)
{
	static t_list	*lst = NULL;
	char			buf[BUFF_SIZE + 1];
	int				ret;

	while (line != NULL && (ret = read(fd, buf, BUFF_SIZE)) > 0
	&& ft_strchr(buf, '\n') == NULL)
	{
		buf[ret] = '\0';
		filllines(buf, fd, &lst);
	}
	if (ret == 0 && line != NULL)
	{
		if (findfd(fd, lst) == NULL)
			return (0);
		sendingline(&lst, fd, line);
	}
	else if (ft_strchr(buf, '\n') != NULL && line != NULL)
	{
		buf[ret] = '\0';
		filllines(buf, fd, &lst);
		sendingline(&lst, fd, line);
	}
	else
		return (-1);
	return (1);
}
