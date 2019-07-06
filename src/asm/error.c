/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdamion- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/06 11:57:52 by gdamion-          #+#    #+#             */
/*   Updated: 2019/07/06 13:56:59 by gdamion-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//#include "com.h"

#include <stdio.h>
#include <stdlib.h>
#include <errno.h>

void	error(char *err_place, int str_no, int col_no)
{
	if (errno)
		perror(err_place);
	else
		ft_printf("Error: %s, string %d col %d\n", err_place, str_no, col_no);
	free_info();
	exit(1);
}

