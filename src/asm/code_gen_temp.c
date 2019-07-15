/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   codegen2.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdamion- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/12 18:32:59 by gdamion-          #+#    #+#             */
/*   Updated: 2019/07/12 18:33:35 by gdamion-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "com.h"

char	*arg_type_code(int arg_types[3])
{
	int i;
	int bin;
	char res[3];

	i = 0;
	bin = 0;
	while (i < 3)
	{
		if (arg_types[i] == T_REG)
			bin = bin | (1 << (3 - i) * 2);
		else if (arg_types[i] == T_DIR)
			bin = bin | (2 << (3 - i) * 2);
		else if (arg_types[i] == T_IND)
			bin = bin | (3 << (3 - i) * 2);
	}
	res[0] = bin / 16;
	res[1] = bin % 16;
	res[2] = '\0';
	return (res);
}

void	write_magic(char* hex, int place)
{
	int i;
	int add_zero;

	i = 0;
	if (hex[0] == '0' && hex[1] == 'x')
		i += 2;
	add_zero = 8 - ft_strlen(&(hex[i]));
	while (hex[i] != '\0')
	{
		// if (*cursor > CHAMP_MAX_SIZE * 2)
		// 	errorr(ERR_BIGEX, temp->x, temp->y);
		add_zero > 0 ? (g_buf[place++] = '0') : \
						(g_buf[place] = hex[i]);
		place++;
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

void	write_name(char *chname, int place)
{
	char	*hex;
	int		len;
	int		i;

	hex = str_to_code(chname);
	len = ft_strlen(hex);
	len > PROG_NAME_LENGTH*2 ? errorr(ERR_CHNAME_LEN, 0, 0) : (i = 0);
	while (i < PROG_NAME_LENGTH)
	{
		// if (*cursor > CHAMP_MAX_SIZE * 2)
		// 	errorr(ERR_BIGEX, 0, 0);
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

void	write_comment(char *chcomm, int place)
{
	char	*hex;
	int		len;
	int		i;

	hex = str_to_code(chcomm);
	len = ft_strlen(hex);
	len > PROG_NAME_LENGTH*2 ? errorr(ERR_CHCOMM_LEN, 0, 0) : (i = 0);
	while (i < COMMENT_LENGTH)
	{
		// if (*cursor > CHAMP_MAX_SIZE * 2)
		// 	errorr(ERR_BIGEX, 0, 0);
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
		if (strcmp((*temp)->content, "comment"))
		{
			if ((*temp)->next->type == STRING)
			{
				write_name((*temp)->next->content, 8);
				comm--;
				*temp = (*temp)->next->next;
			}
			else
				errorr(ERR_NO_CHCOMM);
		}
		else if (strcmp((*temp)->content, "name"))
		{
			if ((*temp)->next->type == STRING)
			{
				write_comment((*temp)->next->content, 8 + PROG_NAME_LENGTH * 2 + 8 * 2);
				name--;
				*temp = (*temp)->next->next;
			}
			else
				errorr(ERR_NO_CHNAME);
		}
	}
	(name != 0 || comm != 0) ? errorr(ERR_NAMECOM) : 1;
}
