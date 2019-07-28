/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_v_31_2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdamion- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/22 18:36:34 by tmann             #+#    #+#             */
/*   Updated: 2019/07/27 18:52:15 by gdamion-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

void	print_sti(t_game *game, t_oper op)
{
	ft_printf("P% 5d | sti r%hhd ", op.carr_id, op.arg1);
	if (op.arg2_type == T_REG)
		ft_printf("r");
	ft_printf("%d ", op.arg2);
	ft_printf("%d\n", op.arg3);
	ft_printf("%8c -> store to %d + %d ", '|', op.arg2, op.arg3);
	ft_printf("= %d (with pc and mod %d)\n", op.arg2 + op.arg3,
	op.address_print);
	print_adv(game->arena, op.i, op.move_len);
}

void	print_live(t_game *game, t_oper op, int have_player)
{
	ft_printf("P% 5d | live %d\n", op.carr_id, op.arg1);
	if (have_player != -1)
		ft_printf("Player %d (%s) is said to be alive\n",
		game->champs[have_player]->num, game->champs[have_player]->name);
	print_adv(game->arena, op.i, op.move_len);
}

void	print_ld(t_game *game, t_oper op)
{
	ft_printf("P% 5d | ld %d r%d\n", op.carr_id, op.arg1_print, op.arg2);
	print_adv(game->arena, op.i, op.move_len);
}

void	print_zjmp(t_game *game, t_carriage *carr, t_oper op)
{
	if (carr->carry == 0)
	{
		ft_printf("P% 5d | zjmp %d FAILED\n", op.carr_id, op.arg1);
		print_adv(game->arena, op.i, 3);
		return ;
	}
	ft_printf("P% 5d | zjmp %d OK\n", op.carr_id, op.arg1);
}

void	print_add(t_game *game, t_oper op)
{
	ft_printf("P% 5d | add r%d r%d r%d\n", op.carr_id,
	op.arg1, op.arg2, op.arg3);
	print_adv(game->arena, op.i, op.move_len);
}
