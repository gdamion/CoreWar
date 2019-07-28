/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   visual_helper3.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdamion- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/22 18:37:37 by tmann             #+#    #+#             */
/*   Updated: 2019/07/27 18:52:15 by gdamion-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

void	print_bright(unsigned char *str, int color, int i)
{
	int n;
	int y;
	int x;

	n = 4;
	if (*str == 0x01)
	{
		array_index_to_move_coord(&y, &x, i);
		move(y, x);
		attron(COLOR_PAIR(color + 10) | A_BOLD);
		printw("0%hhx", *str);
	}
	i++;
	str++;
	attron(COLOR_PAIR(color) | A_BOLD);
	while (n--)
	{
		y = i / 64 + 2;
		x = 3 * (i++ % 64) + 3;
		move(y, x);
		if (*str < 0x16)
			printw("0");
		printw(" %hhx", *str++);
	}
	attroff(COLOR_PAIR(color) | A_BOLD);
}

void	draw_curr_lives(t_game *game)
{
	int lives;
	int i;
	int total_perc;

	lives = 0;
	i = -1;
	while (++i < game->champs_count)
		lives += game->champs[i]->live_count;
	print_bold_str("[");
	if (lives == 0)
	{
		print_bold_str("------------------------");
		print_bold_str("-------------------------");
	}
	else
	{
		i = game->champs_count;
		total_perc = 49;
		while (i--)
		{
			print_hyphen_curr(game, &total_perc, lives, i);
		}
	}
	print_bold_str("]");
}

void	draw_prev_lives(t_game *game)
{
	int lives;
	int i;
	int total_perc;

	lives = 0;
	i = -1;
	while (++i < game->champs_count)
		lives += game->champs[i]->prev_live_count;
	print_bold_str("[");
	if (game->cycle_count < CYCLE_TO_DIE + 1 || !lives)
	{
		print_bold_str("------------------------");
		print_bold_str("-------------------------]");
		return ;
	}
	i = game->champs_count;
	total_perc = 49;
	while (i--)
		print_hyphen_prev(game, &total_perc, lives, i);
	print_bold_str("]");
}

void	print_hyphen_prev(t_game *game, int *total_perc, int lives, int i)
{
	int perc;

	perc = (i > 0) ? (double)game->champs[i]->prev_live_count / lives * 49.0
	: *total_perc;
	*total_perc -= perc;
	while (perc-- > 0)
		addch('-' | COLOR_PAIR(game->champs[i]->num));
}

void	print_hyphen_curr(t_game *game, int *total_perc, int lives, int i)
{
	int perc;

	perc = (i > 0) ? (double)game->champs[i]->live_count / lives * 49.0
	: *total_perc;
	*total_perc -= perc;
	while (perc-- > 0)
		addch('-' | COLOR_PAIR(game->champs[i]->num));
}
