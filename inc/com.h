/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   com.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdamion- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/04 21:43:57 by gdamion-          #+#    #+#             */
/*   Updated: 2019/07/20 13:35:57 by gdamion-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef COM_H
# define COM_H

# define TRUE 1
# define FALSE 0

# include "libft.h"

# include "op.h"
# include "asm.h"

# include "libft.h"

# include <errno.h>
# include <sys/types.h>
# include <sys/stat.h>
# include <fcntl.h>
# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include <string.h>

/*
** We can use:
** open read lseek write close malloc
** realloc free perror strerror exit
*/

char		*g_buf;
t_data		*g_data;
u_int32_t	g_bytes;

#endif
