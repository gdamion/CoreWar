/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdamion- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/07 13:25:22 by gdamion-          #+#    #+#             */
/*   Updated: 2019/07/15 14:10:57 by gdamion-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "com.h"

void		data_init(void)
{
	t_data	*temp;

	if (INIT_DATA)
		print_error(ERR_ALLOC);
	ft_bzero(temp, sizeof(temp));
	g_data = temp;
}

void		token_add(t_type type)
{
	t_token	*new;

	if (INIT_TOKEN)
		print_error(ERR_ALLOC);
	ft_bzero(new, sizeof(new));
	new->x = g_data->x;
	new->y = g_data->y;
	new->type = type;
	if (g_data->token)
		g_data->token->prev = new;
	new->next = g_data->token;
	g_data->token = new;
}

void		lable_duplicates(void)
{
	char	*origin;
	t_label	*temp;

	origin = g_data->label->point->content;
	temp = g_data->label->next;
	while (temp)
	{
		if (!ft_strcmp(origin, temp->point->content))
			print_error("CHECK_DUP_LAB");
		temp = temp->next;
	}
}

void		label_add(void)
{
	t_label	*new;

	if (INIT_LABEL)
		print_error(ERR_ALLOC);
	ft_bzero(new, sizeof(new));
	g_data->token->type = LABEL;
	new->point = g_data->token;
	if (g_data->label)
		g_data->label->prev = new;
	new->next = g_data->label;
	g_data->label = new;
	lable_duplicates();
}
