/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsatou <bsatou@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/08 17:44:40 by bsatou            #+#    #+#             */
/*   Updated: 2019/09/11 16:16:20 by bsatou           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t dstlen;
	size_t srclen;
	size_t i;

	dstlen = ft_strlen(dst);
	srclen = ft_strlen(src);
	i = 0;
	if (size)
	{
		if (size > dstlen)
			srclen += dstlen;
		else
			srclen += size;
		while (src[i] && dstlen < (size - 1))
		{
			dst[dstlen] = src[i];
			i++;
			dstlen++;
		}
		dst[dstlen] = '\0';
	}
	return (srclen);
}
