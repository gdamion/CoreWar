/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   visual_helper4.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdamion- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/22 18:37:48 by tmann             #+#    #+#             */
/*   Updated: 2019/07/27 18:52:15 by gdamion-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

void		print_bold_str(char *str)
{
	int i;

	i = 0;
	while (*str && i < 40)
	{
		addch(*str | A_BOLD);
		str++;
		i++;
	}
}

void		print_nbr_ncurses(int num)
{
	if (num > 9)
		print_nbr_ncurses(num / 10);
	addch(num % 10 + 48 | A_BOLD);
}

void		prepare_screen(void)
{
	initscr();
	start_color();
	cbreak();
	nodelay(stdscr, TRUE);
	init_colors();
	noecho();
	move(0, 0);
	draw_borders();
	draw_usage();
}

void		init_colors(void)
{
	init_pair(10, COLOR_WHITE, COLOR_WHITE);
	init_pair(21, COLOR_WHITE, COLOR_BLACK);
	init_pair(22, COLOR_BLACK, COLOR_BLACK);
	init_pair(1, COLOR_GREEN, COLOR_BLACK);
	init_pair(2, COLOR_BLUE, COLOR_BLACK);
	init_pair(3, COLOR_RED, COLOR_BLACK);
	init_pair(4, COLOR_CYAN, COLOR_BLACK);
	init_pair(5, COLOR_BLACK, COLOR_GREEN);
	init_pair(6, COLOR_BLACK, COLOR_BLUE);
	init_pair(7, COLOR_BLACK, COLOR_RED);
	init_pair(8, COLOR_BLACK, COLOR_CYAN);
	init_pair(11, COLOR_WHITE, COLOR_GREEN);
	init_pair(12, COLOR_WHITE, COLOR_BLUE);
	init_pair(13, COLOR_WHITE, COLOR_RED);
	init_pair(14, COLOR_WHITE, COLOR_CYAN);
}

void		draw_borders(void)
{
	int i;

	i = -1;
	while (++i < 254)
	{
		move(0, i);
		addch('*' | COLOR_PAIR(10));
		move(67, i);
		addch('*' | COLOR_PAIR(10));
	}
	i = 0;
	while (++i < 68)
	{
		move(i, 0);
		addch('*' | COLOR_PAIR(10));
		move(i, 198);
		addch('*' | COLOR_PAIR(10));
		move(i, 253);
		if (i != 67)
			addch('*' | COLOR_PAIR(10));
	}
}
