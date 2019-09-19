/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_count_letters.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsatou <bsatou@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/11 14:41:16 by bsatou            #+#    #+#             */
/*   Updated: 2019/09/12 18:57:44 by bsatou           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_count_letters(const char *str, char c)
{
	size_t	letters;
	size_t	i;

	i = 0;
	letters = 0;
	if (!str)
		return (0);
	while (str[i])
	{
		while (str[i] == c && str[i])
			i++;
		while (str[i] != c && str[i])
		{
			if (str[i] != c && str[i + 1] == c && str[i + 1])
				return (letters + 1);
			i++;
			letters++;
		}
	}
	return (letters);
}
