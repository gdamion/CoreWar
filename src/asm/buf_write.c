/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   buf_write.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdamion- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/12 14:34:07 by gdamion-          #+#    #+#             */
/*   Updated: 2019/07/20 20:21:08 by gdamion-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "com.h"

void	translate(t_token *code_start, u_int32_t code_size)
{
	t_token		*temp;
	u_int32_t	cursor;
	char		*buf;

	ft_printf("Print info\n");
	print_champion_info(g_data->token);
	ft_printf("Write size of prog\n");
	buf = num_to_hex(code_size, 4);
	write_magic(buf, 8 + PROG_NAME_LENGTH * 2 + 8);
	free(buf);
	ft_printf("Write magic header\n");
	char *s= num_to_hex(COREWAR_EXEC_MAGIC, 3);
	write_magic(s, 0);
	free(s);
	ft_printf("Write empty separator\n");
	write_magic("", 8 + PROG_NAME_LENGTH * 2);
	ft_printf("Write empty separator\n");
	write_magic("", 8 + PROG_NAME_LENGTH * 2 + 8 * 2 + COMMENT_LENGTH * 2);
	cursor = EXEC_START;
	temp = code_start;
	ft_printf("Lets go along labels\n");
	while (temp)
	{
		ft_printf("%sYet another token, cursor: %u%s\n", CYAN, cursor - EXEC_START, EOC);
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
}

void	print_instruction(t_token **op, u_int32_t *cursor, u_int8_t type)
{
	u_int8_t n_arg;
	u_int8_t d_size;

	n_arg = g_op_tab[type].args_num;
	ft_printf("%sn of args = %d%s\n", GREEN, n_arg, EOC);
	if (g_op_tab[type].args_types_code)
		print_arg_types_code(*op, cursor, n_arg);
	*op = (*op)->prev;
	while (n_arg)
	{
		while ((*op)->type == SEPARATOR)
			*op = (*op)->prev;
		d_size = g_op_tab[type].t_dir_size;
		ft_printf("%s%d th arg = '%s', type = %d%s\n", PURPUL, n_arg, (*op)->content, (*op)->type, EOC);
		if ((*op)->type == REGISTER)
			write_arg(ft_atoi_cor((*op)->content + 1, 1), 1, cursor);
		else if ((*op)->type == DIRECT)
			write_arg(ft_atoi_cor((*op)->content, d_size), d_size, cursor);
		else if ((*op)->type == INDIRECT)
			write_arg(ft_atoi_cor((*op)->content, IND_SIZE), IND_SIZE, cursor);
		else if ((*op)->type == DIRECT_LABEL)
			write_arg(process_label((*op)->bytes, (*op)->content), d_size, cursor);
		else if ((*op)->type == INDIRECT_LABEL)
			write_arg(process_label((*op)->bytes, (*op)->content), IND_SIZE, cursor);
		*op = (*op)->prev;
		n_arg--;
	}
}



void	print_arg_types_code(t_token *op, u_int32_t *cursor, u_int8_t n_arg)
{
	u_int8_t	arg_types[3];
	char		*hex;

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
	hex = arg_type_code(arg_types);
	just_write(hex, cursor);
	free(hex);
	ft_printf("arg_types_code -DONE\n");
}

char	*arg_type_code(u_int8_t arg_types[3])
{
	int		i;
	int		bin;
	char	*res;

	ft_printf("tp1\n");
	if (!(res = (char*)malloc(sizeof(char) * 3)))
		errorr(ERR_ALLOC);
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
	res[0] = bin / 16;
	res[1] = bin % 16;
	res[2] = '\0';
	return (res);
}

int32_t	process_label(u_int32_t bytes, char *label_name)
{
	int32_t	move;
	t_label	*temp;

	ft_printf("Call to label '%s'\n", label_name);
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
