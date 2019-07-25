/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fork.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rywisozk <rywisozk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/08 15:55:23 by rywisozk          #+#    #+#             */
/*   Updated: 2019/07/08 15:55:57 by rywisozk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../vm.h"

void			exec_fork(t_carriage *carr, t_game *game)
{
	t_oper		oper;
	t_carriage	*new_carry;
	int			address;

	init_oper(&oper, carr->id);
	oper.i = carr->curr_position;
	change_oper_read_pos(&oper, 1);
	oper.arg1 = get_arg_value(game, oper.i + oper.j, 2) % IDX_MOD;
	oper.is_arg1_set = true;
	oper.arg1_type = T_DIR;
	change_oper_read_pos(&oper, 2);
	new_carry = copy_carr(carr);
	address = carr->curr_position + (oper.arg1);
	new_carry->curr_position = get_new_pos(address);
	new_carry->color = carr->color;
	new_carry->id = game->carrs_count + 1;
	game->carrs_count++;
	new_carry->is_oper_executed = true;
	add_to_end(carr, new_carry);
	game->alive_carrs_count++;
	move_carr(carr, oper.move_len);
	oper.address_print = address;
	if (game->verbose)
		print_fork(game, oper);
}
