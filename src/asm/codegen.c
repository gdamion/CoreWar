/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   codegen.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdamion- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/07 13:52:13 by gdamion-          #+#    #+#             */
/*   Updated: 2019/07/10 21:25:48 by gdamion-         ###   ########.fr       */
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

void	just_write(char *hex, int *place)
{
	int i;

	if (hex[0] == '0' && hex[1] == 'x')
		i += 2;
	while (hex[i] != '\0')
	{
		// if (*place > CHAMP_MAX_SIZE * 2)
		// 	error(ERR_BIGEX, 0, 0);
		g_buf[*place] = hex[i];
		(*place)++;
		hex[i]++;
	}
}

void	write_arg(int arg, int byte_num, int *place)
{
	char	*hex;
	int		len;
	int		zeros;
	int		i;

	hex = ft_itoa_base(arg, 16, 0);
	len = ft_strlen(hex);
	zeros = byte_num * 2 - len;
	while (zeros--)
		g_buf[(*place)++] = '0';
	just_write(hex, place);
	free(hex);
}

void	process_label(t_token *label, int byte_num, int *place) //преобразование метки в число и печать числа
{
	int move;

	move = ...;
	write_arg(move, byte_num, place);
}

void	args_to_code(t_token **temp, int *place, int op_n)
{
	int	dir_size;
	int	arg_n;

	dir_size = g_op_tab[op_n].t_dir_size;
	arg_n = g_op_tab[op_n].args_num;
	while (arg_n)
	{
		if ((*temp)->type == LABEL)
		{
			process_label(*temp, dir_size, place);
			*temp = (*temp)->next;
			arg_n--;
		}
		else if ((*temp)->type == T_DIR || (*temp)->type == T_IND)
		{
			write_arg(ft_atoi((*temp)->content), dir_size, place);
			arg_n--;
		}
		else
			*temp = (*temp)->next;
	}
}
