/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdamion- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/06 11:57:52 by gdamion-          #+#    #+#             */
/*   Updated: 2019/07/17 13:30:31 by gdamion-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "com.h"

static void	place_write(int y, int x)
{
	write(2, "Ln ", 4);
	ft_putnbr_fd(y, 2);
	write(2, ", Col ", 6);
	ft_putnbr_fd(x, 2);
}

static void	free_token(t_token *token)
{
	t_token	*temp;

	while (token)
	{
		free(token->content);
		temp = token;
		token = token->prev;
		free(temp);
	}
}

static void	free_label(t_label *label)
{
	t_label	*temp;

	while (label)
	{
		temp = label;
		label = label->next;
		free(temp);
	}
}

void		free_data(t_data *data)
{
	if (data->filename)
		free(data->filename);
	if (data->token)
		free_token(data->token);
	if (data->label)
		free_label(data->label);
	free(data);
}

void		errorr(char *event, int y, int x)
{
	if (x != -1 && y != -1)
	{
		place_write(y, x);
		write(2, "\n", 2);
	}
	print_error(event);
	if (g_data->fd)
		close(g_data->fd);
	free_data(g_data);
	exit(1);
}
