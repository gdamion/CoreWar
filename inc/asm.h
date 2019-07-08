/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   asm.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdamion- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/04 21:43:25 by gdamion-          #+#    #+#             */
/*   Updated: 2019/07/07 15:05:14 by gdamion-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ASM_H
# define ASM_H

# include "com.h"
# include "asm_error.h"
# include "asm_ops.h"

char					g_buf[CHAMP_MAX_SIZE + 1];

typedef enum			e_type
{
	COMMAND,
	STRING,
	LABEL,
	INSTRUCTION,
	REGISTER,
	DIRECT,
	DIRECT_LABEL,
	INDIRECT,
	INDIRECT_LABEL,
	SEPARATOR,
	NEW_LINE,
	END
}						t_type;

typedef struct			s_token
{
	char				*content;
	t_type				type;
	int					str;
	int					col;
	struct s_token		*next;
	struct s_token		*prev;
}						t_token;

typedef struct			s_label
{
	char				*name;
	t_token				*point;
	struct s_label		*next;
	struct s_label		*prev;
}						t_label;

typedef struct			s_data
{
	int					x;
	int					y;
	int					fd;
	char				*f_name;
	t_token				*token;
	t_label				*label;
}						t_data;

# define Q(c) (c == '\0')
# define W(c) (c == '\n')
# define E(c) (c == '\"')
# define R(c) (c == DIRECT_CHAR)
# define T(c) (c == SEPARATOR_CHAR)
# define Y(c) (c == COMMENT_CHAR)
# define U(c) (SP(c))

# define DELIMITER(c) (Q(c) || W(c) || E(c) || R(c) || T(c) || Y(c) || U(c))

# define INIT_DATA (!(temp = (t_data*)ft_memalloc(sizeof(t_data))))
# define INIT_TOKEN (!(new = (t_token*)ft_memalloc(sizeof(t_token))))
# define INIT_LABEL (!(new = (t_label*)ft_memalloc(sizeof(t_label))))

void		read_file(char *filename);
void		data_init(t_data **data, int fd);
void		lexical_analyzer(t_data *data);
void		skip_whitespaces(t_data *data, char *line);
void		skip_comment(t_data *data, char *line);
void		token_add(t_data *data, t_type type);
void		label_add(t_data *data);
_Bool		is_reg(char *line, int len);
void		syntax_analiser(t_data *data);


void		error(char *err_place, int str_no, int col_no, t_data *data);

#endif
