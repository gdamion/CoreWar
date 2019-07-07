/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdamion- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/07 13:25:31 by gdamion-          #+#    #+#             */
/*   Updated: 2019/07/07 13:27:49 by gdamion-         ###   ########.fr       */
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
	ft_strcmp(fname, ".s") ? error(ERR_FNAME) : 1;
}

void		read_file(char *filename)
{
	int		fd;
	t_data	*data;

	check_fname(filename); // is name of the file correct?
	((fd = open(filename, O_RDONLY)) == -1) ? \
		error(ERR_FOPEN, 0, 0) : data_init(&data, fd);
	lexical_analyzer(data);
}
