/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   visual_helper5.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmann <tmann@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/22 18:34:36 by tmann             #+#    #+#             */
/*   Updated: 2019/07/22 18:37:56 by tmann            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../vm.h"

void	nclean(int count)
{
	int y;
	int x;

	getyx(stdscr, y, x);
	attron(COLOR_PAIR(22));
	while (count--)
		addch(' ');
	attroff(COLOR_PAIR(22));
	move(y, x);
}

void	draw_usage(void)
{
	int y;

	y = 3;
	move(y++, 265);
	print_bold_str("PAUSE/RUN - SPACE");
	move(++y, 260);
	print_bold_str("FOR SPEED MANAGE USE NUMPAD");
	y++;
	move(++y, 260);
	print_bold_str("  +1 - 1           -1 - 3");
	move(++y, 260);
	print_bold_str(" +10 - 4          -10 - 6");
	move(++y, 260);
	print_bold_str("+100 - 7         -100 - 9");
	y++;
	move(++y, 256);
	print_bold_str("MIN SPEED - 5 c/s MAX SPEED - 500 c/s");
}

int		find_verbose(int *ac, char **av)
{
	int i;
	int num;

	i = -1;
	num = 0;
	while (++i < *ac)
		if (ft_strequ("-v", av[i]))
		{
			delete_args(ac, av, i, 1);
			i--;
			num = 1;
		}
	return (num);
}

int		find_graphic(int *ac, char **av)
{
	int i;
	int num;

	i = -1;
	num = 0;
	while (++i < *ac)
		if (ft_strequ("-g", av[i]))
		{
			delete_args(ac, av, i, 1);
			i--;
			num = 1;
		}
	return (num);
}
