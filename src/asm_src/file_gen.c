/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   file_gen.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdamion- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/07 14:58:34 by gdamion-          #+#    #+#             */
/*   Updated: 2019/07/27 14:12:12 by gdamion-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "com.h"

void	write_to_file(void)
{
	int		fd;
	char	*new_name;

	new_name = new_filename(g_data->filename);
	if ((fd = open(new_name, O_CREAT | O_TRUNC | O_WRONLY, 0644)) == -1)
		error_event(ERR_CRFHEX, 0);
	ft_printf("%sWriting output program to %s%s\n", GREEN, new_name, EOC);
	free(new_name);
	if (write(fd, g_buf, EXEC_START + g_bytes) == -1)
	{
		close(fd);
		error_event(ERR_WRFHEX, 0);
	}
	close(fd);
}

char	*new_filename(char *filename)
{
	u_int32_t		len;
	char			*new_name;
	int				i;

	len = (unsigned int)(ft_strstr(filename, ".s") - filename);
	// ft_printf("len = %u\n", len);
	if (!(new_name = (char*)malloc(len + (g_data->test ? 6 : 5))))
		error_event(ERR_ALLOC, 0);
	i = -1;
	while (++i < len)
		new_name[i] = filename[i];
	ft_strcpy(&(new_name[i]), (g_data->test ? ".mycor" : ".cor"));
	// ft_printf("newn = '%s'\n", new_name);
	return (new_name);
}
