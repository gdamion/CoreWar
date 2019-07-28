/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_file.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdamion- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/18 19:03:47 by gdamion-          #+#    #+#             */
/*   Updated: 2019/07/27 16:59:13 by gdamion-         ###   ########.fr       */
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
		error_event(ERR_FNAME);
}

t_token			*prepare_data(void)
{
	t_token		*code;

	code = g_data->token;
	while (code->next)
		code = code->next;
	g_data->token = code;
	return (code);
}

void		analyze(void)
{
	t_token		*code;

	lexical_analyzer();
	code = prepare_data();
	valid_champion_info(&code);
	syntax_analyser(code);
}

void		compilation(void)
{
	if (!(g_buf = (char*)malloc(sizeof(char) * (EXEC_START + g_bytes))))
		error_event(ERR_ALLOC);
	ft_bzero(g_buf, EXEC_START + g_bytes);
	translate(g_data->token, g_bytes);
	write_to_file();
}

void		read_file(char *filename, _Bool flag)
{
	data_init();
	valid_filename(filename);
	g_data->test = flag;
	if ((g_data->fd = open(filename, O_RDONLY)) == -1)
		error_event(ERR_FOPEN);
	g_data->filename = filename;
	analyze();
	compilation();
	free_data();
}
