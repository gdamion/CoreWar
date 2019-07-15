/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   valid_info.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdamion- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/12 18:32:59 by gdamion-          #+#    #+#             */
/*   Updated: 2019/07/15 21:35:38 by gdamion-         ###   ########.fr       */
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
		if (ft_strcmp((*temp)->content, "comment"))
		{
			if ((*temp)->next->type == STRING)
			{
				write_name_or_comm((*temp)->next->content, 8, 0);
				comm--;
				*temp = (*temp)->next->next;
			}
			else
				errorr(ERR_NO_CHCOMM, 0, 0);
		}
		else if (ft_strcmp((*temp)->content, "name"))
		{
			if ((*temp)->next->type == STRING)
			{
				write_name_or_comm((*temp)->next->content, 8 + PROG_NAME_LENGTH * 2 + 8 * 2, 1);
				name--;
				*temp = (*temp)->next->next;
			}
			else
				errorr(ERR_NO_CHNAME, 0, 0);
		}
		i--;
	}
	(name != 0 || comm != 0) ? errorr(ERR_NAMECOM, 0, 0) : 1;
}

void	write_name_or_comm(char *chname, int place, _Bool type)
{
	char	*hex;
	int		len;
	int		i;
	int		max;

	hex = str_to_code(chname);
	len = ft_strlen(hex);
	max = (type ? PROG_NAME_LENGTH : COMMENT_LENGTH ) * 2;
	if (type)
		len > max ? errorr(ERR_CHNAME_LEN, 0, 0) : 1;
	else
		len > max ? errorr(ERR_CHCOMM_LEN, 0, 0) : 1;
	i = 0;
	while (i < max)
	{
		if (len > 0)
		{
			g_buf[place] = hex[i];
			len--;
		}
		else
			g_buf[place++] = '0';
		i++;
	}
	free(hex);
}

char	*str_to_code(char *str)
{
	char	*res;
	int		len;
	int		i;
	int		buf;

	i = 0;
	len = ft_strlen(str) * 2;
	!(res = (char*)malloc(len + 1)) ? \
		errorr(ERR_ALLOC, 0, 0) : (res[len + 1] = '\0');
	while (i < len)
	{
		res[i] = (buf = *str / 16) < 10 ? \
			('0' + buf) : ('A' + buf - 10);
		res[i + 1] = (buf = *str % 16) < 10 ? \
			('0' + buf) : ('A' + buf - 10);
		str++;
		i += 2;
	}
	return (res);
}
