/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstfreeone.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmaron-g <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/28 17:41:38 by lmaron-g          #+#    #+#             */
/*   Updated: 2018/11/28 17:41:51 by lmaron-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/libft.h"

void	ft_lstfreeone(t_list **alst)
{
	if (!(alst && *alst))
		return ;
	(*alst)->content_size = 0;
	free((*alst)->content);
	free(*alst);
	*alst = 0;
}
