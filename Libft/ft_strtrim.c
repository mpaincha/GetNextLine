/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpaincha <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/30 10:08:22 by mpaincha          #+#    #+#             */
/*   Updated: 2015/12/02 11:28:13 by mpaincha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s)
{
	size_t	i;
	size_t	lg_str;
	char	*str;

	i = 0;
	if (s == NULL)
		return (NULL);
	str = ft_strnew(ft_strlen(s));
	lg_str = 0;
	while (s[i] && (s[i] == '\t' || s[i] == '\n' || s[i] == ' '))
		i++;
	if (s[i] && s[i] != '\t' && s[i] != '\n' && s[i] != ' ')
	{
		str = ft_strsub(s, i, ft_strlen(s));
		i++;
	}
	lg_str = ft_strlen(str) - 1;
	while (lg_str > 0 && (str[lg_str] == '\t' || str[lg_str] == '\n'
		|| str[lg_str] == ' '))
		str[lg_str--] = '\0';
	return (str);
}
