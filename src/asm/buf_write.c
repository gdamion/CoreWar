/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   buf_write.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdamion- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/12 14:34:07 by gdamion-          #+#    #+#             */
/*   Updated: 2019/07/12 18:45:37 by gdamion-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "com.h"

void	translate(t_token *code_start)
{

}


	write_magic(args_to_code(), 8 + PROG_NAME_LENGTH * 2 + 8); //размер исполняемого кода
	write_magic(COREWAR_EXEC_MAGIC, 0); //магический заголовок
	write_magic("", 8 + PROG_NAME_LENGTH * 2); //разделитель
	write_magic("", 8 + PROG_NAME_LENGTH * 2 + 8 * 2 + COMMENT_LENGTH * 2); //разделитель

	cursor = 8 + PROG_NAME_LENGTH * 2 + 8 * 2 + COMMENT_LENGTH * 2 + 8; //cursor stays on code place

	short			arg_types[3];
	ft_bzero(arg_types, sizeof(int) * 3);
//операции
	just_write(g_op_tab[op_n].code, cursor); //write code name of operation
	g_op_tab[op_n].args_types_code ? just_write(arg_type_code(arg_types), cursor) : 1; //код типов аргументов
	args_to_code(operations, &cursor, op_n); // печать аргументов данной операции
