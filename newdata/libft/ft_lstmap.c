/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmann <tmann@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/08 15:59:16 by tmann             #+#    #+#             */
/*   Updated: 2019/07/08 16:02:00 by tmann            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

static	void	free_list(t_list **alst)
{
	t_list	*tmp;
	t_list	*node;

	if (!alst)
		return ;
	node = *alst;
	while (node != NULL)
	{
		tmp = node->next;
		free(node->content);
		free(node);
		node = tmp;
	}
	*alst = NULL;
}

t_list			*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem))
{
	t_list	*head;
	t_list	*tmp;

	if (!f || lst == NULL)
		return (NULL);
	head = (t_list*)malloc(sizeof(t_list));
	if (head == NULL)
		return (NULL);
	head = f(lst);
	tmp = head;
	while (lst->next != NULL)
	{
		lst = lst->next;
		if ((tmp->next = (t_list*)malloc(sizeof(t_list))) == NULL)
		{
			free_list(&head);
			return (NULL);
		}
		tmp->next = f(lst);
		tmp = tmp->next;
	}
	return (head);
}
