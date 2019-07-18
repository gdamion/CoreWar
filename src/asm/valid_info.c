/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   valid_info.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdamion- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/12 18:32:59 by gdamion-          #+#    #+#             */
/*   Updated: 2019/07/18 18:24:48 by gdamion-         ###   ########.fr       */
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
	{
		write_name_or_comm(*temp, \
			(type ? 8 : 8 + PROG_NAME_LENGTH * 2 + 8 * 2), type);
		*temp = (*temp)->prev;
	}
	else if (type)
		errorr(ERR_NO_CHNAME);
	else
		errorr(ERR_NO_CHCOMM);
}

void	write_name_or_comm(t_token *temp, int place, _Bool type)
{
	char	*hex;
	int		len;
	int		i;
	int		max;

	hex = str_to_code(temp->content);
	len = ft_strlen(hex);
	max = (type ? PROG_NAME_LENGTH : COMMENT_LENGTH ) * 2;
	if (type)
		len > max ? errorr(ERR_CHNAME_LEN) : 1;
	else
		len > max ? errorr(ERR_CHCOMM_LEN) : 1;
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
		errorr(ERR_ALLOC) : (res[len + 1] = '\0');
	while (i < len)
	{
		res[i] = (buf = *str / 16) < 10 ? \
			('0' + buf) : ('a' + buf - 10);
		res[i + 1] = (buf = *str % 16) < 10 ? \
			('0' + buf) : ('a' + buf - 10);
		str++;
		i += 2;
	}
	return (res);
}
