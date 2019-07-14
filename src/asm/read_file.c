/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_file.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdamion- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/12 18:40:12 by gdamion-          #+#    #+#             */
/*   Updated: 2019/07/12 18:40:33 by gdamion-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "com.h"

void		read_file(char *filename)
{
	int		fd;
	t_token	*code_start;

	ch_fname(filename); // is name of the file correct?
	(fd = open(filename, O_RDONLY)) == -1 ? errorr(ERR_FOPEN, 0, 0) : data_init(fd);
	g_data->f_name = filename;
	lexical_analyzer();
	code_start = valid_champion_info(); //печать имени и коммента
	syntax_analiser(code_start);
	translate(code_start);
	write_to_file();
}

void	ch_fname(char *fname)
{
	while(*fname != '\0')
	{
		if (*fname == '.')
			break;
		fname++;
	}
	ft_strcmp(fname, ".s") ? print_error(ERR_FNAME) : 1;
}
