/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdel.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsatou <bsatou@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/10 20:09:49 by bsatou            #+#    #+#             */
/*   Updated: 2019/09/10 20:28:41 by bsatou           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstdel(t_list **alst, void (*del)(void *, size_t))
{
	t_list *list;
	t_list *next_list;

	if (alst && *alst && del)
	{
		list = *alst;
		while (list)
		{
			next_list = list->next;
			del(list->content, list->content_size);
			free(list);
			list = next_list;
		}
		*alst = NULL;
	}
}
