/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_error.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdamion- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/20 19:59:28 by lmaron-g          #+#    #+#             */
/*   Updated: 2019/07/18 19:33:23 by gdamion-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/libft.h"
#include <stdlib.h>
#include <stdio.h>
#include <errno.h>

void		print_error(char *message)
{
	if (errno == 0)
		ft_putendl_fd(message, 2);
	else
		perror(message);
	ft_putstr_fd(EOC, 2);
	exit(1);
}
