/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_v_31_3.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmann <tmann@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/22 18:36:40 by tmann             #+#    #+#             */
/*   Updated: 2019/07/22 18:36:41 by tmann            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../vm.h"

void	print_st(t_game *game, t_oper op)
{
	ft_printf("P% 5d | st r%d ", op.carr_id, op.arg1);
	ft_printf("%d\n", op.arg2);
	print_adv(game->arena, op.i, op.move_len);
}

void	print_ldi(t_game *game, t_oper op)
{
	ft_printf("P% 5d | ldi ", op.carr_id);
	if (op.arg1 == T_REG)
		ft_printf("r");
	ft_printf("%d ", op.arg1);
	if (op.arg2 == T_REG)
		ft_printf("r");
	ft_printf("%d r%d\n", op.arg2, op.arg3);
	ft_printf("%8s -> load from %d + %d = %d (with pc and mod %d)\n",
	"|", op.arg1, op.arg2, op.arg1 + op.arg2, op.address_print);
	print_adv(game->arena, op.i, op.move_len);
}

void	print_lld(t_game *game, t_oper op)
{
	ft_printf("P% 5d | lld %hhd r%d\n", op.carr_id, op.arg1, op.arg2);
	print_adv(game->arena, op.i, op.move_len);
}

void	print_lldi(t_game *game, t_oper op)
{
	ft_printf("P% 5d | lldi %hhd r%d\n", op.carr_id, op.arg1, op.arg2);
	print_adv(game->arena, op.i, op.move_len);
}

void	print_lfork(t_game *game, t_oper op)
{
	ft_printf("P% 5d | lfork %d (%d)\n", op.carr_id, op.arg1, op.address_print);
	print_adv(game->arena, op.i, op.move_len);
}
