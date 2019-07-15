/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_file.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdamion- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/12 18:40:12 by gdamion-          #+#    #+#             */
/*   Updated: 2019/07/15 13:32:20 by gdamion-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "com.h"

void		read_file(char *filename)
{
	int			fd;
	t_token		*code_start;
	u_int32_t	code_size;

	valid_filename(filename);
	(fd = open(filename, O_RDONLY)) == -1 ? \
		errorr(ERR_FOPEN, 0, 0) : data_init(fd);
	g_data->filename = filename;
	lexical_analyzer();
	code_start = g_data->token;
	valid_champion_info(&code_start);
	code_size = syntax_analiser(code_start);
	translate(code_start, code_size);
	write_to_file();
	free_info();
}

void	valid_filename(char *fname)
{
	while(*fname != '\0')
	{
		if (*fname == '.')
			break;
		fname++;
	}
	ft_strcmp(fname, ".s") ? print_error(ERR_FNAME) : 1;
}
