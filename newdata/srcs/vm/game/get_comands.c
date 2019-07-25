/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_comands.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rywisozk <rywisozk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/08 15:57:31 by rywisozk          #+#    #+#             */
/*   Updated: 2019/07/08 15:57:32 by rywisozk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../vm.h"

int		exec_additional_comands(t_carriage *carr,
t_game *game, unsigned char exec)
{
	if (exec == XOR_CODE)
		exec_xor(carr, game);
	else if (exec == ZJMP_CODE)
		exec_zjmp(carr, game);
	else if (exec == LDI_CODE)
		exec_ldi(carr, game);
	else if (exec == STI_CODE)
		exec_sti(carr, game);
	else if (exec == FORK_CODE)
		exec_fork(carr, game);
	else if (exec == LLD_CODE)
		exec_lld(carr, game);
	else if (exec == LLDI_CODE)
		exec_lldi(carr, game);
	else if (exec == LFORK_CODE)
		exec_lfork(carr, game);
	else if (exec == AFF_CODE)
		exec_aff(carr, game);
	else
	{
		move_carr(carr, 1);
	}
	return (1);
}

void	exec_comand(t_carriage *carr, t_game *game)
{
	unsigned char exec;

	exec = carr->oper_code;
	if (exec == LIVE_CODE)
		exec_live(carr, game);
	else if (exec == LD_CODE)
		exec_ld(carr, game);
	else if (exec == ST_CODE)
		exec_st(carr, game);
	else if (exec == ADD_CODE)
		exec_add(carr, game);
	else if (exec == SUB_CODE)
		exec_sub(carr, game);
	else if (exec == AND_CODE)
		exec_and(carr, game);
	else if (exec == OR_CODE)
		exec_or(carr, game);
	else if (exec_additional_comands(carr, game, exec))
		;
	carr->is_oper_executed = true;
	if (game->graphic)
		init_screen(game, carr);
}

void	set_comand_code(t_carriage *carr, unsigned char oper_code,
	int cycles_to_use_oper)
{
	carr->oper_code = oper_code;
	carr->cycles_to_use_oper = cycles_to_use_oper;
}

int		get_additional_comands(t_carriage *carr, unsigned char exec)
{
	if (exec == XOR_CODE)
		set_comand_code(carr, XOR_CODE, XOR_CYCLE_CD - 1);
	else if (exec == ZJMP_CODE)
		set_comand_code(carr, ZJMP_CODE, ZJMP_CYCLE_CD - 1);
	else if (exec == LDI_CODE)
		set_comand_code(carr, LDI_CODE, LDI_CYCLE_CD - 1);
	else if (exec == STI_CODE)
		set_comand_code(carr, STI_CODE, STI_CYCLE_CD - 1);
	else if (exec == FORK_CODE)
		set_comand_code(carr, FORK_CODE, FORK_CYCLE_CD - 1);
	else if (exec == LLD_CODE)
		set_comand_code(carr, LLD_CODE, LLD_CYCLE_CD - 1);
	else if (exec == LLDI_CODE)
		set_comand_code(carr, LLDI_CODE, LLDI_CYCLE_CD - 1);
	else if (exec == LFORK_CODE)
		set_comand_code(carr, LFORK_CODE, LFORK_CYCLE_CD - 1);
	else if (exec == AFF_CODE)
		set_comand_code(carr, AFF_CODE, AFF_CYCLE_CD - 1);
	else
	{
		carr->oper_code = exec;
		move_carr(carr, 1);
		carr->is_oper_executed = true;
	}
	return (1);
}

void	get_comand(t_carriage *carr, t_game *game)
{
	unsigned char exec;

	exec = game->arena[carr->curr_position];
	carr->is_oper_executed = false;
	if (exec == LIVE_CODE)
		set_comand_code(carr, LIVE_CODE, LIVE_CYCLE_CD - 1);
	else if (exec == LD_CODE)
		set_comand_code(carr, LD_CODE, LD_CYCLE_CD - 1);
	else if (exec == ST_CODE)
		set_comand_code(carr, ST_CODE, ST_CYCLE_CD - 1);
	else if (exec == ADD_CODE)
		set_comand_code(carr, ADD_CODE, ADD_CYCLE_CD - 1);
	else if (exec == SUB_CODE)
		set_comand_code(carr, SUB_CODE, SUB_CYCLE_CD - 1);
	else if (exec == AND_CODE)
		set_comand_code(carr, AND_CODE, AND_CYCLE_CD - 1);
	else if (exec == OR_CODE)
		set_comand_code(carr, OR_CODE, OR_CYCLE_CD - 1);
	else if (get_additional_comands(carr, exec))
		;
}
