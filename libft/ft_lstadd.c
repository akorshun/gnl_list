/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsatou <bsatou@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/10 20:34:43 by bsatou            #+#    #+#             */
/*   Updated: 2019/09/10 20:50:48 by bsatou           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstadd(t_list **alst, t_list *new)
{
	t_list *temp;

	temp = *alst;
	if (*alst && new)
	{
		*alst = new;
		(*alst)->next = temp;
	}
	else if (new)
	{
		*alst = new;
		(*alst)->next = NULL;
	}
}
