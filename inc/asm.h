/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   asm.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdamion- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/04 21:43:25 by gdamion-          #+#    #+#             */
/*   Updated: 2019/07/05 14:56:03 by gdamion-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ASM_H
# define ASM_H

# include "com.h"
# include "asm_error.h"
# include "asm_ops.h"

typedef enum			e_type
{
	COMMAND,
	STRING,
	LABEL,
	OPERATOR,
	REGISTER,
	DIRECT,
	DIRECT_LABEL,
	INDIRECT,
	INDIRECT_LABEL,
	SEPARATOR,
	NEW_LINE,
	END
}						t_type;

typedef struct			s_data
{
	int					fd;
	char				*name;
	unsigned			cursor;
	t_token				*token;
}						t_data;

typedef struct			s_token
{
	char				*content;
	t_type				type;
	struct s_token		*next;
	struct s_token		*prev;
}						t_token;


# define INIT_DATA (!(temp = (t_data*)ft_memalloc(sizeof(t_data))))
# define INIT_TOKEN (!(new = (t_token*)ft_memalloc(sizeof(t_token))))

void		read_file(char *filename);
void		data_init(t_data **data, int fd);
void		token_add(t_data *data, t_type type);


#endif
