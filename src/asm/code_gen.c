/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   code_gen.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdamion- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/07 13:52:13 by gdamion-          #+#    #+#             */
/*   Updated: 2019/07/15 12:50:18 by gdamion-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "com.h"

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

char					*num_to_hex(int32_t dec, int dir_size)
{
	char *hex;
	int i;
	uint8_t temp;
	int move;

	move = 0;
	i = dir_size * 2 - 1;
	if (!(hex = (char*)malloc(sizeof(char)*(dir_size * 2 + 1))))
		errorr(ERR_ALLOC, 0, 0);
	hex[dir_size] = '\0';
	dir_size--;
	while (dir_size + 1)
	{
		temp = (uint8_t)((dec >> move) & 0xFF);
		hex[i--] = temp % 16 + (temp % 16 > 9 ? 'a' - 10 : '0');
		hex[i--] = temp / 16 + (temp / 16 > 9 ? 'a' - 10 : '0');
		move += 8;
		dir_size--;
	}
	return(hex);
}

void	write_arg(int arg, int byte_num, int *place)
{
	char	*hex;
	int		len;
	int		zeros;
	int		i;

	hex = num_to_hex(arg, byte_num);
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
