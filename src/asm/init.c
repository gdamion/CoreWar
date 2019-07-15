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

void		data_init(int fd)
{
	t_data	*temp;

	if (INIT_DATA)
		print_error(ERR_ALLOC);
	ft_bzero(temp, sizeof(temp));
	temp->fd = fd;
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

void		check_duplicates(t_label *label)
{
	t_label	*temp;

	temp = label->next;
	while (temp)
	{
		if (!ft_strcmp(label->name, temp->name))
			; //error
		temp = temp->next;
	}
}

void		label_add(char *line, int start)
{
	t_label	*new;

	if (INIT_LABEL)
		print_error(ERR_ALLOC);
	ft_bzero(new, sizeof(new));
	new->x = g_data->x;
	new->y = g_data->y;
	g_data->token->type = LABEL;
	if (g_data->label)
		g_data->label->prev = new;
	new->next = g_data->label;
	g_data->label = new;
	check_duplicates(g_data->label);
}

void	op_add(t_op_type **curr)
{
	if (!((*curr)->next = (t_op_type*)malloc(sizeof(t_op_type))))
		errorr(ERR_ALLOC, 0, 0);
	ft_bzero((*curr)->next, sizeof(t_op_type));
	*curr = (*curr)->next;
}
