/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   codegen.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdamion- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/07 13:52:13 by gdamion-          #+#    #+#             */
/*   Updated: 2019/07/09 19:55:02 by gdamion-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "com.h"

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
		// 	error(ERR_BIGEX, temp->x, temp->y);
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
		error(ERR_ALLOC, 0, 0) : (res[len + 1] = '\0');
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
	len > PROG_NAME_LENGTH*2 ? error(ERR_CHNAME_LEN, 0, 0) : (i = 0);
	while (i < PROG_NAME_LENGTH)
	{
		// if (*cursor > CHAMP_MAX_SIZE * 2)
		// 	error(ERR_BIGEX, 0, 0);
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
	len > PROG_NAME_LENGTH*2 ? error(ERR_CHCOMM_LEN, 0, 0) : (i = 0);
	while (i < COMMENT_LENGTH)
	{
		// if (*cursor > CHAMP_MAX_SIZE * 2)
		// 	error(ERR_BIGEX, 0, 0);
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


void	print_op()
{

}


void	op_to_code(t_token *op)
{

	write_to_buf();
}

