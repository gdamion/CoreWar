/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   process_info.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdamion- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/18 19:04:44 by gdamion-          #+#    #+#             */
/*   Updated: 2019/07/28 20:31:58 by gdamion-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "com.h"

static void	find_info_string(t_token **temp, _Bool type)
{
	*temp = (*temp)->prev;
	if (*temp && (*temp)->type == STRING)
		*temp = (*temp)->prev;
	else if (type)
		error_event(ERR_NO_CHNAME);
	else
		error_event(ERR_NO_CHCOMM);
}

void		valid_champion_info(t_token **temp)
{
	int		i;
	int		name;
	int		comm;

	name = 1;
	comm = 1;
	i = 3;
	while (--i)
	{
		while (*temp && (*temp)->type == NEW_LINE)
			*temp = (*temp)->prev;
		if ((*temp)->type != COMMAND)
			error_token(ERR_WRTYPE, *temp);
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
	}
	if (name != 0 || comm != 0 || (*temp)->type != NEW_LINE)
		error_event(ERR_NAMECOM);
} //26 lines

t_token		*print_champion_info(t_token *temp)
{
	int		i;

	i = 2;
	while (i)
	{
		while (temp && temp->type == NEW_LINE)
			temp = temp->prev;
		if (!ft_strcmp(temp->content, "comment"))
		{
			temp = temp->prev;
			ft_memcpy(g_buf + 4 + PROG_NAME_LENGTH + 4 * 2,
					temp->content, ft_strlen(temp->content));
		}
		else if (!ft_strcmp(temp->content, "name"))
		{
			temp = temp->prev;
			ft_memcpy(g_buf + 4, temp->content, ft_strlen(temp->content));
		}
		else
			error_event(ERR_NAMECOM);
		temp = temp->prev;
		i--;
	}
	return (temp);
}

void		write_name_or_comm(char *cnt, int place, _Bool type)
{
	int		i;
	int		max;
	int		buf;

	max = (type ? PROG_NAME_LENGTH : COMMENT_LENGTH) * 2;
	i = -1;
	while (++i < max)
	{
		if (*cnt)
		{
			if (i % 2)
				g_buf[place + i] = ((buf = (*cnt) / 16) < 10 ? \
								('0' + buf) : ('a' + buf - 10));
			else
				g_buf[place + i] = ((buf = (*cnt) % 16) < 10 ? \
								('0' + buf) : ('a' + buf - 10));
			cnt++;
		} //2 assignations
		else
			g_buf[place + i] = '0';
	}
	if (type && *cnt)
		error_event(ERR_CHNAME_LEN);
	else if (*cnt)
		error_event(ERR_CHCOMM_LEN);
}
//30 lines
