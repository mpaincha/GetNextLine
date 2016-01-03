/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdbldel.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpaincha <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/11 10:06:14 by mpaincha          #+#    #+#             */
/*   Updated: 2015/12/20 16:12:56 by mpaincha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstdbldel(t_dbllist **list)
{
	t_elem	*tmp;

	tmp = NULL;
	while ((*list)->head != NULL)
	{
		tmp = (*list)->head->next;
		free((*list)->head->content);
		(*list)->head->content = NULL;
		free((*list)->head);
		(*list)->head = tmp;
	}
	(*list)->tail = NULL;
	(*list)->head = NULL;
}
