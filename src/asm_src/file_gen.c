/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   file_gen.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdamion- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/07 14:58:34 by gdamion-          #+#    #+#             */
/*   Updated: 2019/07/27 16:50:31 by gdamion-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "com.h"

static char			*new_filename(char *filename)
{
	u_int16_t		len;
	char			*new_name;
	u_int16_t		i;

	len = -1;
	while (filename[++len] + 1)
		if (filename[len] == '.'
		&& filename[len + 1] == 's'
		&& filename[len + 2] == '\0')
			break ;
	if (!(new_name = (char*)malloc(len + (g_data->test ? 6 : 5) + 1)))
		error_event(ERR_ALLOC);
	i = -1;
	while (++i < len)
		new_name[i] = filename[i];
	ft_strcpy(&(new_name[i]), (g_data->test ? ".mycor" : ".cor"));
	return (new_name);
}

void				write_to_file(void)
{
	int				fd;
	char			*new_name;

	new_name = new_filename(g_data->filename);
	if ((fd = open(new_name, O_CREAT | O_TRUNC | O_WRONLY, 0644)) == -1)
		error_event(ERR_CRFHEX);
	ft_printf("%sWriting output program to %s%s\n", GREEN, new_name, EOC);
	free(new_name);
	if (write(fd, g_buf, EXEC_START + g_bytes) == -1)
	{
		close(fd);
		error_event(ERR_WRFHEX);
	}
	close(fd);
}
