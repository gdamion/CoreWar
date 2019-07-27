/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_data.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdamion- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/20 21:07:21 by gdamion-          #+#    #+#             */
/*   Updated: 2019/07/27 18:54:40 by gdamion-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

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

void		free_data()
{
	if (g_data->token)
		free_token(g_data->token);
	if (g_data->label)
		free_label(g_data->label);
	free(g_data);
}
