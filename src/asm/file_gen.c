/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   file_gen.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdamion- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/07 14:58:34 by gdamion-          #+#    #+#             */
/*   Updated: 2019/07/18 23:29:23 by gdamion-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "com.h"

void	write_to_file(void)
{
	int		fd;
	char	*new_name;

	new_name = new_filename(g_data->filename);
	if (fd = open(new_name, O_TRUNC | O_WRONLY | O_CREAT) == -1)
			errorr(ERR_CRFHEX);
	ft_printf("Writing output program to %s, fd = %d\n", new_name, fd);
	free(new_name);
	if (write(fd, g_buf, FULL_SIZE) == -1)
	{
		close(fd);
		errorr(ERR_WRFHEX);
	}
	ft_printf("ok? really???\n");
	close(fd);
}

char	*new_filename(char *filename)
{
	int		len;
	char	*new_name;
	int		i;

	len = ft_findchar(filename, '.');
	if (!(new_name = (char*)malloc(len + 5)))
		errorr(ERR_ALLOC);
	new_name[len + 4] = '\0';
	i = -1;
	while (++i < len)
		new_name[i] = filename[i];
	ft_strcpy(&(new_name[i]), "cor");
	return (new_name);
}
