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

#include "asm.h"

int		main(int ac, char **av)
{
	errno = 0;
	g_data = 0;
	g_bytes = 0;
	g_buf = NULL;
	// ft_printf("START\n");
	if (ac == 2)
		read_file(av[1], 0);
	else if (ac == 3 && !ft_strcmp(av[2], "-test"))
		read_file(av[1], 1);
	else
		error_event(ERR_NOFILE, 0);
	// ft_printf("FINISH\n");
	return (0);
}
