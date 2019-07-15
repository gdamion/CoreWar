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

	valid_filename(filename);
	if ((fd = open(filename, O_RDONLY)) == -1)
		errorr(ERR_FOPEN, 0, 0);
	data_init(fd);
	g_data->filename = filename;
	lexical_analyzer();
	// valid_champion_info();
	syntax_analiser();
	// translate();
	// write_file();
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
		print_error(ERR_FNAME);
}
