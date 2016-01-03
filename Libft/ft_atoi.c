/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpaincha <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/26 16:13:29 by mpaincha          #+#    #+#             */
/*   Updated: 2015/11/26 16:13:31 by mpaincha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_atoi(const char *str)
{
	int		i;
	int		nb;
	int		neg;

	i = 0;
	nb = 0;
	neg = 0;
	while (str[i] == '\t' || str[i] == '\n' || str[i] == '\v' || str[i] == '\f'
		|| str[i] == '\r' || str[i] == '\n' || str[i] == ' ')
		i++;
	if (str[i] == '+' || str[i] == '-')
	{
		if (str[i] == '-')
			neg++;
		i++;
	}
	while (str[i])
	{
		if (ft_isdigit(str[i]))
			nb = nb * 10 + (str[i] - 48);
		else
			return (neg != 0) ? (-nb) : (nb);
		i++;
	}
	return (neg != 0) ? (-nb) : (nb);
}
