/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_data.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdamion- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/20 21:07:21 by gdamion-          #+#    #+#             */
/*   Updated: 2019/07/20 21:07:33 by gdamion-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "com.h"

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
