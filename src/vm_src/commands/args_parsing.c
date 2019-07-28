/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   args_parsing.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdamion- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/08 15:55:11 by rywisozk          #+#    #+#             */
/*   Updated: 2019/07/27 18:52:15 by gdamion-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

int		parse_args(char byte, int arg)
{
	int bitwise;

	bitwise = 0;
	if (arg < 1 || arg > 3)
		return (0);
	if (arg == 1)
		bitwise = 6;
	else if (arg == 2)
		bitwise = 4;
	else if (arg == 3)
		bitwise = 2;
	if (byte & 1 << bitwise && byte & 1 << (bitwise + 1))
		return (T_IND);
	else if (byte & 1 << bitwise)
		return (T_REG);
	else if (byte & 2 << bitwise)
		return (T_DIR);
	return (0);
}

int		get_arg_value(t_game *game, int i, int arg_size)
{
	int reg_value;
	int k;
	int buf;
	int negative;

	reg_value = 0;
	k = arg_size - 1;
	buf = 0;
	negative = 0;
	if (game->arena[i] & (1 << 7))
		negative = 1;
	while (k >= 0)
	{
		buf = game->arena[i];
		i = move_arg(i, 1);
		buf = buf << (8 * k);
		reg_value = reg_value | buf;
		k--;
	}
	if (arg_size == 2)
		return ((short)reg_value);
	return (reg_value);
}

void	place_bytes(t_game *game, int address, int arg)
{
	int	i;
	int	k;

	i = arg;
	k = 3;
	while (k >= 0)
	{
		game->arena[address] = (i >> (k * 8));
		k--;
		address = move_arg(address, 1);
	}
}

void	move_carr(t_carriage *carr, int move_count)
{
	int		address;

	address = get_new_pos(carr->curr_position + move_count);
	carr->curr_position = address;
}

int		move_arg(int curr_pos, int move_count)
{
	int		address;

	address = get_new_pos(curr_pos + move_count);
	return (address);
}
