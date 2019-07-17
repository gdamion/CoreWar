/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   file_gen.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdamion- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/07 14:58:34 by gdamion-          #+#    #+#             */
/*   Updated: 2019/07/17 14:01:55 by gdamion-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "com.h"

void	write_to_file(void)
{
	int		fd;
	char	*new_name;

	new_name = new_filename(g_data->filename);
	if ((fd = open(new_name, O_CREAT | O_WRONLY)) == -1)
			errorr(ERR_CRFHEX, 0, 0);
	free(new_name);
	ft_printf("Writing output program to %s\n", new_name);
	if (write(fd, g_buf, FULL_SIZE) == -1)
	{
		close(fd);
		errorr(ERR_WRFHEX, 0, 0);
	}
	close(fd);
}

char	*new_filename(char *filename)
{
	int		len;
	char	*new_name;
	int		i;

	len = ft_findchar(filename, '.');
	if (!(new_name = (char*)malloc(len + 5)))
		errorr(ERR_ALLOC, 0, 0);
	new_name[len + 4] = '\0';
	i = -1;
	while (++i < len)
		new_name[i] = filename[i];
	ft_strcpy(&(new_name[i]), ".cor");
	return (new_name);
}
