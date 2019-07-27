/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_structures.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmann <tmann@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/22 18:35:16 by tmann             #+#    #+#             */
/*   Updated: 2019/07/23 15:18:46 by tmann            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../vm.h"

void		init_oper(t_oper *operation, int carr_id)
{
	t_oper *tmp;

	tmp = operation;
	tmp->arg_byte_pose = 0;
	tmp->i = 0;
	tmp->j = 0;
	tmp->arg1 = 0;
	tmp->arg2 = 0;
	tmp->arg3 = 0;
	tmp->arg1_type = 0;
	tmp->arg2_type = 0;
	tmp->arg3_type = 0;
	tmp->is_arg1_set = false;
	tmp->is_arg2_set = false;
	tmp->is_arg3_set = false;
	tmp->move_len = 0;
	tmp->carr_id = carr_id;
}

t_binary_r	*init_binary_represent(void)
{
	t_binary_r	*file;

	file = (t_binary_r*)malloc(sizeof(t_binary_r));
	file->size = 0;
	file->arr = NULL;
	file->used_num_names = NULL;
	file->i = 0;
	file->player_num = 0;
	return (file);
}

void		set_game_init_args(t_game *game)
{
	game->cycle_to_die = CYCLE_TO_DIE;
	game->cycle_delta = CYCLE_DELTA;
	game->live_check_cycle = 0;
	game->count_of_live_checks = 0;
	game->live_checks_count = 0;
	game->is_first_die_cycle = 0;
	game->champs_count = 0;
	game->cycles_per_sec = 50;
	game->champs = NULL;
	game->time = 16;
	game->winner_num = 0;
}

t_game		*init_game(int *ac, char **av)
{
	t_game	*game;

	game = (t_game*)malloc(sizeof(t_game));
	game->arena_size = MEM_SIZE;
	game->cycle_count = 0;
	game->arena = malloc(sizeof(unsigned char) * (MEM_SIZE + 1));
	game->arena_which_champ = malloc(sizeof(unsigned char) * (MEM_SIZE + 1));
	game->bright_arr = malloc(sizeof(int) * (MEM_SIZE + 1));
	if (game->arena == NULL || game->arena_which_champ == NULL)
	{
		ft_printf("Error: Can't allocate enough space for creating arena.\n");
		exit(404);
	}
	ft_bzero(game->arena, MEM_SIZE);
	game->arena[MEM_SIZE] = '\0';
	game->arena_which_champ[MEM_SIZE] = '\0';
	game->dump = find_dump(ac, av);
	game->verbose = find_verbose(ac, av);
	game->graphic = find_graphic(ac, av);
	set_game_init_args(game);
	ft_bzero(game->bright_arr, MEM_SIZE);
	return (game);
}
