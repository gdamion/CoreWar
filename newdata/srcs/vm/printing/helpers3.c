/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helpers3.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmann <tmann@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/22 18:36:22 by tmann             #+#    #+#             */
/*   Updated: 2019/07/22 18:36:24 by tmann            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../vm.h"

void	ft_fd_error(int fd)
{
	ft_printf("Error: fd(%d)\n", fd);
	exit(-1);
}

void	allocate_memory_error(void)
{
	ft_printf("Can't allocate memory\n");
	exit(-1);
}
