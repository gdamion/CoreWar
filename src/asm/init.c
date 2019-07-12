/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdamion- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/07 13:25:22 by gdamion-          #+#    #+#             */
/*   Updated: 2019/07/07 13:25:23 by gdamion-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "com.h"

void		data_init(t_data **data, int fd)
{
	t_data	*temp;

	if (INIT_DATA)
		print_error(ERR_ALLOC);
	ft_bzero(temp, sizeof(temp));
	temp->fd = fd;
	*data = temp;
}

void		token_add(t_data *data, t_type type)
{
	t_token	*new;

	if (INIT_TOKEN)
		print_error(ERR_ALLOC);
	ft_bzero(new, sizeof(new));
	new->x = data->x;
	new->y = data->y;
	new->type = type;
	if (data->token)
		data->token->prev = new;
	new->next = data->token;
	data->token = new;
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

void		label_add(t_data *data, char *line, int start)
{
	t_label	*new;

	if (INIT_LABEL)
		print_error(ERR_ALLOC);	
	ft_bzero(new, sizeof(new));
	new->x = data->x;
	new->y = data->y;
	data->token->type = LABEL;
	if (data->label)
		data->label->prev = new;
	new->next = data->label;
	data->label = new;
	check_duplicates(data->label);
}
