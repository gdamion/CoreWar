/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmann <tmann@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/22 18:34:20 by tmann             #+#    #+#             */
/*   Updated: 2019/07/23 15:18:27 by tmann            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../corewar.h"

t_game	*read_info(int ac, char **av)
{
	int			i;
	int			*used_numes;
	t_game		*game;

	i = -1;
	if (ac == 0)
	{
		ft_printf("Incorrect amount of champs. ");
		ft_printf("Program work with 1 - 4 champs\n");
		exit(-1);
	}
	game = init_game(&ac, av);
	find_all_n(game, &used_numes, &ac, av);
	while (++i < ac)
		read_one_champ(game, av[i], deter_num(used_numes));
	if (game->champs_count == 0)
	{
		ft_printf("Incorrect amount of champs. ");
		ft_printf("Program work with 1 - 4 champs\n");
		exit(-1);
	}
	check_champs_nums_and_amount(game);
	game->alive_carrs_count = game->champs_count;
	free(used_numes);
	return (game);
}

void	read_one_champ(t_game *game, char *av, int player_num)
{
	t_binary_r	*file;
	t_player	*player;
	int			fd;

	file = init_binary_represent();
	if ((fd = open(av, O_RDONLY)) < 0)
		ft_fd_error(fd);
	read_binary_file(fd, file);
	player = prepare_player(file, player_num);
	game->champs = init_champs(game->champs, player);
	game->champs_count++;
	free_binary_presentation(file);
	free(file);
}

int		main(int ac, char **av)
{
	t_game		*game;
	t_carriage	*carr;

	if (ac == 1)
		print_usage(av[0]);
	game = read_info(ac - 1, &av[1]);
	place_all_champs_execs(game);
	carr = init_all_carrs(game);
	if (game->graphic)
	{
		prepare_screen(game);
		getch();
		init_screen(game, carr);
	}
	introduce_players(game);
	start_game(game, &carr);
	free_champs(game);
	free_carrs(&carr);
	free_game(game);
	free(game);
	return (0);
}

void	print_usage(char *name)
{
	ft_printf("Usage: %s [-d N -v -g | -n (1 - 4)] ", name);
	ft_printf("[-a] <champion1.cor> <...>\n");
	ft_printf("##########################################################");
	ft_printf("#####\n");
	ft_printf("% 5c-dump N   : Dumps memory after N cycles then exits\n", ' ');
	ft_printf("% 5c-n N      : Sets the number of the next player\n", ' ');
	ft_printf("% 5c-v        : Verbose mode\n", ' ');
	ft_printf("% 5c-g        : Ncurses output mode\n", ' ');
	exit(-1);
}
