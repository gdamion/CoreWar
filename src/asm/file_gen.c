/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   filegen.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdamion- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/07 14:58:34 by gdamion-          #+#    #+#             */
/*   Updated: 2019/07/12 18:36:12 by gdamion-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "com.h"

void	write_file(void)
{
	int		fd;
	char	*new_name;

	new_name = newn_create(g_data->filename);
	if ((fd = open(new_name, O_CREAT|O_WRONLY)) == -1)
			error(ERR_CRFHEX);
	free(new_name);
	if (write(fd, g_buf, CHAMP_MAX_SIZE) == -1)
	{
		close(fd);
		error(ERR_WRFHEX);
	}
	close(fd);
}

char	*newn_create(char *filename)
{
	int		len;
	char	*new_name;
	int		i;

	len = ft_findchar(filename, '.');
	new_name = (char*)malloc(len + 5);
	new_name[len + 4] = '\0';
	i = -1;
	while (++i < len)
		new_name[i] = filename[i];
	ft_strcpy(&(new_name[i]), ".cor");
	return (new_name);
}
