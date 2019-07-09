/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   codegen.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdamion- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/07 13:52:13 by gdamion-          #+#    #+#             */
/*   Updated: 2019/07/09 17:19:13 by gdamion-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "com.h"

void	write_magic(char* hex, int *cursor, t_token *temp)
{
	int i;
	int add_zero;

	i = 0;
	if (hex[0] == '0' && hex[1] == 'x')
		i += 2;
	add_zero = 8 - ft_strlen(&(hex[i]));
	while (hex[i] != '\0')
	{
		if (*cursor > CHAMP_MAX_SIZE)
			error(ERR_BIGEX, temp->x, temp->y);
		add_zero > 0 ? (g_buf[(*cursor)++] = '0') : \
						(g_buf[*cursor] = hex[i]);
		(*cursor)++;
		i++;
	}
	free(hex);
}

char	*str_to_code(char *str)
{
	char	*res;
	int		len;

	len = ft_strlen(str) * 2;
	!(res = (char*)malloc(len + 1)) ? \
		error(ERR_ALLOC, 0, 0) : (res[len + 1] = '\0');

	
	return (res);
}

void	write_name(char *chname, int *cursor)
{
	char	*hex;
	int		len;
	int		i;

	hex = str_to_code(chname);
	len = ft_strlen(hex);
	i = 0;
	while (i < PROG_NAME_LENGTH)
	{
		if (*cursor > CHAMP_MAX_SIZE)
			error(CHAMP_MAX_SIZE);
		if (len > 0)
		{
			g_buf[*cursor] = hex[i];
			len--;
		}
		else
			g_buf[(*cursor)++] = '0';

		i++;
	}
	free(hex);
}

void	write_comment(char *chcomm, int *cursor)
{
	char	*hex;
	int		len;
	int		i;

	hex = str_to_code(chcomm);
	len = ft_strlen(hex);
	i = 0;
	while (i < COMMENT_LENGTH)
	{
		if (*cursor > CHAMP_MAX_SIZE)
			error(CHAMP_MAX_SIZE);
		if (len > 0)
		{
			g_buf[*cursor] = hex[i];
			len--;
		}
		else
			g_buf[(*cursor)++] = '0';

		i++;
	}
	free(hex);
}


void	write_to_buf(char* hex, int *cursor, t_token *temp)
{
	if (*cursor > CHAMP_MAX_SIZE)
				error(ERR_BIGEX, temp->x, temp->y);
}


void	op_to_code(t_token *op)
{

	write_to_buf();
}

