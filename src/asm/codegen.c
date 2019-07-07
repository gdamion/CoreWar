/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   codegen.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdamion- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/07 13:52:13 by gdamion-          #+#    #+#             */
/*   Updated: 2019/07/07 14:21:22 by gdamion-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "com.h"

void	write_to_buf(char* hex, int *place)
{

	if (len > CHAMP_MAX_SIZE)
		error(ERR_BIGEX);
}

void	name_to_code(char *chname)
{

	if (len > PROG_NAME_LENGTH)
		error(ERR_CHNAME_LEN);
	write_to_buf();
}

void	comment_to_code(char *chcomm)
{

	if (len > COMMENT_LENGTH)
		error(ERR_CHCOMM_LEN);
	write_to_buf();
}

void	op_to_code(t_token op)
{

	write_to_buf();
}

