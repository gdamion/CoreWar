/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   syntax.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdamion- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/07 13:25:02 by gdamion-          #+#    #+#             */
/*   Updated: 2019/07/16 15:35:22 by gdamion-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "com.h"

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
		errorr(ERR_OP, 0, 0);
	operation->bytes = i;
	return (i);
}

static void			valid_arg(int op_n, t_token *arg, int mask)
{
	int				arg_type;

	arg_type = arg->type;
	if (arg->type == 3)
		arg_type = 2;
	else if (arg->type == 5)
		arg_type = 4;
	if (arg_type != (arg_type & mask))
		errorr(ERR_ARGTP, arg->x, arg->y);
	if (arg_type == T_REG)
		g_bytes++;
	else if (arg_type == T_IND)
		g_bytes += 2;
	else if (arg_type == T_DIR)
	{
		arg->bytes = g_bytes;
		g_bytes += g_op_tab[op_n].t_dir_size;
	}
}

static void			valid_instruction(t_token **operations)
{
	int				i;
	int				op_n;
	int32_t			args;
	unsigned int	*types;
	t_token			*temp;

	i = 0;
	temp = (*operations);
	op_n = op_exist(temp);
	args = g_op_tab[op_n].args_num;
	types = g_op_tab[op_n].args_types;
	g_bytes += 1 + (g_op_tab[op_n].args_types_code ? 1 : 0);
	while ((temp = temp->prev) && temp->type < 5 && args--)
	{
		valid_arg(op_n, temp, types[i++]);
		temp = temp->prev;
		if (temp->type != SEPARATOR)
			break;
	}
	if ((args != 0) && temp && temp->type != NEW_LINE)
		errorr(ERR_ARGNO, temp->x, temp->y);
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
		{
			ft_printf("Token: type=%d, cont=%s\n", token->type, token->content);			
			errorr(ERR_SYM, token->x, token->y);
		}
		token = token->prev;
	}
}

//ft_printf("Token: type=%d, cont=%s\n", temp->type, temp->content);
