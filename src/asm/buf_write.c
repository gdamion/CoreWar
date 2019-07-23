/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   buf_write.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdamion- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/23 15:17:24 by gdamion-          #+#    #+#             */
/*   Updated: 2019/07/23 16:53:53 by gdamion-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "com.h"

void	translate(t_token *code_start, u_int32_t code_size)
{
	t_token		*temp;
	u_int32_t	cursor;
	char		*buf;

	cursor = 0;
	ft_printf("Write magic header\n");
	int_to_hex(COREWAR_EXEC_MAGIC, 4, &cursor);

	ft_printf("Print info\n");
	print_champion_info(g_data->token);

	cursor = 4 + PROG_NAME_LENGTH + 4;
	ft_printf("Write size of prog\n");
	uint_to_hex(code_size, 4, &cursor);

	cursor = EXEC_START;
	temp = code_start;
	ft_printf("Lets go along labels\n");
	while (temp)
	{
		ft_printf("%sYet another token, cursor: %u%s\n", CYAN, cursor, EOC);
		if (temp->type == INSTRUCTION)
		{
			ft_printf("%sNew instruction: %s, type %d%s\n", GREEN, temp->content, temp->bytes, EOC);
			print_instruction(&temp, &cursor, temp->bytes);
		}
		if (temp->type == LABEL)
			ft_printf("New label '%s', %u bytes after start\n",  temp->content, temp->bytes);
		temp = temp->prev;
		ft_printf("\n");
	}
	ft_printf("%sEXEC_START = %d, CURSOR = %d, g_bytes + exec_start = %d %s\n", RED, EXEC_START, cursor, EXEC_START + g_bytes, EOC);
}

void	print_instruction(t_token **op, u_int32_t *cursor, u_int8_t type)
{
	u_int8_t n_arg;
	u_int8_t d_size;

	uint_to_hex(g_op_tab[type].code, 1, cursor);
	n_arg = g_op_tab[type].args_num;
	ft_printf("%sn of args = %d%s\n", GREEN, n_arg, EOC);
	if (g_op_tab[type].args_types_code)
		arg_types_code(*op, cursor, n_arg);
	*op = (*op)->prev;
	while (n_arg)
	{
		while ((*op)->type == SEPARATOR)
			*op = (*op)->prev;
		d_size = g_op_tab[type].t_dir_size;
		ft_printf("%s%d th arg = '%s', type = %d%s\n", PURPUL, n_arg, (*op)->content, (*op)->type, EOC);
		if ((*op)->type == REGISTER)
			uint_to_hex(ft_atoi_cor((*op)->content + 1, 1), 1, cursor);
		else if ((*op)->type == DIRECT)
			int_to_hex(ft_atoi_cor((*op)->content, d_size), d_size, cursor);
		else if ((*op)->type == INDIRECT)
			int_to_hex(ft_atoi_cor((*op)->content, IND_SIZE), IND_SIZE, cursor);
		else if ((*op)->type == DIRECT_LABEL)
			int_to_hex(process_label((*op)->bytes, *op), d_size, cursor);
		else if ((*op)->type == INDIRECT_LABEL)
			int_to_hex(process_label((*op)->bytes, *op), IND_SIZE, cursor);
		*op = (*op)->prev;
		n_arg--;
	}
}

// void	arg_types_code(t_token *op, u_int32_t *cursor, u_int8_t n_arg)
// {
// 	int			i;
// 	u_int8_t	bin;

// 	ft_printf("print_arg_types_code\n");
// 	while (n_arg)
// 	{
// 		if (op->type == DIRECT || op->type == DIRECT_LABEL)
// 			bin = bin | (2 << (3 - i) * 2);
// 		else if (op->type == INDIRECT || op->type == INDIRECT_LABEL)
// 			bin = bin | (3 << (3 - i) * 2);
// 		else if (op->type == REGISTER)
// 			bin = bin | (1 << (3 - i) * 2);
// 		op = op->prev;
// 	}
// 	uint_to_hex(bin, 1, cursor);
// 	ft_printf("arg_types_code -DONE\n");
// }

void	arg_types_code(t_token *op, u_int32_t *cursor, u_int8_t n_arg)
{
	u_int8_t	arg_types[3];

	ft_printf("print_arg_types_code\n");
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
	print_arg_types_code(arg_types, cursor, n_arg);
	ft_printf("arg_types_code -DONE\n");
}

void	print_arg_types_code(u_int8_t arg_types[3], u_int32_t *cursor, uint8_t n_arg)
{
	int			i;
	u_int8_t	bin;

	ft_printf("tp1\n");
	i = 0;
	bin = 0;
	while (i < 3)
	{
		ft_printf("tp2\n");
		if (arg_types[i] == T_REG)
			bin = bin | (1 << (3 - i) * 2);
		else if (arg_types[i] == T_DIR)
			bin = bin | (2 << (3 - i) * 2);
		else if (arg_types[i] == T_IND)
			bin = bin | (3 << (3 - i) * 2);
		i++;
	}
	uint_to_hex(bin, 1, cursor);
}

int32_t	process_label(u_int32_t bytes, t_token *label)
{
	int32_t	move;
	t_label	*temp;

	ft_printf("Call to label '%s'\n", label->content);
	temp = g_data->label;
	while (temp)
	{
		if (!(ft_strcmp(label->content, temp->point->content)))
			break;
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

	ft_printf("int to hex, %d, dir size = %d\n", dec, dir_size);
	move = 0;
	while (dir_size)
	{
		g_buf[*place + dir_size - 1] = (u_int8_t)((dec >> move) & 0xFF);
		move += 8;
		dir_size--;
	}
	*place += dir_size;
}

void	uint_to_hex(u_int32_t dec, int dir_size, u_int32_t *place)
{
	int			move;

	ft_printf("%suint to hex, %d, dir size = %d%s\n", RED, dec, dir_size, EOC);
	(*place) += dir_size;
	move = 0;
	while (dir_size)
	{
		g_buf[*place + dir_size - 1] = (u_int8_t)((dec >> move) & 0xFF);
		move += 8;
		dir_size--;
	}
}
