/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dump.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdamion- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/22 18:35:34 by tmann             #+#    #+#             */
/*   Updated: 2019/07/27 18:52:15 by gdamion-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

int		find_dump(int *ac, char **av)
{
	int i;
	int dump;

	i = -1;
	while (++i < *ac)
	{
		if (!(ft_strcmp("-dump", av[i])))
		{
			if (i + 1 < *ac)
			{
				dump = check_valid_dump(av[i + 1]);
				delete_args(ac, av, i, 2);
				return (dump);
			}
			else
			{
				ft_printf("Error - dump doesn't have cycles\n");
				exit(-1);
			}
		}
	}
	return (-1);
}

int		check_valid_dump(char *dump_int)
{
	int i;

	i = -1;
	if (dump_int[0] == '+')
		i++;
	while (dump_int[++i])
		if (!ft_isdigit(dump_int[i]))
		{
			ft_printf("Dump number is not digit or is negative\n");
			exit(-1);
		}
	i = ft_atoi(dump_int);
	if (i < 0)
	{
		ft_printf("Dump number is negative\n");
		exit(-1);
	}
	return (i);
}

void	delete_args(int *ac, char **av, int i, int skipped)
{
	while (i + skipped < *ac)
	{
		av[i] = av[i + skipped];
		i++;
	}
	*ac -= skipped;
}

void	print_gc(int ac, char **av)
{
	int i;

	i = -1;
	ft_printf("args count - %d\n", ac);
	while (++i < ac)
		ft_printf("av[%d] - %s\n", i, av[i]);
}
