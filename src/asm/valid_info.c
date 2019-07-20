/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   valid_info.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdamion- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/18 19:04:44 by gdamion-          #+#    #+#             */
/*   Updated: 2019/07/20 13:33:09 by gdamion-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "com.h"

void	valid_champion_info(t_token **temp)
{
	int i;
	int name;
	int comm;

	name = 1;
	comm = 1;
	i = 2;
	while (i)
	{
		while(*temp && (*temp)->type == NEW_LINE)
			*temp = (*temp)->prev;
		if (ft_strcmp((*temp)->content, "comment"))
		{
			find_info_string(temp, 0);
			comm--;
		}
		else if (ft_strcmp((*temp)->content, "name"))
		{
			find_info_string(temp, 1);
			name--;
		}
		i--;
	}
	(name != 0 || comm != 0) ? errorr(ERR_NAMECOM) : 1;
}

void	find_info_string(t_token **temp, _Bool type)
{
	*temp = (*temp)->prev;
	if (*temp && (*temp)->type == STRING)
		*temp = (*temp)->prev;
	else if (type)
		errorr(ERR_NO_CHNAME);
	else
		errorr(ERR_NO_CHCOMM);
}
