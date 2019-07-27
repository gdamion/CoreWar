/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdamion- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/06 11:57:52 by gdamion-          #+#    #+#             */
/*   Updated: 2019/07/24 19:46:12 by gdamion-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "com.h"

void	error_event(char *event, _Bool var)
{
	if (var && g_data
		&& g_data->x != -1 && g_data->y != -1)
		print_place(g_data->x, g_data->y);
	else if (g_data && g_data->filename)
		print_filename();
	ft_putstr_fd("    ", 2);
	ft_putstr_fd(RED, 2);
	print_error(event);
	if (g_data->fd)
		close(g_data->fd);
	if (g_buf)
		free(g_buf);
	if (g_data)
		free_data();
	exit(1);
}

void	error_line(char *event, char *line, int x)
{
	if (g_data && g_data->x != -1 && g_data->y != -1)
		print_place(g_data->x, g_data->y);
	print_line_error(event, line, x);
	if (g_data->fd)
		close(g_data->fd);
	if (g_buf)
		free(g_buf);
	if (g_data)
		free_data();
	exit(1);
}

void	error_token(char *event, t_token *token)
{
	if (token->x != -1 && token->y != -1)
		print_place(token->x, token->y);
	print_token_error(event, token);
	if (g_data->fd)
		close(g_data->fd);
	if (g_buf)
		free(g_buf);
	if (g_data)
		free_data();
	exit(1);
}
