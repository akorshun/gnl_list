/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putendl.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsatou <bsatou@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/05 19:05:27 by bsatou            #+#    #+#             */
/*   Updated: 2019/09/12 16:38:16 by bsatou           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putendl(char const *s)
{
	int count;

	count = 0;
	if (!s || !*s)
	{
		ft_putchar('\n');
		return ;
	}
	while (s[count] != '\0')
	{
		ft_putchar(s[count]);
		count++;
	}
	ft_putchar('\n');
}
