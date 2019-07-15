/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   syntax.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdamion- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/07 13:25:02 by gdamion-          #+#    #+#             */
/*   Updated: 2019/07/12 18:23:29 by gdamion-         ###   ########.fr       */
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
** Is arg valid?
** If it is DIRECT_LABEL - check if mark, on which we point, is exist
*/
void				valid_arg(int op_n, t_token *arg, int mask)
{
	if (arg->type != (arg->type & mask))
		errorr(ERR_ARGTP, arg->x, arg->y);
	if (arg->type == T_REG)
		g_bytes++;
	else if (arg->type == T_IND)
		g_bytes += 2;
	else if (arg->type == T_DIR)
	{
		arg->bytes = g_bytes;
		g_bytes += g_op_tab[op_n].t_dir_size;
	}
}

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
	g_bytes += g_op_tab[op_n].args_types_code ? 2 : 1;
	while ((temp = temp->prev) &&
			(temp->type < 3 || temp->type == 4) && args--)
	{
		valid_arg(op_n, temp, (*types)++);
		if (temp->prev->type == SEPARATOR)
			temp = temp->prev;
		else
			break;
	}
	if ((args || args < 0) && temp && temp->type != NEW_LINE)
		errorr(ERR_ARGNO, temp->x, temp->y);
	*operations = temp;
}

/*
** Dont forget that the g_data->token point to the last token
** We should run to previous elem_list
** Return exec code size in bytes     // Sasha
*/
void				syntax_analiser(void)
{
	t_token			*temp;

	temp = g_data->token;
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
