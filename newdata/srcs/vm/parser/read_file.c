/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_file.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmann <tmann@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/22 18:36:02 by tmann             #+#    #+#             */
/*   Updated: 2019/07/22 18:36:04 by tmann            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../vm.h"

void			blank_error(unsigned char *arr)
{
	if (arr == NULL)
	{
		ft_printf("Blank file!\n");
		exit(404);
	}
}

void			read_binary_file(int fd, t_binary_r *file)
{
	int				i;
	char			buf[BUFF_SIZE + 1];
	unsigned char	*tmp;
	int				ret;

	i = 0;
	tmp = NULL;
	while ((ret = read(fd, buf, BUFF_SIZE)))
	{
		i = 0;
		buf[ret] = '\0';
		if (tmp != NULL && ret != 0)
			tmp = realloc(tmp, file->size + ret);
		else
			tmp = malloc((file->size + ret));
		while (i < ret && ret != -1)
		{
			tmp[file->size] = (unsigned char)buf[i];
			i++;
			(file->size)++;
		}
	}
	blank_error(tmp);
	file->arr = (unsigned char*)tmp;
}

void			place_all_champs_execs(t_game *game)
{
	int				i;
	int				j;
	int				k;

	i = 0;
	j = 0;
	while (i < game->champs_count && game->champs[i])
	{
		k = 0;
		while (k < game->champs[i]->exec_size)
		{
			game->arena[j] = game->champs[i]->exec[k];
			game->arena_which_champ[j] = game->champs[i]->num;
			k++;
			j++;
		}
		while (j < (MEM_SIZE / game->champs_count) * (i + 1) && j < MEM_SIZE)
		{
			j++;
		}
		i++;
	}
}

void			usage(char *arg)
{
	if (arg)
	{
		ft_printf("Invalid |%s|, only *.cor files ", arg);
		ft_printf("or valid flags with arguments allowed\n");
	}
	else
	{
		ft_printf("Invalid args, only *.cor files or ");
		ft_printf("or valid flags with arguments allowed\n");
	}
	exit(-1);
}

int				deter_num(int *used_numes)
{
	int num;
	int i;

	i = -1;
	num = 1;
	while (++i < 4)
	{
		if (num == used_numes[i])
		{
			num++;
			i = -1;
		}
	}
	i = 0;
	while (used_numes[i] != 0 && i < 5)
		i++;
	if (num > 4)
	{
		ft_printf("Error with num of champs\n");
		exit(-1);
	}
	used_numes[i] = num;
	return (num);
}
