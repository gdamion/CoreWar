/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   syntax.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdamion- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/07 13:25:02 by gdamion-          #+#    #+#             */
/*   Updated: 2019/07/15 13:13:25 by gdamion-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "com.h"

static int		op_exist(char *op_name)
{
	int	i;

	i = 0;
	while (i < 16)
	{
		if (!ft_strcmp(op_name, g_op_tab[i].name))
			break ;
		i++;
	}
	if (i == 16)
		; //error
	return (i);
}

/*
** Arg types
** 1) Label (check existense)
** 2) DIR
** 3) INDIR
*/

/*
** Is arg valid?
** If it is DIRECT_LABEL - check if mark, on which we point, is exist
** And it should return number of bytes
*/
void		valid_arg(t_token *arg, int mask)
{
	if (arg->type != (arg->type & mask))
		errorr(ERR_ARGTP, arg->x, arg->y);
}

void		update_bytes(int op_n)
{
	int		i;
	unsigned int	types[3];

	i = 0;
	types = g_op_tab[op_n].args_types;
	g_bytes += 1 + g_op_tab[op_n].args_types_code ? 1 : 0;
	while (i < 3)
	{
		if (types[i] == T_REG)
			g_bytes++;
		else if (types[i] == T_DIR)
			g_bytes += g_op_tab[op_n].t_dir_size;
		else if (types[i] == T_IND)
			g_bytes += 2;
		i++;
	}
}

/*
** Check operation
** 1) Op name exists
** 2) Right number of args
** 3) Right format of args
*/

/*
** Take token - operation
** Read while !(\n)
** \n - should NOT be skiped
*/
void				valid_instruction(t_token **operations)
{
	int				op_n;
	unsigned int	args;
	unsigned int	*types;
	t_token			*temp;

	temp = (*operations);
	op_n = op_exist(temp->content);
	args = g_op_tab[op_n].args_num;
	types = g_op_tab[op_n].args_types;
	while ((temp = temp->prev) &&
			(temp->type < 3 || temp->type == 4) && args--)
	{
		valid_arg(temp, (*types)++);
		if (temp->prev->type == SEPARATOR)
			temp = temp->prev;
		else
			break;
	}
	if (args || args < 0 && temp && temp->type != NEW_LINE)
		errorr(ERR_ARGNO, temp->x, temp->y);
	update_bytes(op_n);
	*operations = temp;
}

/*
** Dont forget that the g_data->token point to the last token
** We should run to previous elem_list
** Return exec code size in bytes     // Sasha
*/
void		syntax_analiser(t_token *code_start)
{
	t_token	*temp;
	t_token *op;

	temp = code_start;
	while (temp)
	{
		if (temp->type == INSTRUCTION)
			valid_instruction(&temp);
		else if (temp->type == LABEL)
			temp->bytes = g_bytes;
		else if (temp->type == NEW_LINE)
			;
		else
			errorr(ERR_SYM, temp->x, temp->y);
		temp = temp->prev;
	}
}
