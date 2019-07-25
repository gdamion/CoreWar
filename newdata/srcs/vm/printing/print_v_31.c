/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_v_31.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmann <tmann@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/22 18:36:46 by tmann             #+#    #+#             */
/*   Updated: 2019/07/22 18:36:50 by tmann            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../vm.h"

void	print_sub(t_game *game, t_oper op)
{
	ft_printf("P% 5d | sub r%d r%d r%d\n", op.carr_id, op.arg1,
	op.arg2, op.arg3);
	print_adv(game->arena, op.i, op.move_len);
}

void	print_and(t_game *game, t_oper op)
{
	ft_printf("P% 5d | and ", op.carr_id);
	ft_printf("%d ", op.arg1);
	ft_printf("%d ", op.arg2);
	ft_printf("r%d\n", op.arg3);
	print_adv(game->arena, op.i, op.move_len);
}

void	print_or(t_game *game, t_oper op)
{
	ft_printf("P% 5d | or ", op.carr_id);
	ft_printf("%d ", op.arg1);
	ft_printf("%d r%d\n", op.arg2, op.arg3);
	print_adv(game->arena, op.i, op.move_len);
}

void	print_xor(t_game *game, t_oper op)
{
	ft_printf("P% 5d | xor ", op.carr_id);
	ft_printf("%d ", op.arg1);
	ft_printf("%d r%d\n", op.arg2, op.arg3);
	print_adv(game->arena, op.i, op.move_len);
}

void	print_fork(t_game *game, t_oper op)
{
	ft_printf("P% 5d | fork %d (%d)\n", op.carr_id, op.arg1, op.address_print);
	print_adv(game->arena, op.i, op.move_len);
}
