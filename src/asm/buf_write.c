/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   buf_write.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdamion- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/12 14:34:07 by gdamion-          #+#    #+#             */
/*   Updated: 2019/07/15 19:22:20 by gdamion-         ###   ########.fr       */
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
			write_arg(process_label((*op)->bytes, (*op)->content), g_op_tab[type].t_dir_size, cursor);
		else if ((*op)->type == INDIRECT_LABEL)
			write_arg(process_label((*op)->bytes, (*op)->content), IND_SIZE, cursor);
		*op = (*op)->next;
	}
}

int32_t	process_label(u_int32_t bytes, char *label_name)
{
	int32_t	move;
	t_label	*temp;

	temp = g_data->label;
	while (temp)
	{
		if (!(ft_strcmp(label_name, temp->name)))
			break;
		temp = temp->next;
	}
	if (!temp)
		errorr(ERR_LABEL_EX, 0, 0);
	move = temp->point->bytes - bytes;
	return (move);
}
