/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_file.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdamion- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/18 19:03:47 by gdamion-          #+#    #+#             */
/*   Updated: 2019/07/28 13:36:54 by gdamion-         ###   ########.fr       */
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

void		prepare_data(void)
{
	t_token		*code;

	code = g_data->token;
	while (code->next)
		code = code->next;
	g_data->token = code;
}

void		analyze(void)
{
	lexical_analyzer();
	prepare_data();
	valid_champion_info(&g_data->token);
	syntax_analyser(g_data->token);
}

void		compilation(void)
{
	ft_printf("compile1\n");
	if (!(g_buf = (char*)malloc(sizeof(char) * (EXEC_START + g_bytes))))
		error_event(ERR_ALLOC);
	ft_printf("compile2\n");
	ft_bzero(g_buf, EXEC_START + g_bytes);
	ft_printf("compile3\n");
	translate(g_data->token, g_bytes);
	ft_printf("compile4\n");
	write_to_file();
	ft_printf("compile5\n");
}

void		read_file(char *filename, _Bool flag)
{
	ft_printf("init\n");
	data_init();
	ft_printf("filename\n");
	valid_filename(filename);
	ft_printf("open\n");
	g_data->test = flag;
	if ((g_data->fd = open(filename, O_RDONLY)) == -1)
		error_event(ERR_FOPEN);
	g_data->filename = filename;
	ft_printf("analize\n");
	analyze();
	ft_printf("compile\n");
	compilation();
	ft_printf("free data\n");
	free_data();
}
