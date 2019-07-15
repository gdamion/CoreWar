/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   buf_write.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdamion- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/12 14:34:07 by gdamion-          #+#    #+#             */
/*   Updated: 2019/07/15 14:46:58 by gdamion-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "com.h"

void	translate(t_token *code_start, u_int32_t code_size)
{
	t_token		*temp;
	u_int32_t	cursor;
	t_op_type	*op_type;

	op_type = g_data->op_type;
	write_magic(num_to_hex(code_size, 4), 8 + PROG_NAME_LENGTH * 2 + 8); //размер исполняемого кода
	write_magic(COREWAR_EXEC_MAGIC, 0); //магический заголовок
	write_magic("", 8 + PROG_NAME_LENGTH * 2); //разделитель
	write_magic("", 8 + PROG_NAME_LENGTH * 2 + 8 * 2 + COMMENT_LENGTH * 2); //разделитель
	cursor = 8 + PROG_NAME_LENGTH * 2 + 8 * 2 + COMMENT_LENGTH * 2 + 8; //cursor stays on code place
	temp = code_start;
	while (temp)
	{
		if (temp->type == INSTRUCTION)
		{
			print_instruction(&temp, &cursor, op_type->type);
			op_type = op_type->next;
		}
		temp = temp->prev;
	}
}

void	print_instruction(t_token **op, int *cursor, u_int8_t type)
{
	u_int8_t n_arg;

	n_arg = g_op_tab[type].args_num;
	if (g_op_tab[type].args_types_code)
		print_arg_types_code(op, cursor, n_arg);
	while (n_arg)
	{
		if ((*op)->type == REGISTER)
			write_arg(ft_atoi((*op)->content), 1, cursor);
		else if ((*op)->type == DIRECT)
			write_arg(ft_atoi((*op)->content), g_op_tab[type].t_dir_size, cursor);
		else if ((*op)->type == INDIRECT)
			write_arg(ft_atoi((*op)->content), IND_SIZE, cursor);
		else if ((*op)->type == DIRECT_LABEL)
			write_arg(process_label(), g_op_tab[type].t_dir_size, cursor);
		else if ((*op)->type == INDIRECT_LABEL)
			write_arg(process_label(), IND_SIZE, cursor);
		*op = (*op)->next;
	}
}

void	process_label(t_token *label, int byte_num, int *place)
{
	int move;

	move = ...;
	write_arg(move, byte_num, place);
}

/*
	short			arg_types[3];
	ft_bzero(arg_types, sizeof(int) * 3);
//операции
	just_write(g_op_tab[op_n].code, cursor); //write code name of operation
	g_op_tab[op_n].args_types_code ? just_write(arg_type_code(arg_types), cursor) : 1; //код типов аргументов
	args_to_code(operations, &cursor, op_n); // печать аргументов данной операции
*/
