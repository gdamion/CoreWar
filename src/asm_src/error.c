/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdamion- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/06 11:57:52 by gdamion-          #+#    #+#             */
/*   Updated: 2019/07/28 20:02:51 by gdamion-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "com.h"

void	error_event(char *event)
{
	ft_putstr_fd(RED, 2);
	print_error(event);
	free_data();
}

void	error_line(char *event, char *line, int x)
{
	print_error_info(g_data->x, g_data->y);
	print_line_error(event, line, x);
	ft_strdel(&line);
	free_data();
}

void	error_token(char *event, t_token *token)
{
	print_error_info(token->x, token->y);
	print_token_error(event, token);
	free_data();
}
