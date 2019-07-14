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

int			skip_whitespaces(char *line, int cursor)
{
	while(SP(line[cursor]))
		cursor++;
	return (cursor);
}

int			skip_comment(char *line, int cursor)
{
	if (line[cursor] == COMMENT_CHAR)
		while(line[cursor] && line[cursor] != "\n")
			cursor++;
	return (cursor);
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