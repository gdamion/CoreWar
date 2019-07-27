/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   n_flag.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdamion- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/22 18:35:47 by tmann             #+#    #+#             */
/*   Updated: 2019/07/27 18:52:15 by gdamion-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

void	find_all_n(t_game *game, int **used_nums, int *ac, char **av)
{
	int i;
	int num;

	i = -1;
	*used_nums = ft_memalloc(sizeof(int) * 4);
	while (++i < *ac)
	{
		if (!(ft_strstr(av[i], ".cor")))
		{
			if (!(ft_strcmp("-n", av[i])) && (i + 2 < *ac))
			{
				num = save_champ_num(av[i + 1], av[i + 2]);
				add_num_to_arr(*used_nums, num);
				read_one_champ(game, av[i + 2], num);
				delete_args(ac, av, i, 3);
				i--;
			}
			else
			{
				ft_printf("Wrong params. Check usage.\n");
				exit(-1);
			}
		}
	}
}

int		save_champ_num(char *num, char *name)
{
	int value;

	check_name(name);
	value = return_valid_n("-n", num);
	return (value);
}

void	check_name(char *name)
{
	if (ft_strstr(name, ".cor"))
		return ;
	usage(name);
}

void	add_num_to_arr(int *used_nums, int num)
{
	int i;

	i = 0;
	if (num > 4)
	{
		ft_printf("Error. Possible num for champ 1 - 4\n");
		exit(-1);
	}
	while (used_nums[i] != 0 && i < 5)
	{
		if (used_nums[i] == num)
		{
			ft_printf("Error. This number (%d) for champ already exists\n",
			num);
			exit(-1);
		}
		i++;
	}
	if (i == 4)
	{
		ft_printf("Error with -n\n");
		exit(-1);
	}
	used_nums[i] = num;
}

int		return_valid_n(char *flag, char *num)
{
	int i;

	i = -1;
	while (num[++i])
		if (!ft_isdigit(num[i]) || num[0] == '+')
		{
			ft_printf("Error - flag %s. Number is not digit or negative\n",
				flag);
			exit(-1);
		}
	i = ft_atoi(num);
	if (i <= 0)
	{
		ft_printf("Error - flag %s %d. Number must be positive\n", flag, i);
		exit(-1);
	}
	return (i);
}
