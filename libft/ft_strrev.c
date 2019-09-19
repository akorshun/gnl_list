/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrev.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsatou <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/04 19:58:41 by bsatou            #+#    #+#             */
/*   Updated: 2019/09/06 16:42:16 by bsatou           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strrev(char *str)
{
	int		i;
	int		size;
	char	c;
	char	*rev_str;

	i = 0;
	size = 0;
	rev_str = str;
	while (str[size] != '\0')
		size++;
	while (i < size - 1)
	{
		c = rev_str[i];
		rev_str[i] = rev_str[size - 1];
		rev_str[size - 1] = c;
		size--;
		i++;
	}
	return (rev_str);
}
