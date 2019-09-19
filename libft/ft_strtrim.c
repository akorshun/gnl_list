/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsatou <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/09 15:41:38 by bsatou            #+#    #+#             */
/*   Updated: 2019/09/09 20:53:16 by bsatou           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_isspace(char c)
{
	if (c == ' ' || c == '\n' || c == '\t')
		return (1);
	return (0);
}

static int	ft_isstrspace(const char *str)
{
	size_t i;

	i = 0;
	while (str[i])
	{
		if (!ft_isspace(str[i]))
			return (0);
		i++;
	}
	return (1);
}

char		*ft_strtrim(char const *s)
{
	size_t	start_index;
	size_t	stop_index;
	char	*res;

	if (!s)
		return (NULL);
	if (!*s)
		return ((char *)s);
	if (ft_isstrspace(s))
		return (ft_strdup(""));
	start_index = 0;
	stop_index = ft_strlen(s) - 1;
	while (ft_isspace(s[start_index]))
		start_index++;
	while (ft_isspace(s[stop_index]))
	{
		if (stop_index)
			stop_index--;
	}
	stop_index++;
	res = ft_strnew(stop_index - start_index);
	if (!res)
		return (NULL);
	res = ft_strsub(s, start_index, stop_index - start_index);
	return (res);
}
