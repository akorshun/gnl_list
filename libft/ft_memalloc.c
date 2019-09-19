/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memalloc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsatou <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/03 19:20:14 by bsatou            #+#    #+#             */
/*   Updated: 2019/09/18 17:29:17 by bsatou           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memalloc(size_t size)
{
	void *mem;

	if (!size)
		return (NULL);
	mem = (void*)malloc(sizeof(void) * (size));
	if (!mem)
		return (NULL);
	ft_bzero(mem, size);
	return (mem);
}
