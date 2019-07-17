/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexical.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdamion- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/07 13:25:26 by gdamion-          #+#    #+#             */
/*   Updated: 2019/07/07 13:27:18 by gdamion-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "com.h"

void		skip_whitespaces(char *line)
{
	while(SP1(line[g_data->x]))
		g_data->x++;
}

void		skip_comment(char *line)
{
	if (line[g_data->x] == COMMENT_CHAR)
		while(line[g_data->x] && line[g_data->x] != '\n')
			g_data->x++;
}

_Bool	is_reg(char *line, int len)
{
	int	i;

	i = 0;
	if ((2 == len || len == 3) && line[i++] == 'r')
	{
		while (ft_isdigit(line[i]) && i < len)
			i++;
		return (i == len && ft_atoi(&line[1]) > 0);
	}
	return (FALSE);
}