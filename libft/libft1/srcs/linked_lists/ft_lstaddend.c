/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstaddend.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmaron-g <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/29 16:09:39 by lmaron-g          #+#    #+#             */
/*   Updated: 2018/11/29 16:09:41 by lmaron-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/libft.h"

int			ft_lstaddend(t_list **alst, t_list *new)
{
	t_list	*temp;

	if (!alst)
		return (0);
	temp = *alst;
	if (temp && new)
	{
		while (temp->next)
			temp = temp->next;
		temp->next = new;
		return (1);
	}
	else if (!temp && new)
	{
		temp = new;
		return (1);
	}
	return (0);
}
