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

void	errorr(char *event, int str_no, int col_no)
{
	char *place;

	place_write(str_no, col_no);
	ft_putendl_fd(place, 2);
	print_error(event);
	g_data->fd ? fclose(g_data->fd) : 1;
	free_info(g_data);
	exit(1);
}

void	place_write(int str_no, int col_no)
{
	write(2, "\nLn ", 5);
	ft_putnbr(str_no);
	write(2, ", Col:", 6);
	ft_putnbr(col_no);
	write(2, '\n', 1);
}

void	free_info(t_data *data)
{

}
