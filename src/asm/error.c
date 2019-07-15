/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdamion- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/06 11:57:52 by gdamion-          #+#    #+#             */
/*   Updated: 2019/07/12 19:01:32 by gdamion-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "com.h"

void	errorr(char *event, int y, int x)
{
	char *place;

	place_write(y, x);
	ft_putendl_fd(place, 2);
	print_error(event);
	if (g_data->fd)
		close(g_data->fd);
	free_info();
	exit(1);
}

void	place_write(int y, int x)
{
	write(2, "\nLn ", 5);
	ft_putnbr(y);
	write(2, ", Col:", 6);
	ft_putnbr(x);
	write(2, "\n", 1);
}

void	free_info(void)
{

}
