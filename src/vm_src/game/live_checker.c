/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   live_checker.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdamion- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/08 15:57:35 by rywisozk          #+#    #+#             */
/*   Updated: 2019/07/27 18:52:15 by gdamion-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

int			get_current_live_checks(t_carriage **head)
{
	t_carriage	*tmp;
	int			curr_live_count;

	tmp = *head;
	curr_live_count = 0;
	while (tmp)
	{
		if (tmp->is_alive == true)
		{
			if (tmp->oper_code == LIVE_CODE &&
			tmp->cycles_to_use_oper == 1 && tmp->is_oper_executed == false)
				curr_live_count++;
		}
		tmp = tmp->prev;
	}
	return (curr_live_count);
}

void		kill_carrs(t_game *game, t_carriage **head)
{
	t_carriage *tmp;

	tmp = *head;
	while (tmp)
	{
		if (tmp->is_alive == true)
		{
			if (tmp->last_live_check <= game->cycle_count - game->cycle_to_die)
			{
				if (game->verbose)
					print_carr_dead(tmp->id,
				game->cycle_count - tmp->last_live_check, game->cycle_to_die);
				tmp->is_alive = false;
				game->alive_carrs_count--;
			}
		}
		tmp = tmp->prev;
	}
}

void		kill_carrs_after_zero(t_game *game, t_carriage **head)
{
	t_carriage *tmp;

	tmp = *head;
	while (tmp)
	{
		if (tmp->is_alive == true)
		{
			if (game->verbose)
				print_carr_dead(tmp->id,
			game->cycle_count - tmp->last_live_check, game->cycle_to_die);
			tmp->is_alive = false;
			game->alive_carrs_count--;
		}
		tmp = tmp->prev;
	}
}

void		check_alive_after_zero_cycles_to_die(t_game *game, t_carriage **h)
{
	kill_carrs_after_zero(game, h);
	if (game->live_checks_count + get_current_live_checks(h) >= NBR_LIVE
	|| (game->count_of_live_checks + 1) >= MAX_CHECKS)
	{
		game->cycle_to_die -= CYCLE_DELTA;
		if (game->verbose)
			ft_printf("Cycle to die is now %d\n", game->cycle_to_die);
		game->count_of_live_checks = 0;
	}
	else
		game->count_of_live_checks++;
	reset_live_count_of_players(game);
	game->live_checks_count = 0;
	game->live_check_cycle = 1;
}

void		check_alive_players(t_game *game, t_carriage **head)
{
	if (game->live_check_cycle - game->is_first_die_cycle == game->cycle_to_die)
	{
		game->is_first_die_cycle = 1;
		kill_carrs(game, head);
		game->live_check_cycle = 1;
		if (game->live_checks_count + get_current_live_checks(head) >= NBR_LIVE
		|| ((game->count_of_live_checks + 1) >= MAX_CHECKS))
		{
			game->cycle_to_die -= CYCLE_DELTA;
			if (game->verbose)
				ft_printf("Cycle to die is now %d\n", game->cycle_to_die);
			game->count_of_live_checks = 0;
		}
		else
			game->count_of_live_checks++;
		game->live_checks_count = 0;
		reset_live_count_of_players(game);
	}
	else if (game->cycle_to_die <= 0)
		check_alive_after_zero_cycles_to_die(game, head);
}
