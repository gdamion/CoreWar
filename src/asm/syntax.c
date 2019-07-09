/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   syntax.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdamion- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/07 13:25:02 by gdamion-          #+#    #+#             */
/*   Updated: 2019/07/09 17:06:11 by gdamion-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "com.h"

void	valid_champion_info(t_token **temp, int *len)
{
	int i;
	int name;
	int comm;

	name = 1;
	comm = 1;
	i = 2;
	while (i)
	{
		if (strcmp((*temp)->content, "comment"))
		{
			if ((*temp)->next->type == STRING)
			{
				write_name((*temp)->next->content, len);
				comm--;
				*temp = (*temp)->next->next;
			}
			else
				error(ERR_NO_CHCOMM);
		}
		else if (strcmp((*temp)->content, "name"))
		{
			if ((*temp)->next->type == STRING)
			{
				write_comment((*temp)->next->content, len);
				name--;
				*temp = (*temp)->next->next;
			}
			else
				error(ERR_NO_CHNAME);
		}
	}
	(name != 0 || comm != 0) ? error(ERR_NAMECOM) : 1;
}

int	op_exist(char *op_name)
{
	int	i;

	i = 0;
	while (i < count)
	{

	}
	else
		error(ERR_OP);
}

/*
** Arg types
** 1) Label (check existense)
** 2) DIR
** 3) INDIR
*/

int	ch_arg(t_token **temp)
{
	if ((*temp)->type == LABEL)
		ch_label_exist();
	else if ((*temp)->type == INDIRECT)
		ch_ind_arg();
	else if ((*temp)->type == DIRECT)
		ch_dir_arg();
	else
		error(ERR_ARGTP, (*temp)->x, (*temp)->y);
}

/*
** Check operation
** 1) Op name exists
** 2) Right number of args
** 3) Right format of args
*/

void		valid_instruction(t_token **temp, int *len)
{
	int		args;
	t_token	*op;

	op = *temp;
	args = g_op_tab[op_exist((*temp)->content)].args_num;
	while (args > 0)
	{
		if (!valid_arg(temp))
			error();
		args--;
	}
	op_to_code(op);
}

void	pass_label() //пропустить метку. ее проверять не надо (или надо????)
{

}

void	syntax_analiser(t_data *data)
{
	t_token	*temp;
	int		cursor;

	cursor = 0;
	write_magic(COREWAR_EXEC_MAGIC, &cursor, temp);
	temp = data->token;
	valid_champion_info(&temp, &cursor);
	while (temp)
	{
		if (temp->type == INSTRUCTION)
			valid_instruction(temp);
		else if (temp->type == LABEL)
			pass_label(&cursor);
		else
			error(ERR_SYM, temp->x, temp->y);
		temp = temp->prev;
	}
}
