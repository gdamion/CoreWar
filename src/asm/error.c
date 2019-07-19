/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdamion- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/06 11:57:52 by gdamion-          #+#    #+#             */
/*   Updated: 2019/07/19 13:58:32 by gdamion-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "com.h"

void		terminate(char *massage, char *line, int x)
{
	if (errno == 0)
		ft_putstr_fd(massage, 2);
	else
		perror(massage);
	ft_putstr_fd(YELLOW, 2);
	ft_putstr_fd("  Token type: ", 2);
	ft_putendl_fd(g_token_type[g_data->token->type + 1], 2);
	ft_putendl_fd(EOC, 2);
	write(2, line, x);
	ft_putstr_fd(RED, 2);
	write(2, line + x, g_data->x - x + 1);
	ft_putstr_fd(EOC, 2);
	ft_putendl_fd(line + g_data->x + 1, 2);
}

void		terminate1(char *massage, t_token *token)
{
	if (errno == 0)
		ft_putstr_fd(massage, 2);
	else
		perror(massage);
	ft_putstr_fd(YELLOW, 2);
	ft_putstr_fd("  Token type: ", 2);
	ft_putendl_fd(g_token_type[token->type + 1], 2);
	ft_putendl_fd(EOC, 2);
	ft_putstr_fd("	... ", 2);
	ft_putstr_fd(RED, 2);
	ft_putstr_fd(token->content, 2);
	ft_putstr_fd(EOC, 2);
	ft_putendl_fd(" ...\n", 2);
}

static void	place_write(int x, int y)
{
	ft_putendl_fd("", 2);
	ft_putstr_fd(BLUE, 2);
	ft_putstr_fd(g_data->filename, 2);
	ft_putstr_fd(EOC, 2);
	write(2, ":\n", 2);
	ft_putstr_fd(YELLOW, 2);
	write(2, "Ln ", 3);
	ft_putnbr_fd(y, 2);
	write(2, ", Col ", 6);
	ft_putnbr_fd(x, 2);
	ft_putstr_fd(EOC, 2);
	write(2, ": ", 2);
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
	if (data->token)
		free_token(data->token);
	if (data->label)
		free_label(data->label);
	free(data);
}

void		errorr(char *event)
{
	if (g_data && g_data->x != -1 && g_data->y != -1)
		place_write(g_data->x, g_data->y);
	ft_putstr_fd(RED, 2);
	print_error(event);
	if (g_data->fd)
		close(g_data->fd);
	free_data(g_data);
	exit(1);
}

void		error_log(char *event, char *line, int x)
{
	if (g_data && g_data->x != -1 && g_data->y != -1)
		place_write(g_data->x, g_data->y);
	terminate(event, line, x);
	if (g_data->fd)
		close(g_data->fd);
	// free_data(g_data);
	exit(1);
}

void		log_error(char *event, t_token *token)
{
	if (token->x != -1 && token->y != -1)
		place_write(token->x, token->y);
	terminate1(event, token);
	if (g_data->fd)
		close(g_data->fd);
	// free_data(g_data);
	exit(1);
}
