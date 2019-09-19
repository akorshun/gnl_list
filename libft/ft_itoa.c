/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsatou <bsatou@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/05 19:32:57 by bsatou            #+#    #+#             */
/*   Updated: 2019/09/09 17:56:46 by bsatou           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char		*ft_itoa_job(int n, int flag, char *res)
{
	size_t i;

	i = 0;
	while (n > 0)
	{
		res[i] = n % 10 + '0';
		n /= 10;
		i++;
	}
	if (flag)
	{
		res[i] = '-';
		i++;
	}
	res[i] = '\0';
	ft_strrev(res);
	return (res);
}

static size_t	ft_nblen(const int n)
{
	size_t	i;
	int		inner_n;

	inner_n = n;
	if (inner_n < 0)
		inner_n *= -1;
	i = 0;
	while (inner_n > 0)
	{
		inner_n /= 10;
		i++;
	}
	return (i);
}

char			*ft_itoa(int n)
{
	char	*res;
	int		i;
	int		flag;

	flag = 0;
	i = ft_nblen(n);
	if (n == -2147483648)
		return (ft_strdup("-2147483648"));
	if (n == 0)
		return (ft_strdup("0"));
	if (n < 0)
	{
		flag = 1;
		n *= -1;
	}
	if (flag)
		res = ft_strnew(i + 1);
	else
		res = ft_strnew(i);
	if (!res)
		return (NULL);
	res = ft_itoa_job(n, flag, res);
	return (res);
}
