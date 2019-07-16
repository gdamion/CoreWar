/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_file.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdamion- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/12 18:40:12 by gdamion-          #+#    #+#             */
/*   Updated: 2019/07/16 12:57:18 by gdamion-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "com.h"

void		read_file(char *filename)
{
	int			fd;
	t_token		*code;

	valid_filename(filename);
	if ((fd = open(filename, O_RDONLY)) == -1)
		errorr(ERR_FOPEN, -1, -1);
	data_init(fd);
	g_data->filename = filename;
	lexical_analyzer();
	code = g_data->token;
	valid_champion_info(&code);
	// syntax_analyser(code);
	// translate(code, g_bytes);
	// write_to_file();
	// free_info();
}

void	valid_filename(char *fname)
{
	while(*fname != '\0')
	{
		if (*fname == '.')
			break;
		fname++;
	}
	if (ft_strcmp(fname, ".s"))
		errorr(ERR_FNAME, -1, -1);
}
