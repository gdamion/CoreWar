/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmaron-g <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/27 18:14:29 by lmaron-g          #+#    #+#             */
/*   Updated: 2018/11/27 18:14:32 by lmaron-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/libft.h"

t_list		*ft_lstnew(void const *content, size_t content_size)
{
	t_list	*fresh;

	if (!(fresh = (t_list*)malloc(sizeof(t_list))))
		return (0);
	if (!content)
	{
		fresh->content = NULL;
		fresh->content_size = 0;
	}
	else
	{
		if (!(fresh->content = malloc(content_size)))
		{
			free(fresh);
			return (0);
		}
		fresh->content_size = content_size;
		ft_memcpy(fresh->content, content, content_size);
	}
	fresh->next = NULL;
	return (fresh);
}
