/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmaron-g <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/02 20:34:05 by lmaron-g          #+#    #+#             */
/*   Updated: 2018/12/02 20:34:07 by lmaron-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/libft.h"

static t_file		*find_node(t_file **list, int fd)
{
	t_file			*temp;

	if (!list)
		return (0);
	temp = *list;
	while (temp)
	{
		if (temp->fd == fd)
			return (temp);
		temp = temp->next;
	}
	if (!(temp = (t_file*)malloc(sizeof(t_file))))
		return (0);
	if (!(temp->thread = ft_strnew(0)))
		return (0);
	temp->fd = fd;
	temp->next = *list;
	*list = temp;
	return (temp);
}

static char			*out_manage(char **src)
{
	char			*ret;
	char			*temp;
	size_t			i;

	i = 0;
	if (!(temp = ft_strdup(*src)))
		return (0);
	while (temp[i] != '\n' && temp[i])
		i++;
	if (!(ret = ft_strsub(*src, 0, i)))
		return (0);
	ft_strdel(src);
	if (ft_strchr(temp, '\n'))
	{
		if (!(*src = ft_strdup(temp + i + 1)))
			return (0);
	}
	else if (!(*src = ft_strnew(0)))
		return (0);
	ft_strdel(&temp);
	return (ret);
}

int					get_next_line(const int fd, char **line)
{
	int				bytes;
	static t_file	*list;
	t_file			*temp;
	char			buf[BUFF_SIZE + 1];

	if (fd < 0 || !line || read(fd, buf, 0) < 0)
		return (-1);
	if (!(temp = find_node(&list, fd)))
		return (-1);
	while ((bytes = read(fd, buf, BUFF_SIZE)) > 0)
	{
		buf[bytes] = 0;
		if (!(ft_catpro(&(temp->thread), buf)))
			return (-1);
		if (ft_strchr(buf, '\n'))
			break ;
	}
	if (!ft_strlen(temp->thread))
		return (0);
	if (!(*line = out_manage(&temp->thread)))
		return (-1);
	return (1);
}
