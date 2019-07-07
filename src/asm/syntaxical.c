/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   syntaxical.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdamion- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/07 13:25:02 by gdamion-          #+#    #+#             */
/*   Updated: 2019/07/07 14:45:54 by gdamion-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "com.h"

void	ch_champinfo(t_token **run, int *len)
{

}

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
