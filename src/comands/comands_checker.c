/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   comands_checker.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rywisozk <rywisozk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/08 15:55:16 by rywisozk          #+#    #+#             */
/*   Updated: 2019/07/08 15:55:53 by rywisozk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../vm.h"

int		t_reg_checker(t_oper *oper, int arg_num)
{
	if (arg_num == 1)
	{
		if (oper->is_arg1_set == false || oper->arg1 <= 0 || oper->arg1 > 16)
			return (0);
		return (1);
	}
	else if (arg_num == 2)
	{
		if (oper->is_arg2_set == false || oper->arg2 <= 0 || oper->arg2 > 16)
			return (0);
		return (1);
	}
	else if (arg_num == 3)
	{
		if (oper->is_arg3_set == false || oper->arg3 <= 0 || oper->arg3 > 16)
			return (0);
		return (1);
	}
	return (0);
}

void	change_oper_read_pos(t_oper *oper, int move_count)
{
	t_oper *tmp;

	tmp = oper;
	while (move_count)
	{
		if (tmp->i + tmp->j + 1 > 4095)
		{
			tmp->i = 0;
			tmp->j = 0;
		}
		else
			tmp->j += 1;
		tmp->move_len += 1;
		move_count--;
	}
}

int		get_new_pos(int address)
{
	if (address < 0)
		address = 4095 + 1 + address;
	else if (address > 4095)
		address = address % MEM_SIZE;
	return (address);
}

void	sti_graphic(t_game *game, t_carriage *carr, int address)
{
	if (game->graphic)
	{
		game->bright_arr[address] = game->cycle_count;
		game->bright_arr[address + 1] = game->cycle_count;
		game->bright_arr[address + 2] = game->cycle_count;
		game->bright_arr[address + 3] = game->cycle_count;
		game->arena_which_champ[address] = carr->color;
		game->arena_which_champ[address + 1] = carr->color;
		game->arena_which_champ[address + 2] = carr->color;
		game->arena_which_champ[address + 3] = carr->color;
	}
}

void	st_graphic(t_game *game, t_carriage *carr, int address)
{
	if (game->graphic && address != -1)
	{
		game->bright_arr[address] = game->cycle_count;
		game->bright_arr[address + 1] = game->cycle_count;
		game->bright_arr[address + 2] = game->cycle_count;
		game->bright_arr[address + 3] = game->cycle_count;
		game->arena_which_champ[address] = carr->color;
		game->arena_which_champ[address + 1] = carr->color;
		game->arena_which_champ[address + 2] = carr->color;
		game->arena_which_champ[address + 3] = carr->color;
	}
}
