/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmaron-g <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/27 22:20:03 by lmaron-g          #+#    #+#             */
/*   Updated: 2018/11/27 22:20:04 by lmaron-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/libft.h"

t_list		*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem))
{
	t_list	*fresh;
	t_list	*rtrn;
	t_list	*temp;

	if (!lst || !f)
		return (NULL);
	temp = f(lst);
	if (!(fresh = ft_lstnew(temp->content, temp->content_size)))
		return (0);
	rtrn = fresh;
	lst = lst->next;
	while (lst)
	{
		temp = f(lst);
		if (!(fresh->next = ft_lstnew(temp->content, temp->content_size)))
		{
			ft_lstfree(&rtrn);
			return (0);
		}
		lst = lst->next;
		fresh = fresh->next;
	}
	return (rtrn);
}
