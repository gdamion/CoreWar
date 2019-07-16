/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_file.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdamion- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/12 18:40:12 by gdamion-          #+#    #+#             */
/*   Updated: 2019/07/16 15:09:33 by gdamion-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "com.h"

void	valid_filename(char *fname)
{
	while(*fname != '\0')
	{
		if (*fname == '.')
			break;
		fname++;
	}
	if (ft_strcmp(fname, ".s"))
		print_error(ERR_FNAME);
}

void		read_file(char *filename)
{
	t_token		*code;

	data_init();
	valid_filename(filename);
	if ((g_data->fd = open(filename, O_RDONLY)) == -1)
		errorr(ERR_FOPEN, 0, 0);
	g_data->filename = filename;
	lexical_analyzer();
	code = g_data->token;
	// valid_champion_info(&code);
	// ft_printf("out\n");
	// while (code->next)
	// {
	// 	code = code->next;
	// }
	// while (code->prev)
	// {
	// 	ft_printf("%s\n", code->content);
	// 	code = code->prev;
	// }

	// syntax_analyser(code);
	// translate(code, g_bytes);
	// write_to_file();
	// free_info();
}
