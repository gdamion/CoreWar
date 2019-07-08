/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   syntaxical.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdamion- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/07 13:25:02 by gdamion-          #+#    #+#             */
/*   Updated: 2019/07/08 16:10:58 by gdamion-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "com.h"

void	ch_champinfo(t_token **temp, int *len)
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
			if ((*temp)->next->type == STRING)
			{
				comment_to_code((*temp)->next->content);
				comm--;
				*temp = (*temp)->next->next;
			}
			else
				error(ERR_NO_CHCOMM);
		else if (strcmp((*temp)->content, "name"))
			if ((*temp)->next->type == STRING)
			{
				name_to_code((*temp)->next->content);
				name--;
				*temp = (*temp)->next->next;
			}
			else
				error(ERR_NO_CHNAME);
	}
	(name != 0 || comm != 0) ? error(ERR_NAMECOM) : 1;
}

int	ch_op_exist(char *op)
{

	else
		error(ERR_OP);
}

int	ch_arg()
{

}

/*
** Check operation
** 1) Op name exists
** 2) Right number of args
** 3) Right format of args
*/

void	ch_op(t_token **temp, int *len)
{
	int		i;
	int		type;
	t_token	*op;

	op = *temp;
	type = ch_op_exist((*temp)->content); //1) Op name exists
	i = g_op_tab[type].args_num;
	while (i > 0) // 2) Right number of args
	{
		if (!ch_arg(temp)) //3) Right format of args
			error();
		i--;
	}
	op_to_code(op);
}

void	pass_label() //пропустить метку. ее проверять не надо (или надо????)
{

}

void	synt_analiser(t_data *data)
{
	t_token	*temp;
	int		len;

	write_to_buff(COREWAR_EXEC_MAGIC, &len);
	len = 0;
	temp = data->token;
	ch_champinfo(&temp, &len);
	while (temp)
	{
		if (temp->type == INSTRUCTION)
			ch_op(&temp, &len);
		else if (temp->type == LABEL)
			pass_label(&len);
		else
			error(ERR_SYM);
		temp = temp->prev;
	}
}
