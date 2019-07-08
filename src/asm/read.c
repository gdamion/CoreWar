/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdamion- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/07 13:25:31 by gdamion-          #+#    #+#             */
/*   Updated: 2019/07/07 15:31:51 by gdamion-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "com.h"

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

void		read_file(char *filename)
{
	int		fd;
	t_data	*data;

	data = 0;
	ch_fname(filename); // is name of the file correct?
	if ((fd = open(filename, O_RDONLY)) == -1)
		print_error(ERR_FOPEN);
	else
		data_init(&data, fd);
	data->f_name = filename;
	lexical_analyzer(data);
}
