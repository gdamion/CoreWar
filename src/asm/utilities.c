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

void		skip_whitespaces(t_data *data, char *line)
{
	while(SP(line[data->x]))
		data->x++;
}

void		skip_comment(t_data *data, char *line)
{
	if (line[data->x] == COMMENT_CHAR)
		while(line[data->x] && line[data->x] != "\n")
			data->x++;
}

_Bool	is_reg(char *line, int len)
{
	int	i;

	i = 0;
	if (2 <= len && len <= 3 && line[i] == 'r')
	{
		while (ft_isdigit(line[++i]) && i < len)
			;
		return (i == len && ft_atoi(&line[1]) > 0);
	}
	return (FALSE);
}