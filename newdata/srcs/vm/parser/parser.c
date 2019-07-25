/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmann <tmann@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/22 18:35:55 by tmann             #+#    #+#             */
/*   Updated: 2019/07/22 18:35:57 by tmann            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../vm.h"

static void	skip_bytes(int *curr_byte_count, int skipping_bytes)
{
	*curr_byte_count += skipping_bytes;
}

char		*get_champ_name(t_binary_r *file)
{
	char	*str;
	int		i;

	if (!(str = malloc(PROG_NAME_LENGTH + 1)))
		exit(-1);
	str[PROG_NAME_LENGTH] = '\0';
	i = 3;
	while (++i < PROG_NAME_LENGTH + 4)
		str[i - 4] = (char)file->arr[i];
	skip_bytes(&file->i, i);
	return (str);
}

char		*get_champ_comment(t_binary_r *file)
{
	char	*str;
	int		i;

	if (!(str = malloc(COMMENT_LENGTH + 1)))
		exit(-1);
	str[COMMENT_LENGTH] = '\0';
	i = -1;
	while (file->i + ++i < COMMENT_LENGTH + file->i)
		str[i] = (char)file->arr[i + file->i];
	skip_bytes(&file->i, i + 4);
	return (str);
}

int			get_champ_exec_code_size(t_binary_r *file)
{
	int champ_code_size;
	int bitwise;

	bitwise = 24;
	champ_code_size = 0;
	skip_bytes(&file->i, 4);
	while (bitwise > -1)
	{
		champ_code_size = champ_code_size | file->arr[file->i++] << bitwise;
		bitwise -= 8;
	}
	return (champ_code_size);
}

char		*get_champ_exec(t_binary_r *file, int exec_size)
{
	int		i;
	char	*exec;

	if (!(exec = malloc(exec_size + 1)))
		exit(-1);
	exec[exec_size] = '\0';
	i = -1;
	while (++i < exec_size)
		exec[i] = (char)file->arr[file->i + i];
	return (exec);
}
