/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_carriage.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmann <tmann@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/22 18:35:03 by tmann             #+#    #+#             */
/*   Updated: 2019/07/23 15:17:45 by tmann            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../vm.h"

t_carriage		*init_carr(t_game *game, int curr_carr)
{
	t_carriage	*carr;

	if (!(carr = malloc(sizeof(t_carriage))))
		exit(-1);
	ft_bzero(carr, sizeof(t_carriage));
	carr->num_of_carriage = -game->champs[curr_carr]->num;
	carr->curr_position = game->arena_size / game->champs_count * (curr_carr);
	carr->regs[0] = carr->num_of_carriage;
	carr->is_oper_executed = true;
	carr->cycles_to_use_oper = 1;
	carr->is_alive = true;
	carr->prev = NULL;
	carr->is_alive = true;
	carr->next = NULL;
	return (carr);
}

t_carriage		*add_carr(t_carriage **head, t_carriage *new_carr)
{
	t_carriage *carr;

	carr = *head;
	if (head && carr)
	{
		new_carr->next = carr;
		carr->prev = new_carr;
	}
	return (new_carr);
}

void			add_carr_to_end(t_carriage **head, t_carriage *new_carry)
{
	t_carriage *tmp;

	tmp = *head;
	while (tmp->next)
		tmp = tmp->next;
	tmp->next = new_carry;
	new_carry->prev = tmp;
}

t_carriage		*copy_carr(t_carriage *carr)
{
	t_carriage	*copy;

	copy = malloc(sizeof(t_carriage));
	copy = ft_memcpy(copy, carr, sizeof(t_carriage));
	copy->prev = NULL;
	copy->next = NULL;
	return (copy);
}

t_carriage		*init_all_carrs(t_game *game)
{
	int			i;
	t_carriage	*head;
	t_carriage	*tmp;

	i = 0;
	head = init_carr(game, i);
	head->id = i + 1;
	head->color = head->id;
	game->carrs_count++;
	i++;
	while (i < game->champs_count)
	{
		tmp = init_carr(game, i);
		tmp->id = i + 1;
		tmp->color = tmp->id;
		game->carrs_count++;
		add_carr_to_end(&head, tmp);
		i++;
	}
	return (head);
}
