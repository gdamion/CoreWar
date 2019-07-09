/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   com.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdamion- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/04 21:43:57 by gdamion-          #+#    #+#             */
/*   Updated: 2019/07/09 15:00:54 by gdamion-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef COM_H
# define COM_H

# define TRUE 1
# define FALSE 0

# include "libft.h"

# include "op.h"
# include "asm.h"

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

#endif
