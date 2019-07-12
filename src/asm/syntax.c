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

void	valid_champion_info(t_token **temp)
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
				write_name((*temp)->next->content, 8);
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
				write_comment((*temp)->next->content, 8 + PROG_NAME_LENGTH * 2 + 8 * 2);
				name--;
				*temp = (*temp)->next->next;
			}
			else
				error(ERR_NO_CHNAME);
		}
	}
	(name != 0 || comm != 0) ? error(ERR_NAMECOM) : 1;
}

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
		return (-1);
	return (i);
}

/*
** Arg types
** 1) Label (check existense)
** 2) DIR
** 3) INDIR
*/

int		valid_arg(t_token *arg, int mask) //!!! а что если тип будет LABEL???
{
	if (arg->type != (arg->type & mask) && arg->type != LABEL)
		errorr(ERR_ARGTP, arg->x, arg->y);
}

/*
** Check operation
** 1) Op name exists
** 2) Right number of args
** 3) Right format of args
*/

void	valid_instruction(t_token **operations)
{
	int				op_n;
	unsigned int	args;
	unsigned int	*types;
	t_token			*temp;

	temp = (*operations)->next;
	(op_n = op_exist(temp->content)) == -1 ? \
		errorr(ERR_OP, temp->x, temp->y) : 1;
	args = g_op_tab[op_n].args_num;
	types = g_op_tab[op_n].args_types;
	while ((temp->type < 3 || temp->type == 4) && args--)
	{
		valid_arg(temp, (*types)++);
		(temp->next->type != SEPARATOR) ? errorr(ERR_TOKEN, \
			temp->next->x, temp->next->y) : (temp = temp->next->next);
	}
	(args || args < 0) ? errorr(ERR_ARGNO, temp->x, temp->y) : 1;
}

void	valid_label() //проверить, что такая метка содержит правильные символы, что название не повторяется добавить ее в список???
{

}

int		syntax_analiser(t_data *data) //return exec code size in bytes
{
	t_token	*temp;
	t_token *op;

	while (temp)
	{
		if (temp->type == INSTRUCTION)
			valid_instruction(&temp);
		else if (temp->type == LABEL)
		{
			valid_label(/*&cursor*/);
			temp = temp->next;
		}
		else
			errorr(ERR_SYM, temp->x, temp->y);
		temp = temp->prev;
	}
}
