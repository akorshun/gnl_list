/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsatou <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/05 19:12:43 by bsatou            #+#    #+#             */
/*   Updated: 2019/09/09 16:49:45 by bsatou           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putnbr_fd(int nb, int fd)
{
	int		inner_nb;
	char	a;

	if (nb == -2147483648)
	{
		ft_putstr_fd("-2147483648", fd);
		return ;
	}
	inner_nb = nb;
	if (nb < 0)
	{
		ft_putchar_fd('-', fd);
		inner_nb *= -1;
	}
	if (inner_nb >= 10)
		ft_putnbr_fd(inner_nb / 10, fd);
	a = (inner_nb % 10) + '0';
	ft_putchar_fd(a, fd);
}
