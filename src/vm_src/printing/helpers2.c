/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helpers2.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdamion- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/22 18:36:15 by tmann             #+#    #+#             */
/*   Updated: 2019/07/27 18:52:15 by gdamion-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

void	print_binary_file(t_binary_r *file)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (i < file->size)
	{
		ft_printf("%hhx", file->arr[i]);
		j++;
		i++;
		if (j == 32)
		{
			ft_printf("\n");
			j = 0;
		}
	}
	ft_printf("\n");
}

void	print_player_info(t_player *player)
{
	int	i;

	i = -1;
	ft_printf("\n");
	ft_printf("player number - %d\n", player->num);
	ft_printf("name - %s\n", player->name);
	ft_printf("comment - %s\n", player->comment);
	ft_printf("exec_size - %d\n", player->exec_size);
	ft_printf("exec_code - ");
	while (++i < player->exec_size)
		ft_printf("%hhx", player->exec[i]);
	ft_printf("\n");
}

void	print_game_info(t_game *game)
{
	ft_printf("\n");
	ft_printf("game->arena_size - %d\n", game->arena_size);
	ft_printf("game->champs_count - %d\n", game->champs_count);
	ft_printf("\n");
}

void	print_arena(t_game *game, int carr_id, int carr_pos)
{
	int		i;
	int		j;

	i = 0;
	j = 0;
	while (i < MEM_SIZE)
	{
		if (j == 0 && i % 32 == 0)
			(i == 0) ? ft_printf("0x0000 : ") : ft_printf("%#.4x : ", i);
		if (carr_id && carr_pos == i && game->arena[i] < 16)
			ft_printf("0");
		else if (game->arena[i] < 16)
			ft_printf("0");
		ft_printf("%hhx ", game->arena[i]);
		i++;
		j++;
		if (j == 32)
		{
			j = 0;
			ft_printf("\n");
		}
	}
}
