/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   syntax.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdamion- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/07 13:25:02 by gdamion-          #+#    #+#             */
/*   Updated: 2019/07/27 18:54:40 by gdamion-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

static int			op_exist(t_token *operation)
{
	int				i;

	i = 0;
	while (i < 16)
		if (!ft_strcmp(operation->content, g_op_tab[i].name))
			break ;
		else
			i++;
	if (i == 16)
		error_token(ERR_OP, operation);
	operation->bytes = i;
	return (i);
}

static void			valid_arg(int op_n, t_token *arg, int mask, u_int32_t b_start)
{
	int				arg_type;

	arg_type = arg->type;
	if (arg->type == DIRECT_LABEL)
		arg_type = T_DIR;
	else if (arg->type == INDIRECT_LABEL)
		arg_type = T_IND;
	if (arg_type != (arg_type & mask))
		error_token(ERR_ARGTP, arg);
	if (arg_type == T_REG)
		g_bytes++;
	else if (arg_type == T_IND)
	{
		g_bytes += IND_SIZE;
		arg->bytes = b_start;
	}
	else if (arg_type == T_DIR)
	{
		g_bytes += g_op_tab[op_n].t_dir_size;
		arg->bytes = b_start;
	}
}

static void			valid_instruction(t_token **operations)
{
	int				i;
	int				op_n;
	int32_t			args;
	unsigned int	*types;
	t_token			*temp;
	u_int32_t		b_start;

	i = 0;
	temp = (*operations);
	op_n = op_exist(temp);
	args = g_op_tab[op_n].args_num;
	types = g_op_tab[op_n].args_types;
	b_start = g_bytes;
	g_bytes += 1 + (g_op_tab[op_n].args_types_code ? 1 : 0);
	while ((temp = temp->prev) && temp->type < 6 && args--)
	{
		valid_arg(op_n, temp, types[i++], b_start);
		temp = temp->prev;
		if (temp->type != SEPARATOR)
			break;
	}
	if ((args != 0) && temp &&
		temp->type != NEW_LINE && temp->type != END)
		error_token(ERR_ARGNO, temp);
	*operations = temp;
}

void				syntax_analyser(t_token *token)
{
	while (token)
	{
		if (token->type == INSTRUCTION)
			valid_instruction(&token);
		else if (token->type == LABEL)
			token->bytes = g_bytes;
		else if (token->type == NEW_LINE)
			;
		else if (token->type == END)
			break ;
		else
			error_token(ERR_SYM, token);
		token = token->prev;
	}
}

//ft_printf("Token: type=%d, cont=%s\n", temp->type, temp->content);
