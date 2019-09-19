/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsatou <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/05 19:12:43 by bsatou            #+#    #+#             */
/*   Updated: 2019/09/06 16:56:46 by bsatou           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putnbr(int nb)
{
	int		inner_nb;
	char	a;

	if (nb == -2147483648)
	{
		ft_putstr("-2147483648");
		return ;
	}
	inner_nb = nb;
	if (nb < 0)
	{
		ft_putchar('-');
		inner_nb *= -1;
	}
	if (inner_nb >= 10)
		ft_putnbr(inner_nb / 10);
	a = (inner_nb % 10) + '0';
	ft_putchar(a);
}
