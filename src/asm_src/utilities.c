/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utilities.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdamion- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/07 13:25:26 by gdamion-          #+#    #+#             */
/*   Updated: 2019/07/27 18:54:40 by gdamion-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

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

int32_t		ft_atoi_cor(const char *str, u_int8_t size)
{
	int				neg;
	int				i;
	int64_t			num;

	i = 0;
	neg = 0;
	num = 0;
	while (SP(str[i]))
		i++;
	if (str[i] == '-')
		neg = 1;
	if ((str[i] == '-') || (str[i] == '+'))
		i++;
	while (str[i] >= 48 && str[i] <= 57)
	{
		num *= 10;
		num += ((int)str[i] - 48);
		i++;
	}
	num = (neg == 1 ? -num : num);
	size == 1 ? (num = (u_int8_t)num) : 1;
	size == 2 ? (num = (int16_t)num) : 1;
	size == 4 ? (num = (int32_t)num) : 1;
	return (num);
}
