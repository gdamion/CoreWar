/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_file.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdamion- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/18 19:03:47 by gdamion-          #+#    #+#             */
/*   Updated: 2019/07/27 17:13:50 by gdamion-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "com.h"

void	valid_filename(char *fname)
{
	int	i;

	i = 0;
	while(fname[i])
		i++;
	while(fname[--i])
		if (fname[i] == '.')
			break ;
	if (ft_strcmp(&fname[i], ".s"))
		error_event(ERR_FNAME, 0);
}

void		read_file(char *filename, _Bool flag)
{
	t_token		*code;

	data_init();
	valid_filename(filename);
	g_data->test = flag;
	if ((g_data->fd = open(filename, O_RDONLY)) == -1)
		error_event(ERR_FOPEN, 0);
	g_data->filename = filename;
	lexical_analyzer();
	code = g_data->token;
	while (code->next)
		code = code->next;
	g_data->token = code;
	valid_champion_info(&code);
	syntax_analyser(code);
	if (!(g_buf = (char*)malloc(sizeof(char) * (EXEC_START + g_bytes))))
		error_event(ERR_ALLOC, 0);
	ft_bzero(g_buf, EXEC_START + g_bytes);
	translate(code, g_bytes);
	write_to_file();
	free_data();
	free(g_buf);
}
