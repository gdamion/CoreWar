/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_msgs.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdamion- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/20 21:10:58 by gdamion-          #+#    #+#             */
/*   Updated: 2019/07/20 22:47:36 by gdamion-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "com.h"

static void	description_token(char *message, t_token *token)
{
	if (errno == 0)
		ft_putstr_fd(message, 2);
	else
		perror(message);
	ft_putstr_fd(YELLOW, 2);
	ft_putstr_fd("  Token type: ", 2);
	ft_putendl_fd(g_token_type[token->type + 1], 2);
	ft_putendl_fd(EOC, 2);
}

void	print_line_error(char *message, char *line, int x)
{
	description_token(message, g_data->token);
	write(2, line, x);
	ft_putstr_fd(RED, 2);
	write(2, line + x, g_data->x - x + 1);
	ft_putstr_fd(EOC, 2);
	ft_putendl_fd(line + g_data->x + 1, 2);
}

void	print_token_error(char *message, t_token *token)
{
	description_token(message, token);
	ft_putstr_fd("	... ", 2);
	ft_putstr_fd(RED, 2);
	ft_putstr_fd(token->content, 2);
	ft_putstr_fd(EOC, 2);
	ft_putendl_fd(" ...\n", 2);
}

void	print_filename(void)
{
	if (!g_data->filename)
		return ;
	ft_putendl_fd("", 2);
	ft_putstr_fd(BLUE, 2);
	ft_putstr_fd(g_data->filename, 2);
	ft_putstr_fd(EOC, 2);
	write(2, ":\n", 2);
}

void	print_error_info(int x, int y)
{
	if (!g_data || g_data->x == -1 || g_data->y == -1)
		return ;
	print_filename();
	ft_putstr_fd(YELLOW, 2);
	write(2, "Ln ", 3);
	ft_putnbr_fd(y, 2);
	write(2, ", Col ", 6);
	ft_putnbr_fd(x, 2);
	ft_putstr_fd(EOC, 2);
	write(2, ": ", 2);
}
