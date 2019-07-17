/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   buf_write.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdamion- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/12 14:34:07 by gdamion-          #+#    #+#             */
/*   Updated: 2019/07/16 16:09:14 by gdamion-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "com.h"

void	translate(t_token *code_start, u_int32_t code_size)
{
	t_token		*temp;
	u_int32_t	cursor;
	char		*buf;

	buf = num_to_hex(code_size, 4);
	write_magic(buf, 8 + PROG_NAME_LENGTH * 2 + 8);
	free(buf);
	write_magic((char *)COREWAR_EXEC_MAGIC, 0);
	write_magic("", 8 + PROG_NAME_LENGTH * 2);
	write_magic("", 8 + PROG_NAME_LENGTH * 2 + 8 * 2 + COMMENT_LENGTH * 2);
	cursor = 8 + PROG_NAME_LENGTH * 2 + 8 * 2 + COMMENT_LENGTH * 2 + 8;
	temp = code_start;
	while (temp)
	{
		if (temp->type == INSTRUCTION)
			print_instruction(&temp, &cursor, temp->bytes);
		temp = temp->prev;
	}
}

void	print_instruction(t_token **op, u_int32_t *cursor, u_int8_t type)
{
	u_int8_t n_arg;

	n_arg = g_op_tab[type].args_num;
	if (g_op_tab[type].args_types_code)
		print_arg_types_code(*op, cursor, n_arg);
	while (n_arg)
	{
		if ((*op)->type == REGISTER)
			write_arg(ft_atoi((*op)->content), 1, cursor);
		else if ((*op)->type == DIRECT)
			write_arg(ft_atoi((*op)->content), g_op_tab[type].t_dir_size, cursor);
		else if ((*op)->type == INDIRECT)
			write_arg(ft_atoi((*op)->content), IND_SIZE, cursor);
		else if ((*op)->type == DIRECT_LABEL)
			write_arg(process_label((*op)->bytes, (*op)->content), g_op_tab[type].t_dir_size, cursor);
		else if ((*op)->type == INDIRECT_LABEL)
			write_arg(process_label((*op)->bytes, (*op)->content), IND_SIZE, cursor);
		*op = (*op)->next;
	}
}

void	print_arg_types_code(t_token *op, u_int32_t *cursor, u_int8_t n_arg)
{
	u_int8_t	arg_types[3];
	char		*hex;

	ft_bzero(arg_types, sizeof(u_int8_t));
	while (n_arg)
	{
		if (op->type == DIRECT || op->type == DIRECT_LABEL)
			arg_types[3 - n_arg--] = T_DIR;
		else if (op->type == INDIRECT || op->type == INDIRECT_LABEL)
			arg_types[3 - n_arg--] = T_IND;
		else if (op->type == REGISTER)
			arg_types[3 - n_arg--] = T_REG;
		op = op->prev;
	}
	hex = arg_type_code(arg_types);
	just_write(hex, cursor);
	free(hex);
}

char	*arg_type_code(u_int8_t arg_types[3])
{
	int		i;
	int		bin;
	char	*res;

	if (!(res = (char*)malloc(sizeof(char) * 3)))
		errorr(ERR_ALLOC);
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

int32_t	process_label(u_int32_t bytes, char *label_name)
{
	int32_t	move;
	t_label	*temp;

	temp = g_data->label;
	while (temp)
	{
		if (!(ft_strcmp(label_name, temp->point->content)))
			break;
		temp = temp->next;
	}
	if (!temp)
		errorr(ERR_LABEL_EX);
	move = temp->point->bytes - bytes;
	return (move);
}
