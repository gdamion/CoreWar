/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmann <tmann@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/08 15:59:16 by tmann             #+#    #+#             */
/*   Updated: 2019/07/08 16:08:33 by tmann            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <unistd.h>
#include <stdlib.h>

static	t_list		*find_fd(t_list **head, int fd)
{
	t_list *tmp;
	t_list *node;

	tmp = *head;
	if (tmp == NULL)
	{
		(*head) = ft_lstnew("", 1);
		(*head)->content_size = (size_t)fd;
		return (*head);
	}
	while (tmp != NULL)
	{
		if (tmp->content_size == (size_t)fd)
			return (tmp);
		tmp = tmp->next;
	}
	node = ft_lstnew("", 1);
	node->content_size = (size_t)fd;
	ft_lstadd(head, node);
	return (node);
}

static char			*remove_nl(char **content, char sep, size_t i, size_t j)
{
	char		*newstr;
	char		*tmp;

	newstr = NULL;
	while (*(*content + j))
	{
		if (*(*content + j) == sep)
		{
			newstr = ft_strnew(j);
			while (++i < j)
				newstr[i] = *(*content + i);
			break ;
		}
		j++;
	}
	if (newstr != NULL)
	{
		tmp = *content;
		*content = ft_strsub(*content, ((unsigned int)(j + 1)),
				ft_strlen(*content) - j);
		free(tmp);
	}
	return (newstr);
}

static int			recheck_line(int ret, char **line, t_list *node)
{
	if (ret == 0 && node->content != NULL && ft_strlen(node->content) != 0)
	{
		*line = remove_nl((char**)&(node->content), '\n', -1, 0);
		if (*line == NULL)
		{
			*line = ft_strdup((char*)node->content);
			node->content = NULL;
			return (1);
		}
		if (ft_strlen(node->content) == 0 && *line == NULL)
			return (0);
		else
			return (1);
	}
	else if (ret == 0)
		return (0);
	return (1);
}

int					get_next_line(const int fd, char **line)
{
	static t_list	*head;
	int				ret;
	char			buf[BUFF_SIZE + 1];
	char			*tmp;
	t_list			*node;

	if (fd < 0 || line == NULL)
		return (-1);
	node = find_fd(&head, fd);
	while ((ret = read(fd, buf, BUFF_SIZE)) > 0)
	{
		tmp = node->content;
		buf[ret] = '\0';
		node->content = ft_strjoin(node->content, buf);
		free(tmp);
		*line = remove_nl((char**)&(node->content), '\n', -1, 0);
		if ((*line == NULL && ret != 0))
			continue ;
		if (ft_strchr(buf, '\n') && ret != 0)
			break ;
		return (1);
	}
	if (ret < 0)
		return (-1);
	return (recheck_line(ret, line, node));
}
