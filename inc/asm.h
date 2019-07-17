/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   asm.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdamion- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/04 21:43:25 by gdamion-          #+#    #+#             */
/*                                                                            */
/* ************************************************************************** */

#ifndef ASM_H
# define ASM_H

# include "asm_error.h"
# include "asm_ops.h"

# define FULL_SIZE ((4 + PROG_NAME_LENGTH + 4 + 4 \
						+ COMMENT_LENGTH + 4 + CHAMP_MAX_SIZE) * 2 + 1)


typedef enum			e_type
{
	REGISTER = 1,
	DIRECT,
	DIRECT_LABEL,
	INDIRECT,
	INDIRECT_LABEL,
	COMMAND,
	STRING,
	LABEL,
	INSTRUCTION,
	SEPARATOR,
	NEW_LINE,
	END
}						t_type;

typedef struct			s_token
{
	int					x;
	int					y;
	t_type				type;
	u_int32_t			bytes;
	struct s_token		*next;
	struct s_token		*prev;
	char				*content;
}						t_token;

typedef struct			s_label
{
	t_token				*point;
	struct s_label		*next;
	struct s_label		*prev;
}						t_label;

typedef struct			s_data
{
	int					x;
	int					y;
	int					fd;
	char				*filename;
	t_token				*token;
	t_label				*label;
}						t_data;

# define Q(c) (c == '\0')
# define W(c) (c == '\n')
# define E(c) (c == '\"')
# define R(c) (c == DIRECT_CHAR)
# define T(c) (c == SEPARATOR_CHAR)
# define Y(c) (c == COMMENT_CHAR)
# define U(c) (SP1(c))

# define DELIMITER(c) (Q(c) || W(c) || E(c) || R(c) || T(c) || Y(c) || U(c))

# define INIT_DATA (!(temp = (t_data*)ft_memalloc(sizeof(t_data))))
# define INIT_TOKEN (!(new = (t_token*)ft_memalloc(sizeof(t_token))))
# define INIT_LABEL (!(new = (t_label*)ft_memalloc(sizeof(t_label))))

/*
** read_file.c
*/
void					read_file(char *filename);
void					valid_filename(char *fname);

int			get_line(const int fd, char **row);
/*
** init.c
*/
void					data_init();
void					token_add(t_type type);
void					label_add(void);

/*
** lexical.c
*/
void					lexical_analyzer(void);

/*
** syntax.c
*/
void					syntax_analyser(t_token	*code_start);

/*
** code_gen.c
*/
void					just_write(char *hex, u_int32_t *place);
void					write_arg(int32_t arg, int byte_num, u_int32_t *place);
void					write_magic(char *hex, int place);
char					*num_to_hex(int32_t dec, int dir_size);

/*
** valid_info.c
*/
void					valid_champion_info(t_token **temp);
void					find_info_string(t_token **temp, _Bool type);
void					write_name_or_comm(t_token *temp, int place, _Bool type);
char					*str_to_code(char *str);

/*
** buf_write.c
*/
void					translate(t_token *code_start, u_int32_t code_size);
void					print_instruction(t_token **op, u_int32_t *cursor, u_int8_t type);
void					print_arg_types_code(t_token *op, u_int32_t *cursor, u_int8_t n_arg);
char					*arg_type_code(u_int8_t arg_types[3]);
int32_t					process_label(u_int32_t bytes, char *label_name);

/*
** filegen.c
*/
void					write_to_file(void);
char					*new_filename(char *filename);

/*
** error.c
*/
void					errorr(char *event);
void					error_log(char *event, char *line, int x);
void					log_error(char *event, t_token *token);
void					free_data(t_data *data);

_Bool					is_reg(char *line, int len);
void					skip_whitespaces(char *line);
void					skip_comment(char *line);

#endif
