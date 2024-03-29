/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsatou <bsatou@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/12 15:10:29 by bsatou            #+#    #+#             */
/*   Updated: 2019/09/23 15:39:19 by bsatou           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static char		*ft_strjoin_free(char *s1, char *s2)
{
	char *temp;

	temp = ft_strdup(s1);
	if (s1)
		ft_strdel(&s1);
	s1 = ft_strjoin(temp, s2);
	ft_strdel(&temp);
	return (s1);
}

static t_list	*fd_collection(size_t fd)
{
	static t_list	*fd_list = NULL;
	t_list			*list;

	list = fd_list;
	while (list)
	{
		if (list->content_size == fd)
			return (list);
		list = list->next;
	}
	if (!list)
	{
		list = ft_lstnew("\0", 1);
		list->content_size = fd;
	}
	ft_lstadd(&fd_list, list);
	return (list);
}

static char		*fd_getline(char **dst, char *src)
{
	size_t	len;
	size_t	stop;

	len = 0;
	stop = 0;
	if (ft_strchr(src, '\n'))
		stop = 1;
	while (src[len] && src[len] != '\n')
		len++;
	*dst = ft_strsub(src, 0, len);
	return (ft_strsub(src, len + stop, ft_strlen(src)));
}

int				get_next_line(const int fd, char **line)
{
	char	buff[BUFF_SIZE + 1];
	t_list	*fd_list;
	int		index;
	char	*temp;

	if (fd < 0 || !line || read(fd, buff, 0) < 0)
		return (-1);
	fd_list = fd_collection(fd);
	*line = NULL;
	while ((index = read(fd, buff, BUFF_SIZE)))
	{
		buff[index] = '\0';
		fd_list->content = ft_strjoin_free(fd_list->content, buff);
		if (ft_strchr(buff, '\n'))
			break ;
	}
	if (!ft_strlen(fd_list->content))
		return (0);
	temp = fd_list->content;
	fd_list->content = fd_getline(line, temp);
	ft_strdel(&temp);
	return (1);
}
