/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmann <tmann@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/22 18:35:24 by tmann             #+#    #+#             */
/*   Updated: 2019/07/23 15:16:55 by tmann            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../vm.h"

void	check_args(t_binary_r *file, t_player *pl)
{
	check_magic_header(file);
	check_null(file);
	check_exec_size(pl);
	compare_exec_with_size(pl->exec_size, file->size);
}

void	check_magic_header(t_binary_r *file)
{
	int magic_header;
	int bitwise;

	bitwise = 24;
	magic_header = 0;
	file->i = 0;
	while (bitwise > -1)
	{
		magic_header = magic_header | file->arr[file->i++] << bitwise;
		bitwise -= 8;
	}
	if (magic_header != COREWAR_EXEC_MAGIC)
	{
		ft_printf("Magic Header invalid.\n");
		exit(-1);
	}
	file->i = 0;
}

void	check_null(t_binary_r *file)
{
	int i;

	i = 131;
	while (++i < 136)
	{
		if (file->arr[i] != 0 || file->arr[i + 2052] != 0)
		{
			ft_printf("NULL invalid.\n");
			exit(-1);
		}
	}
}

void	check_exec_size(t_player *pl)
{
	if (pl->exec_size < 0 || pl->exec_size > 682)
	{
		ft_printf("Error: Champion - %s has too large a code ", pl->name);
		ft_printf("(%d bytes > 682 bytes)\n", pl->exec_size);
		exit(-1);
	}
}

void	compare_exec_with_size(int exec_size, int read)
{
	if (exec_size != read + 1 - 2193)
	{
		ft_printf("Parsed exec_size and real exec_size not equiualent.\n");
		ft_printf("size - %d exec - %d\n", exec_size, read - 2193);
		exit(-1);
	}
}
