/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   brigtness.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmann <tmann@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/22 18:36:54 by tmann             #+#    #+#             */
/*   Updated: 2019/07/22 18:36:56 by tmann            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../vm.h"

int	check_bright(t_game *game, int i)
{
	int num;

	if (game->bright_arr[i] == 0)
		return (0);
	num = game->bright_arr[i];
	if (game->bright_arr[i] < 0)
		num = -game->bright_arr[i];
	if (num + 50 > game->cycle_count)
	{
		if (game->bright_arr[i] < 0)
			return (print_bright_live(game, i));
		else
			return (print_bright_st(game, i));
	}
	else
		game->bright_arr[i] = 0;
	return (0);
}

int	print_bright_live(t_game *game, int i)
{
	if (game->arena[i] < 0x10)
		printw("0");
	printw("%hhx", game->arena[i]);
	printw(" ");
	attron(COLOR_PAIR(21));
	return (1);
}

int	print_bright_st(t_game *game, int i)
{
	attron(COLOR_PAIR(game->arena_which_champ[i]) | A_BOLD);
	if (game->arena[i] < 0x10)
		printw("0");
	printw("%hhx", game->arena[i]);
	attroff(COLOR_PAIR(game->arena_which_champ[i]) | A_BOLD);
	printw(" ");
	attron(COLOR_PAIR(21));
	return (1);
}
