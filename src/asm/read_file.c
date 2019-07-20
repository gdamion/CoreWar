/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_file.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdamion- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/18 19:03:47 by gdamion-          #+#    #+#             */
/*   Updated: 2019/07/20 22:29:53 by gdamion-         ###   ########.fr       */
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

void		read_file(char *filename)
{
	t_token		*code;

	data_init();
	valid_filename(filename);
	if ((g_data->fd = open(filename, O_RDONLY)) == -1)
		error_event(ERR_FOPEN, 0);
	g_data->filename = filename;
	ft_printf("Lexical analyser... ");
	lexical_analyzer();
	ft_printf("DONE\n");

	code = g_data->token;
	while (code->next)
		code = code->next;
	g_data->token = code;

	// t_token *test = code;
	// while (test->prev)
	// {
	// 	ft_printf("content: %s|\n", test->content);
	// 	test = test->prev;
	// }

	ft_printf("Valid info... ");
	valid_champion_info(&code);
	ft_printf("DONE\n");

	// while ((code->prev->type == NEW_LINE || code->prev->type == COMMAND
	// 		|| code->prev->type == STRING) && code->prev)
	// 	code = code->prev;

	ft_printf("Syntax... ");
	syntax_analyser(code);
	ft_printf("DONE\n");

	t_token *test = g_data->token;
	while (test)
	{
		ft_printf("content: %s| type: %d\n", test->content, test->type);
		test = test->prev;
	}

	// t_token *test1 = code;
	// while (test1->prev)
	// {
	// 	ft_printf("bytes %u\n", test1->bytes);
	// 	test1 = test1->prev;
	// }
	if (!(g_buf = (char*)malloc(sizeof(char) * (g_bytes * 2))))
		error_event(ERR_ALLOC, 0);
	ft_printf("Translate... ");
	ft_printf("size of prog = %u\n", g_bytes);
	translate(code, g_bytes);
	ft_printf("DONE\n");

	ft_printf("Writing... ");
	write_to_file();
	ft_printf("DONE\n");

	ft_printf("Free data... ");
	free_data(g_data);
	ft_printf("DONE\n");
}
