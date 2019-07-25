/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rywisozk <rywisozk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/08 15:57:26 by rywisozk          #+#    #+#             */
/*   Updated: 2019/07/08 15:57:28 by rywisozk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../vm.h"

void	play_turn(t_game *game, t_carriage **head)
{
	int			prev_carrs_count;
	t_carriage	*tmp;

	tmp = *head;
	while (tmp)
	{
		prev_carrs_count = game->carrs_count;
		if (tmp->is_alive == true)
		{
			if (tmp->cycles_to_use_oper == 1)
			{
				if (tmp->cycles_to_use_oper == 1 &&
				tmp->is_oper_executed == true)
					get_comand(tmp, game);
				if (tmp->cycles_to_use_oper == 1 &&
				tmp->is_oper_executed == false)
					exec_comand(tmp, game);
			}
			else
				tmp->cycles_to_use_oper--;
		}
		tmp = tmp->prev;
	}
}

void	print_dump(t_game *game, t_carriage *carr)
{
	if (!game->graphic && game->cycle_count == game->dump)
	{
		print_arena(game, (carr)->id, (carr)->curr_position);
		exit(91);
	}
}

void	start_game(t_game *game, t_carriage **carr)
{
	t_carriage	*head;

	game->cycle_count = 1;
	game->live_check_cycle = 1;
	while (game->alive_carrs_count != 0 && game->cycle_count != game->dump)
	{
		head = get_end(carr);
		if (game->verbose)
			ft_printf("It is now cycle %d\n", game->cycle_count);
		play_turn(game, &head);
		check_alive_players(game, &head);
		head = get_end(carr);
		game->cycle_count++;
		game->live_check_cycle++;
		if (game->graphic)
		{
			init_screen(game, head);
			refresh();
			process_keyboard(game, head, getch());
		}
		print_dump(game, head);
	}
	print_winner(game);
}
