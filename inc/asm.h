/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   asm.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdamion- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/04 21:43:25 by gdamion-          #+#    #+#             */
/*   Updated: 2019/07/27 13:22:56 by gdamion-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# ifndef ASM_H
# define ASM_H

# include "asm_error.h"
# include "asm_ops.h"

# define EXEC_START (4 + PROG_NAME_LENGTH + 4 + 4 + COMMENT_LENGTH + 4)
# define FULL_SIZE (EXEC_START + CHAMP_MAX_SIZE)


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
	_Bool				test;
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
void					read_file(char *filename, _Bool flag);
void					valid_filename(char *fname);

/*
** get_line.c
*/
int						get_line(const int fd, char **row);

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
** process_info.c
*/
void					valid_champion_info(t_token **temp);
void					print_champion_info(t_token *temp);
void					write_name_or_comm(char *cnt, int place, _Bool type);

/*
** buf_write.c
*/
void					translate(t_token *code_start, u_int32_t code_size);
void					print_instruction(t_token **op, u_int32_t *cursor, u_int8_t type);
void					arg_types_code(t_token *op, u_int32_t *cursor, u_int8_t n_arg);
void					print_arg_types_code(u_int8_t arg_types[3], u_int32_t *cursor, u_int8_t n_arg);
int32_t					process_label(u_int32_t bytes, t_token *label);
void					int_to_hex(int32_t dec, int dir_size, u_int32_t *place);
void					uint_to_hex(u_int32_t dec, int dir_size, u_int32_t *place);


/*
** filegen.c
*/
void					write_to_file(void);

/*
** error.c
*/
void					error_event(char *event);
void					error_line(char *event, char *line, int x);
void					error_token(char *event, t_token *token);

/*
** error_msgs.c
*/
void					print_line_error(char *message, char *line, int x);
void					print_token_error(char *message, t_token *token);
void					print_error_info(int x, int y);
void					print_filename(void);

/*
** free_data.c
*/
void					free_data(void);

/*
** utilities.c
*/
_Bool					is_reg(char *line, int len);
void					skip_whitespaces(char *line);
void					skip_comment(char *line);
int32_t					ft_atoi_cor(const char *str, u_int8_t size);

#endif
