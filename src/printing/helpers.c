/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helpers.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmann <tmann@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/22 18:36:09 by tmann             #+#    #+#             */
/*   Updated: 2019/07/22 18:36:11 by tmann            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../vm.h"

void	print_all_champs(t_player **champs)
{
	int i;

	i = 0;
	while (champs[i])
	{
		ft_printf("\nChampion: %d\n", i);
		print_player_info(champs[i]);
		i++;
	}
}

int		get_champs_count(t_player **champs)
{
	int i;

	if (champs == NULL)
		return (-1);
	i = 0;
	while (champs[i])
		i++;
	return (i);
}

void	print_operation_args(t_oper oper)
{
	ft_printf("\n########## OPER INFO ##########\n");
	ft_printf("i: %d\n", oper.i);
	ft_printf("j: %d\n", oper.j);
	ft_printf("arg_byte_pos: %d\n", oper.arg_byte_pose);
	ft_printf("arg1: %d\n", oper.arg1);
	ft_printf("arg2: %d\n", oper.arg2);
	ft_printf("arg3: %d\n", oper.arg3);
	ft_printf("is_arg1_set: %d\n", oper.is_arg1_set);
	ft_printf("is_arg2_set: %d\n", oper.is_arg2_set);
	ft_printf("is_arg3_set: %d\n", oper.is_arg3_set);
	ft_printf("move_len: %d\n", oper.move_len);
}

void	check_champs_nums_and_amount(t_game *game)
{
	int i;
	int j;

	i = 0;
	while (game->champs[i])
		i++;
	if (i > 4 || i < 1)
	{
		ft_printf("Error, champs - %d. Allowed only 1 - 4 champs.\n");
		exit(-1);
	}
	j = -1;
	while (game->champs[++j])
		if (game->champs[j]->num > i)
		{
			ft_printf("Error num (%d) for -n is more than existing champs\n",
			game->champs[j]->num);
			exit(-1);
		}
	check_order(game);
}

void	check_order(t_game *game)
{
	int			i;
	t_player	*tmp;

	i = 1;
	while (game->champs[i])
	{
		if (game->champs[i - 1]->num > game->champs[i]->num)
		{
			tmp = game->champs[i];
			game->champs[i] = game->champs[i - 1];
			game->champs[i - 1] = tmp;
			i = 0;
		}
		i++;
	}
}
