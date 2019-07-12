/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   buf_write.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdamion- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/12 14:34:07 by gdamion-          #+#    #+#             */
/*   Updated: 2019/07/12 14:37:08 by gdamion-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	valid_instruction(t_token **operations/* , int *cursor*/)
{
	int				op_n;
	unsigned int	args;
	unsigned int	*types;
	t_token			*temp;
	// short			arg_types[3];

	// ft_bzero(arg_types, sizeof(int) * 3);
	temp = (*operations)->next;
	(op_n = op_exist(temp->content)) == -1 ? \
		errorr(ERR_OP, temp->x, temp->y) : 1;
	// just_write(g_op_tab[op_n].code, cursor); //write code name of operation
	args = g_op_tab[op_n].args_num;
	types = g_op_tab[op_n].args_types;
	while ((temp->type < 3 || temp->type == 4) && args--)
	{
		valid_arg(temp, (*types)++);
		// arg_types[3 - args + 1] = temp->type;
		(temp->next->type != SEPARATOR) ? errorr(ERR_TOKEN, \
			temp->next->x, temp->next->y) : (temp = temp->next->next);
	}
	(args || args < 0) ? errorr(ERR_ARGNO, temp->x, temp->y) : 1;
	// g_op_tab[op_n].args_types_code ? just_write(arg_type_code(arg_types), cursor) : 1;
	// args_to_code(operations, &cursor, op_n); // здесь будут выводиться аргументы, сюда нужно передать t_token, возможно
}

void	valid_label() //проверить, что такая метка содержит правильные символы, что название не повторяется добавить ее в список???
{

}

void	syntax_analiser(t_data *data)
{
	t_token	*temp;
	// int		cursor;
	t_token *op;

////////////////// DONT TOUCH
	// write_magic(COREWAR_EXEC_MAGIC, 0); //add magic header
	// write_magic("", 8 + PROG_NAME_LENGTH * 2); //add 8 zeros as separator
	// write_magic("", 8 + PROG_NAME_LENGTH * 2 + 8 * 2 + COMMENT_LENGTH * 2); //add 8 zeros as separator
	// temp = data->token;
	// valid_champion_info(&temp);
	// cursor = 8 + PROG_NAME_LENGTH * 2 + 8 * 2 + COMMENT_LENGTH * 2 + 8; //cursor stays on code place
//////////////////
	while (temp)
	{
		if (temp->type == INSTRUCTION)
			valid_instruction(&temp/* , &cursor*/);
		else if (temp->type == LABEL)
		{
			valid_label(/*&cursor*/);
			temp = temp->next;
		}
		else
			errorr(ERR_SYM, temp->x, temp->y);
		temp = temp->prev;
	}
	// write_magic(args_to_code(), 8 + PROG_NAME_LENGTH * 2 + 8); //add exec code size
}
