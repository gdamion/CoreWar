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

void	ch_champinfo(t_token **run, int *len)
{
	int i;
	int name;
	int comm;

	name = 1;
	comm = 1;
	i = 2;
	while (i)
	{
		if (strcmp((*run)->content, "comment"))
			if ((*run)->next->type == STRING)
			{
				comment_to_code((*run)->next->content);
				comm--;
				*run = (*run)->next->next;
			}
			else
				error(ERR_NO_CHCOMM);
		else if (strcmp((*run)->content, "name"))
			if ((*run)->next->type == STRING)
			{
				name_to_code((*run)->next->content);
				name--;
				*run = (*run)->next->next;
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

void	ch_op(t_token **run, int *len)
{
	int		i;
	int		type;
	t_token	*op;

	op = *run;
	type = ch_op_exist((*run)->content); //1) Op name exists
	i = g_op_tab[type].args_num;
	while (i > 0) // 2) Right number of args
	{
		if (!ch_arg(run)) //3) Right format of args
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
	t_token	*run;
	int		len;

	write_to_buff(COREWAR_EXEC_MAGIC, &len);
	len = 0;
	run = data->token;
	ch_champinfo(&run, &len);
	while (run)
	{
		if (run->type == INSTRUCTION)
			ch_op(&run, &len);
		else if (run->type == LABEL)
			pass_label(&len);
		else
			error(ERR_SYM);
		run = run->prev;
	}
}
