/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   asm.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdamion- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/04 21:43:25 by gdamion-          #+#    #+#             */
/*   Updated: 2019/07/12 19:01:29 by gdamion-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ASM_H
# define ASM_H

# include "com.h"
# include "asm_error.h"
# include "asm_ops.h"

char					g_buf[CHAMP_MAX_SIZE * 2 + 1];
t_data					*g_data;

typedef enum			e_type
{
	REGISTER = 1,
	DIRECT,
	COMMAND,
	INDIRECT,
	STRING,
	LABEL,
	INSTRUCTION,
	DIRECT_LABEL,
	INDIRECT_LABEL,
	SEPARATOR,
	NEW_LINE,
	END
}						t_type;

typedef struct			s_token
{
	int					x;
	int					y;
	t_type				type;
	int					bytes;
	struct s_token		*next;
	struct s_token		*prev;
	char				*content;
}						t_token;

typedef struct			s_label
{
	int					x;
	int					y;
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

/*
** read_file.c
*/

void					read_file(char *filename);
void					ch_fname(char *fname);

/*
** init.c
*/

void					data_init(int fd);
void					token_add(t_type type);
void					label_add();


/*
** lexical.c
*/

void					lexical_analyzer(t_data *data);

/*
** syntax.c
*/

int						syntax_analiser(t_data *data);
void					valid_champion_info(t_token **temp);
int						valid_arg(t_token *arg, int mask);
void					valid_instruction(t_token **operations);

/*
** codegen1.c
*/

void					args_to_code(t_token **temp, int *place, int op_n);
void					process_label(t_token *label, int byte_num, int *place);
void					write_arg(int arg, int byte_num, int *place);
char					*num_to_hex(int32_t dec, int dir_size);
void					just_write(char *hex, int *place);

/*
** codegen2.c
*/

void					write_comment(char *chcomm, int place);
void					write_name(char *chname, int place);
char					*str_to_code(char *str);
void					write_magic(char* hex, int place);
char					*arg_type_code(int arg_types[3]);

/*
** buf_write.c
*/

void	translate(t_token *code_start);


/*
** filegen.c
*/

void					write_to_file(t_data *data);
char					*newn_create(char *f_name);


/*
** error.c
*/
void	errorr(char *event, int str_no, int col_no);
void	place_write(int str_no, int col_no);
void	free_info(t_data *data);

#endif
