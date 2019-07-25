/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sub.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rywisozk <rywisozk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/08 15:57:02 by rywisozk          #+#    #+#             */
/*   Updated: 2019/07/08 15:57:05 by rywisozk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../vm.h"

static int	get_arg1(t_game *game, t_oper *oper)
{
	if (parse_args(game->arena[oper->arg_byte_pose], 1) == T_REG)
	{
		get_t_reg_value(game, oper, 1);
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

static int	get_arg3(t_game *game, t_oper *op)
{
	t_oper *oper;

	oper = op;
	if (parse_args(game->arena[oper->arg_byte_pose], 3) == T_REG)
	{
		get_t_reg_value(game, oper, 3);
		change_oper_read_pos(oper, 1);
		if (oper->arg3 <= 0 || oper->arg3 > 16)
			return (0);
	}
	else
	{
		oper->arg3_type = parse_args(game->arena[oper->arg_byte_pose], 3);
		if (oper->arg3_type == T_DIR)
			change_oper_read_pos(oper, 4);
		else if (oper->arg3_type == T_IND)
			change_oper_read_pos(oper, 2);
		else
			change_oper_read_pos(oper, 0);
		return (0);
	}
	return (1);
}

void		apply_sub(t_carriage *carr, t_oper *oper)
{
	int arg1;
	int arg2;

	arg1 = carr->regs[oper->arg1 - 1];
	arg2 = carr->regs[oper->arg2 - 1];
	if ((arg1 - arg2) == 0)
		carr->carry = 1;
	else
		carr->carry = 0;
	carr->regs[oper->arg3 - 1] = arg1 - arg2;
}

void		exec_sub(t_carriage *carr, t_game *game)
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
	err_args += get_arg3(game, &oper);
	oper.i = carr->curr_position;
	if (err_args != 3)
	{
		if (game->verbose)
			print_adv(game->arena, carr->curr_position, oper.move_len);
		move_carr(carr, oper.move_len);
		return ;
	}
	apply_sub(carr, &oper);
	move_carr(carr, oper.move_len);
	if (game->verbose)
		print_sub(game, oper);
}
