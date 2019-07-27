/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lld.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdamion- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/08 15:56:32 by rywisozk          #+#    #+#             */
/*   Updated: 2019/07/27 18:52:15 by gdamion-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

static int	get_arg1(t_game *game, t_oper *oper)
{
	if (parse_args(game->arena[oper->arg_byte_pose], 1) == T_DIR)
	{
		get_t_dir_value(game, oper, 1);
		change_oper_read_pos(oper, 4);
	}
	else if (parse_args(game->arena[oper->arg_byte_pose], 1) == T_IND)
	{
		get_t_ind_value(game, oper, 1);
		change_oper_read_pos(oper, 2);
	}
	else
	{
		oper->arg1_type = parse_args(game->arena[oper->arg_byte_pose], 1);
		if (oper->arg1_type == T_REG)
			change_oper_read_pos(oper, 1);
		else
			change_oper_read_pos(oper, 1);
		return (0);
	}
	return (1);
}

static int	get_arg2(t_game *game, t_oper *op)
{
	t_oper *oper;

	oper = op;
	if (parse_args(game->arena[oper->arg_byte_pose], 2) == T_REG)
	{
		get_t_reg_value(game, oper, 2);
		change_oper_read_pos(oper, 1);
		if (oper->arg2 <= 0 || oper->arg2 > 16)
			return (0);
	}
	else
	{
		oper->arg2_type = parse_args(game->arena[oper->arg_byte_pose], 2);
		if (oper->arg2_type == T_DIR)
			change_oper_read_pos(oper, 4);
		else if (oper->arg2_type == T_IND)
			change_oper_read_pos(oper, 2);
		else
			change_oper_read_pos(oper, 0);
		return (0);
	}
	return (1);
}

void		apply_lld(t_carriage *carr, t_game *game, t_oper *oper)
{
	t_oper	*tmp;
	int		arg;

	tmp = oper;
	arg = oper->arg1;
	if (oper->arg1_type == T_IND)
		arg = get_arg_value(game, carr->curr_position + arg, 4);
	if (arg == 0)
		carr->carry = 1;
	else if (arg != 0)
		carr->carry = 0;
	carr->regs[oper->arg2] = arg;
}

void		exec_lld(t_carriage *carr, t_game *game)
{
	t_oper	oper;
	int		err_args;

	err_args = 0;
	init_oper(&oper, carr->id);
	oper.i = carr->curr_position;
	oper.arg_byte_pose = move_arg(oper.i, 1);
	change_oper_read_pos(&oper, 2);
	err_args += get_arg1(game, &oper);
	err_args += get_arg2(game, &oper);
	oper.i = carr->curr_position;
	if (err_args != 2)
	{
		if (game->verbose)
			print_adv(game->arena, carr->curr_position, oper.move_len);
		move_carr(carr, oper.move_len);
		return ;
	}
	apply_lld(carr, game, &oper);
	move_carr(carr, oper.move_len);
	if (game->verbose)
		print_lld(game, oper);
}
