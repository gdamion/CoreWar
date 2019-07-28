/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   buf_write.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdamion- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/23 15:17:24 by gdamion-          #+#    #+#             */
/*   Updated: 2019/07/28 20:20:45 by gdamion-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "com.h"

void	translate(void)
{
	t_token		*temp;
	u_int32_t	cursor;

	cursor = 0;
	int_to_hex(COREWAR_EXEC_MAGIC, 4, &cursor);
	temp = print_champion_info(g_data->token);
	cursor = 4 + PROG_NAME_LENGTH + 4;
	int_to_hex(g_bytes, 4, &cursor);
	cursor = EXEC_START;
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
	u_int8_t d_size;

	int_to_hex(g_op_tab[type].code, 1, cursor);
	n_arg = g_op_tab[type].args_num;
	if (g_op_tab[type].args_types_code)
		arg_types_code(*op, cursor, n_arg);
	*op = (*op)->prev;
	while (n_arg--)
	{
		while ((*op)->type == SEPARATOR)
			*op = (*op)->prev;
		d_size = g_op_tab[type].t_dir_size;
		if ((*op)->type == REGISTER)
			int_to_hex(ft_atoi_cor((*op)->content + 1, 1), 1, cursor);
		else if ((*op)->type == DIRECT)
			int_to_hex(ft_atoi_cor((*op)->content, d_size), d_size, cursor);
		else if ((*op)->type == INDIRECT)
			int_to_hex(ft_atoi_cor((*op)->content, IND_SIZE), IND_SIZE, cursor);
		else if ((*op)->type == DIRECT_LABEL)
			int_to_hex(process_label((*op)->bytes, *op), d_size, cursor);
		else if ((*op)->type == INDIRECT_LABEL)
			int_to_hex(process_label((*op)->bytes, *op), IND_SIZE, cursor);
		*op = (*op)->prev;
	}
}

void	arg_types_code(t_token *op, u_int32_t *cursor, u_int8_t n_arg)
{
	int8_t	bin;
	int		arg;

	bin = 0;
	arg = 0;
	while (arg < n_arg)
	{
		if (op->type == REGISTER)
			bin |= 1 << 2 * (3 - arg++);
		else if (op->type == DIRECT || op->type == DIRECT_LABEL)
			bin |= 2 << 2 * (3 - arg++);
		else if (op->type == INDIRECT || op->type == INDIRECT_LABEL)
			bin |= 3 << 2 * (3 - arg++);
		op = op->prev;
	}
	int_to_hex(bin, 1, cursor);
}

int32_t	process_label(u_int32_t bytes, t_token *label)
{
	int32_t	move;
	t_label	*temp;

	temp = g_data->label;
	while (temp)
	{
		if (!(ft_strcmp(label->content, temp->point->content)))
			break ;
		temp = temp->next;
	}
	if (!temp)
		error_token(ERR_LABEL_EX, label);
	move = temp->point->bytes - bytes;
	return (move);
}

void	int_to_hex(int32_t dec, int dir_size, u_int32_t *place)
{
	int			move;
	int			buf;

	buf = dir_size;
	move = 0;
	while (dir_size)
	{
		g_buf[*place + dir_size - 1] = (u_int8_t)((dec >> move) & 0xFF);
		move += 8;
		dir_size--;
	}
	*place += buf;
}
