/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsatou <bsatou@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/12 15:10:29 by bsatou            #+#    #+#             */
/*   Updated: 2019/09/19 22:31:58 by bsatou           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static char		*ft_strjoin_free(char *s1, const char *s2)
{
	char *temp;

	temp = ft_strdup(s1);
	if (s1)
		free(s1);
	s1 = ft_strjoin(temp, s2);
	free(temp);
	return (s1);
}

static t_list	*ft_fd_collection(size_t fd)
{
	static t_list	*fd_list;
	t_list			*list;

	fd_list = NULL;
	list = fd_list;
	while (list)
	{
		if (list->content_size == fd)
			return (list);
		list = list->next;
	}
	list = ft_lstnew("\0", fd);
	ft_lstadd(&fd_list, list);
	return (list);
}

static char		*ft_getline(char **dst, const char *src)
{
	size_t	len;

	len = 0;
	while (src[len] != '\n')
	{
		if (src[len] == '\0')
			break ;
		len++;
	}
	*dst = ft_strsub(src, 0, len);
	return (ft_strdup(src[len]));
}


int				get_next_line(const int fd, char **line)
{
	t_list	*fd_list;
	char	*temp;
	char	buff[BUFF_SIZE + 1];
	int		index;

	if (fd < 0 || line == NULL || read(fd, buff, 0) < 0)
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
	if (!fd_list->content)
		return (0);
	*line = fd_list->content;
	temp = fd_list->content;
	fd_list->content = ft_getline(line, temp);
	free(temp);
	return (1);
}
