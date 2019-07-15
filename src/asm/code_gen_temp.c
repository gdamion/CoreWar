/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   code_gen_temp.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdamion- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/12 18:32:59 by gdamion-          #+#    #+#             */
/*   Updated: 2019/07/15 19:59:13 by gdamion-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "com.h"

char	*arg_type_code(int arg_types[3])
{
	int i;
	int bin;
	char res[3];

	i = 0;
	bin = 0;
	while (i < 3)
	{
		if (arg_types[i] == T_REG)
			bin = bin | (1 << (3 - i) * 2);
		else if (arg_types[i] == T_DIR)
			bin = bin | (2 << (3 - i) * 2);
		else if (arg_types[i] == T_IND)
			bin = bin | (3 << (3 - i) * 2);
	}
	res[0] = bin / 16;
	res[1] = bin % 16;
	res[2] = '\0';
	return (res);
}
