/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   syntaxical.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdamion- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/07 13:25:02 by gdamion-          #+#    #+#             */
/*   Updated: 2019/07/07 16:52:50 by gdamion-         ###   ########.fr       */
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

/*
** Check operation
** 1) Op name exists
** 2) Right number of args
** 3) Right format of args
*/

void	ch_op(t_token **run, int *len)
{

}

void	pass_label()
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
