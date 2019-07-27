/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   carrs_funcs.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rywisozk <rywisozk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/08 15:57:43 by rywisozk          #+#    #+#             */
/*   Updated: 2019/07/08 15:57:45 by rywisozk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../vm.h"

void			add_to_end(t_carriage *head, t_carriage *new_carry)
{
	t_carriage *tmp;

	tmp = head;
	while (tmp->next)
		tmp = tmp->next;
	tmp->next = new_carry;
	new_carry->prev = tmp;
}

void			add_to_start(t_carriage **head, t_carriage *new_carry)
{
	t_carriage *tmp;

	tmp = *head;
	while (tmp->prev)
		tmp = tmp->prev;
	*head = new_carry;
	new_carry->next = tmp;
	tmp->prev = new_carry;
}

t_carriage		*get_last_carr(t_carriage **head)
{
	t_carriage *tmp;

	tmp = *head;
	while (tmp->next)
		tmp = tmp->next;
	return (tmp);
}

t_carriage		*get_end(t_carriage **head)
{
	t_carriage *tmp;

	tmp = *head;
	while (tmp->next)
		tmp = tmp->next;
	return (tmp);
}
