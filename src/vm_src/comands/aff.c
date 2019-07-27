/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   aff.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdamion- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/08 15:55:00 by rywisozk          #+#    #+#             */
/*   Updated: 2019/07/27 18:52:15 by gdamion-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

static int	get_arg1(t_game *game, t_oper *oper)
{
	if (parse_args(game->arena[oper->arg_byte_pose], 1) == T_REG)
	{
		get_t_reg_value(game, oper, 1);
		oper->arg1_type = T_REG;
		change_oper_read_pos(oper, 1);
		if (oper->arg1 <= 0 || oper->arg1 > 16)
			return (0);
	}
	else
	{
		oper->arg1_type = parse_args(game->arena[oper->arg_byte_pose], 1);
		if (oper->arg1_type == T_DIR)
			change_oper_read_pos(oper, 4);
		else if (oper->arg1_type == T_IND)
			change_oper_read_pos(oper, 2);
		else
			change_oper_read_pos(oper, 0);
		return (0);
	}
	return (1);
}

void		exec_aff(t_carriage *carr, t_game *game)
{
	t_oper	oper;
	int		err_args;

	err_args = 0;
	init_oper(&oper, carr->id);
	oper.i = carr->curr_position;
	oper.arg_byte_pose = move_arg(oper.i, 1);
	change_oper_read_pos(&oper, 1);
	err_args += get_arg1(game, &oper);
	if (err_args == 1)
	{
		if (game->verbose)
			ft_printf("%c\n", carr->regs[oper.arg1 - 1]);
		if (game->verbose)
			print_adv(game->arena, carr->curr_position, oper.move_len);
		move_carr(carr, oper.move_len);
	}
	else
		move_carr(carr, oper.move_len);
}
