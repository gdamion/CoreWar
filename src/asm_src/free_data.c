/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_data.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdamion- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/20 21:07:21 by gdamion-          #+#    #+#             */
/*   Updated: 2019/07/27 16:58:48 by gdamion-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "com.h"

static void	free_token(t_token **token)
{
	t_token	*temp;

	if (!token)
		return ;
	if ((*token)->prev)
		while ((*token)->prev)
			*token = (*token)->prev;
	while (*token)
	{
		temp = *token;
		*token = (*token)->next;
		if (temp->content)
			ft_strdel(&temp->content);
		free(temp);
	}
}

static void	free_label(t_label **label)
{
	t_label	*temp;

	if (!label)
		return ;
	while (*label)
	{
		temp = *label;
		*label = (*label)->next;
		free(temp);
	}
}

void		free_data(void)
{
	if (g_buf)
		free(g_buf);
	if (g_data)
	{
		if (g_data->fd)
			close(g_data->fd);
		free_label(&g_data->label);
		free_token(&g_data->token);
		free(g_data);
	}
	exit(0);
}
