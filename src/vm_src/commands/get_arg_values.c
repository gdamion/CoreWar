/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_arg_values.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdamion- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/08 15:55:29 by rywisozk          #+#    #+#             */
/*   Updated: 2019/07/27 18:52:15 by gdamion-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

void	get_t_reg_value(t_game *game, t_oper *oper, int arg_num)
{
	if (arg_num == 1)
	{
		oper->arg1 = game->arena[oper->i + oper->j];
		oper->arg1_type = T_REG;
	}
	else if (arg_num == 2)
	{
		oper->arg2 = game->arena[oper->i + oper->j];
		oper->arg2_type = T_REG;
	}
	else if (arg_num == 3)
	{
		oper->arg3 = game->arena[oper->i + oper->j];
		oper->arg3_type = T_REG;
	}
}

void	get_t_ind_value(t_game *game, t_oper *oper, int arg_num)
{
	if (arg_num == 1)
	{
		oper->arg1 = get_arg_value(game, oper->i + oper->j, 2);
		oper->arg1_type = T_IND;
	}
	else if (arg_num == 2)
	{
		oper->arg2 = get_arg_value(game, oper->i + oper->j, 2);
		oper->arg2_type = T_IND;
	}
	else if (arg_num == 3)
	{
		oper->arg3 = get_arg_value(game, oper->i + oper->j, 2);
		oper->arg3_type = T_IND;
	}
}

void	get_t_dir_short_value(t_game *game, t_oper *oper, int arg_num)
{
	if (arg_num == 1)
	{
		oper->arg1 = get_arg_value(game, oper->i + oper->j, 2);
		oper->arg1_type = T_DIR;
	}
	else if (arg_num == 2)
	{
		oper->arg2 = get_arg_value(game, oper->i + oper->j, 2);
		oper->arg2_type = T_DIR;
	}
	else if (arg_num == 3)
	{
		oper->arg3 = get_arg_value(game, oper->i + oper->j, 2);
		oper->arg3_type = T_DIR;
	}
}

void	get_t_dir_value(t_game *game, t_oper *oper, int arg_num)
{
	if (arg_num == 1)
	{
		oper->arg1 = get_arg_value(game, oper->i + oper->j, 4);
		oper->arg1_type = T_DIR;
	}
	else if (arg_num == 2)
	{
		oper->arg2 = get_arg_value(game, oper->i + oper->j, 4);
		oper->arg2_type = T_DIR;
	}
	else if (arg_num == 3)
	{
		oper->arg3 = get_arg_value(game, oper->i + oper->j, 4);
		oper->arg3_type = T_DIR;
	}
}
