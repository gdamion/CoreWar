/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   zjmp.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rywisozk <rywisozk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/08 15:57:17 by rywisozk          #+#    #+#             */
/*   Updated: 2019/07/08 15:57:19 by rywisozk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../vm.h"

void	exec_zjmp(t_carriage *carr, t_game *game)
{
	t_oper oper;

	init_oper(&oper, carr->id);
	oper.i = carr->curr_position;
	change_oper_read_pos(&oper, 1);
	oper.arg1 = get_arg_value(game, oper.i + oper.j, 2);
	oper.is_arg1_set = true;
	oper.arg1_type = T_DIR;
	oper.move_len = 3;
	oper.i = carr->curr_position;
	if (carr->carry == 1)
	{
		oper.move_len = get_new_pos(carr->curr_position + oper.arg1 % IDX_MOD);
		carr->curr_position = oper.move_len;
	}
	else if (carr->carry == 0)
		move_carr(carr, 3);
	if (game->verbose)
		print_zjmp(game, carr, oper);
}
