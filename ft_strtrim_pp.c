/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim_pp.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-mouk <mel-mouk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/02 13:21:50 by mel-mouk          #+#    #+#             */
/*   Updated: 2015/02/25 23:06:04 by mel-mouk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	*cpy(char *dest, const char *str, int (*f)(char))
{
	int	i;
	int	y;

	i = 0;
	y = 0;
	while (f(str[i]) == 1)
		i++;
	while (str[i] != '\0')
	{
		dest[y] = str[i];
		y++;
		i++;
	}
	y--;
	while (f(dest[y]) == 1 && dest[y - 1] != '\\')
	{
		dest[y] = '\0';
		y--;
	}
	return (dest);
}

char		*ft_strtrim_pp(char const *s, int (*f)(char))
{
	char	*str;
	int		i;

	i = ft_strlen(s);
	if (!(str = ft_strnew(i)))
		return (NULL);
	str = cpy(str, s, f);
	return (str);
}
