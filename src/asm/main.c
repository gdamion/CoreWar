                               /* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdamion- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/04 21:38:07 by gdamion-          #+#    #+#             */
/*   Updated: 2019/07/07 10:19:40 by gdamion-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "com.h"

int		main(int ac, char **av)
{
	errno = 0;
	g_data = 0;
	g_bytes = 0;
	ft_bzero(g_buf, FULL_SIZE + 1);
	ft_printf("START\n");
	if (ac == 2)
		read_file(av[1]);
	else
		errorr(ERR_NOFILE);
	ft_printf("FINISH\n");
	return (0);
}
