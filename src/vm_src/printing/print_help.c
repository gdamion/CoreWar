/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_help.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdamion- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/22 18:36:29 by tmann             #+#    #+#             */
/*   Updated: 2019/07/27 18:52:15 by gdamion-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

void	introduce_players(t_game *game)
{
	int i;

	i = 0;
	if (game->graphic)
		return ;
	ft_printf("Introducing contestants...\n");
	while (i < game->champs_count)
	{
		ft_printf("* Player %d, weighing %d bytes, \"%s\" (\"%s\") !\n",
		game->champs[i]->num, game->champs[i]->exec_size,
		game->champs[i]->name, game->champs[i]->comment);
		i++;
	}
}

void	print_adv(unsigned char *arena, int begin, int len)
{
	ft_printf("ADV %d (", len);
	begin == 0 ? ft_printf("0x0000 -> ") : ft_printf("%#.4x -> ", begin);
	if (((begin + len) % MEM_SIZE) == 0)
		ft_printf("0x0000) ");
	else if ((begin + len) % MEM_SIZE < begin)
		ft_printf("0x1%.3x) ", (begin + len) % 4096);
	else
		ft_printf("%#.4x) ", (begin + len) % 4096);
	while (len--)
	{
		ft_printf("%02hhx ", arena[begin]);
		begin = (begin + 1) % 4096;
	}
	ft_printf("\n");
}

void	print_carr_dead(int process, int cycles_dead, int cycles_to_die)
{
	ft_printf("Process %d hasn't lived for %d cycles (CTD %d)\n",
	process, cycles_dead, cycles_to_die);
}

void	print_winner(t_game *game)
{
	if (game->graphic)
	{
		attron(COLOR_PAIR(game->winner_num + 1));
		move(return_y(game->game_info) + 6, return_x(CYCLE_PER_SEC));
		print_bold_str("Contestant ");
		print_nbr_ncurses(game->winner_num + 1);
		print_bold_str(", \"");
		print_bold_str(game->champs[game->winner_num]->name);
		print_bold_str("\", has won !");
		while (1)
			end_game(getch());
	}
	else
		ft_printf("Contestant %d, \"%s\", has won !\n",
		game->winner_num + 1, game->champs[game->winner_num]->name);
}

void	end_game(char ch)
{
	int i;

	move(0, 0);
	i = -1;
	while (++i < 10)
		print_bold_str("PRESS SPACE FOR AU REVOIR ");
	move(67, 0);
	i = -1;
	while (++i < 10)
		print_bold_str("PRESS SPACE FOR AU REVOIR ");
	i = -1;
	if (ch == ' ')
	{
		endwin();
		exit(1);
	}
}
