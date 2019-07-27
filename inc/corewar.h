/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   corewar.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdamion- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/22 18:38:40 by tmann             #+#    #+#             */
/*   Updated: 2019/07/27 18:49:22 by gdamion-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef COREWAR_H
# define COREWAR_H

# include "libft.h"
# include "op.h"
# include <stdbool.h>
# include <unistd.h>
# include <ncurses.h>
# include <stdio.h>
# include <time.h>
# include <fcntl.h>

# define ANSI_COLOR_RED     "\x1b[31m"
# define ANSI_COLOR_GREEN   "\x1b[32m"
# define ANSI_COLOR_YELLOW  "\x1b[33m"
# define ANSI_COLOR_BLUE    "\x1b[34m"
# define ANSI_COLOR_MAGENTA "\x1b[35m"
# define ANSI_COLOR_CYAN    "\x1b[36m"
# define ANSI_COLOR_RESET   "\x1b[0m"

# define RUNNING 			713
# define CYCLE_PER_SEC		1225
# define CYCLE_COORD		1993
# define PROCESSES			2505
# define PL_ONE_LIVE		3529

# define LIVE_CODE	0x01
# define LD_CODE 	0x02
# define ST_CODE	0x03
# define ADD_CODE	0x04
# define SUB_CODE	0x05
# define AND_CODE	0x06
# define OR_CODE	0x07
# define XOR_CODE	0x08
# define ZJMP_CODE	0x09
# define LDI_CODE	0x0a
# define STI_CODE	0x0b
# define FORK_CODE	0x0c
# define LLD_CODE	0x0d
# define LLDI_CODE	0x0e
# define LFORK_CODE	0x0f
# define AFF_CODE	0x10

# define LIVE_CYCLE_CD	10
# define LD_CYCLE_CD	5
# define ST_CYCLE_CD	5
# define ADD_CYCLE_CD	10
# define SUB_CYCLE_CD	10
# define AND_CYCLE_CD	6
# define OR_CYCLE_CD	6
# define XOR_CYCLE_CD	6
# define ZJMP_CYCLE_CD	20
# define LDI_CYCLE_CD	25
# define STI_CYCLE_CD	25
# define FORK_CYCLE_CD	800
# define LLD_CYCLE_CD	10
# define LLDI_CYCLE_CD	50
# define LFORK_CYCLE_CD	1000
# define AFF_CYCLE_CD	2

typedef struct	s_binary_r
{
	unsigned char	*arr;
	int				size;
	int				i;
	int				player_num;
	int				dump;
	int				*used_num_names;
}				t_binary_r;

typedef	struct	s_player
{
	int			num;
	char		*name;
	char		*comment;
	int			exec_size;
	char		*exec;
	int			live_count;
	int			prev_live_count;
	int			die_player_circle;
	int			live_coord;
}				t_player;

typedef struct	s_carriage
{
	int					id;
	int					color;
	int					num_of_carriage;
	int					carry;
	int					num_of_curr_key;
	int					last_live_check;
	int					cycles_to_use_oper;
	int					curr_position;
	int					byte_jump;
	int					oper_code;
	bool				is_alive;
	bool				is_oper_executed;
	int					regs[REG_NUMBER];
	struct s_carriage	*next;
	struct s_carriage	*prev;
}				t_carriage;

typedef struct	s_game
{
	int				winner_num;
	unsigned char	*arena;
	unsigned char	*arena_which_champ;
	int				*bright_arr;
	int				arena_size;
	int				cycle_to_die;
	int				live_check_cycle;
	int				live_checks_count;
	int				count_of_live_checks;
	int				is_first_die_cycle;
	int				cycle_delta;
	int				champs_count;
	int				alive_carrs_count;
	long long		cycle_count;
	int				dump;
	bool			verbose;
	bool			graphic;
	t_player		**champs;
	int				live_curr;
	int				game_info;
	int				cycles_per_sec;
	int				carrs_count;
	int				time;
}				t_game;

typedef struct	s_oper
{
	int			i;
	int			j;
	int			arg_byte_pose;
	int			arg1_print;
	int			arg2_print;
	int			arg3_print;
	int			arg1;
	int			arg2;
	int			arg3;
	int			arg1_type;
	int			arg2_type;
	int			arg3_type;
	bool		is_arg1_set;
	bool		is_arg2_set;
	bool		is_arg3_set;
	int			address_print;
	int			move_len;
	int			carr_id;
}				t_oper;

void			place_all_champs_execs(t_game *game);
void			read_binary_file(int fd, t_binary_r *file);
char			*get_champ_name(t_binary_r *file);
int				get_champ_exec_code_size(t_binary_r *file);
void			fd_error(int fd);
char			*get_champ_comment(t_binary_r *file);
char			*get_champ_exec(t_binary_r *file, int exec_size);
int				get_champs_count(t_player **champs);
t_player		*prepare_player(t_binary_r *file, int gc);
t_game			*prepare_field(t_player **champs);
void			ft_fd_error(int fd);
t_binary_r		*init_binary_represent();
t_player		*init_player(int gc);
t_player		**init_champs(t_player **champs, t_player *new_player);
t_game			*init_game(int *gc, char **av);
void			init_oper(t_oper *operation, int carr_id);
void			print_all_champs(t_player **champs);
void			print_player_info(t_player *player);
void			print_binary_file(t_binary_r *file);
void			print_arena(t_game *game, int carr_id, int carr_pos);
void			print_game_info(t_game *game);
void			print_operation_args(t_oper oper);
t_carriage		*init_carr(t_game *game, int curr_carr);
t_carriage		*init_all_carrs(t_game *game);
t_carriage		*add_carr(t_carriage **head, t_carriage *last_carr);
int				parse_args(char byte, int arg);
void			exec_sti(t_carriage *carr, t_game *game);
void			exec_comand(t_carriage *carr, t_game *game);
void			check_args(t_binary_r *file, t_player *pl);
void			check_magic_header(t_binary_r *file);
void			check_null(t_binary_r *file);
void			check_exec_size(t_player *pl);
void			compare_exec_with_size(int exec_size, int read);
void			get_comand(t_carriage *carr, t_game *game);
void			exec_comand(t_carriage *carr, t_game *game);
void			exec_live(t_carriage *carr, t_game *game);
void			exec_ld(t_carriage *carr, t_game *game);
void			exec_st(t_carriage *carr, t_game *game);
void			exec_add(t_carriage *carr, t_game *game);
void			exec_sub(t_carriage *carr, t_game *game);
void			exec_and(t_carriage *carr, t_game *game);
void			exec_or(t_carriage *carr, t_game *game);
void			exec_xor(t_carriage *carr, t_game *game);
void			exec_zjmp(t_carriage *carr, t_game *game);
void			exec_ldi(t_carriage *carr, t_game *game);
void			exec_sti(t_carriage *carr, t_game *game);
void			exec_fork(t_carriage *carr, t_game *game);
void			exec_lld(t_carriage *carr, t_game *game);
void			exec_lldi(t_carriage *carr, t_game *game);
void			exec_lfork(t_carriage *carr, t_game *game);
void			exec_aff(t_carriage *carr, t_game *game);
int				get_arg_value(t_game *game, int i, int arg_size);
t_carriage		*copy_carr(t_carriage *carr);
int				get_arg_value_test(int num, int i, int arg_size);
void			place_bytes(t_game *game, int address, int arg);
t_carriage		*rev_carr(t_carriage *carr);
int				t_reg_checker(t_oper *oper, int arg_num);
void			move_carr(t_carriage *carr, int move_count);
int				move_arg(int curr_pos, int move_count);
void			change_oper_read_pos(t_oper *oper, int move_count);
int				return_valid_n(char *flag, char *num);
int				save_champ_num(char *num, char *name);
void			check_name(char *name);
void			usage(char *arg);
void			allocate_memory_error();
void			start_game(t_game *game, t_carriage **head);
int				find_dump(int *ac, char **av);
void			find_all_n(t_game *game, int **used_nums, int *ac, char **av);
void			add_num_to_arr(int *used_nums, int num);
void			delete_args(int *ac, char **av, int i, int skipped);
void			read_one_champ(t_game *game, char *av, int player_num);
int				check_valid_dump(char *dump_int);
void			print_gc(int ac, char **av);
int				deter_num(int *used_numes);
void			check_champs_nums_and_amount(t_game *game);
void			introduce_players(t_game *game);
void			print_adv(unsigned char *arena, int begin, int end);
void			print_sti(t_game *game, t_oper op);
void			print_ld(t_game *game, t_oper op);
void			print_zjmp(t_game *game, t_carriage *carr, t_oper op);
void			add_to_end(t_carriage *head, t_carriage *new_carry);
void			print_add(t_game *game, t_oper op);
void			print_sub(t_game *game, t_oper op);
void			print_and(t_game *game, t_oper op);
void			print_or(t_game *game, t_oper op);
void			print_xor(t_game *game, t_oper op);
void			print_fork(t_game *game, t_oper op);
void			print_st(t_game *game, t_oper op);
void			print_ldi(t_game *game, t_oper op);
void			print_lld(t_game *game, t_oper op);
void			print_lldi(t_game *game, t_oper op);
void			print_lfork(t_game *game, t_oper op);
void			print_live(t_game *game, t_oper op, int have_player);
int				find_verbose(int *ac, char **av);
int				find_graphic(int *ac, char **av);
void			print_usage(char *name);
int				find_player_by_num(t_game *game, int num);
void			init_screen(t_game *game, t_carriage *carr);
void			draw_arena(t_game *game, t_carriage *carr);
void			draw_borders();
void			draw_code(t_game *game);
void			draw_info(t_game *game, t_carriage *carr);
void			print_bold_str(char *str);
void			init_colors();
void			add_coordination_live(t_player *pl, int y, int x);
void			print_nbr_ncurses(int num);
int				return_y(int coord);
int				return_x(int coord);
void			draw_live_bar(t_game *game);
void			draw_game_info(t_game *game);
void			reset_live_count_of_players(t_game *game);
int				count_carrs(t_carriage *carr);
t_carriage		*find_first_carr(t_carriage *carr);
void			draw_carrs(t_game *game, t_carriage *carr);
void			prepare_screen();
void			add_to_start(t_carriage **head, t_carriage *new_carry);
void			print_rendering_command(unsigned char *arena, int begin,
int end);
void			print_bright(unsigned char *str, int color, int i);
void			draw_frame(t_game *game);
void			array_index_to_move_coord(int *y, int *x, int arr_index);
int				check_bright(t_game *game, int i);
void			pause_run(t_game *game, t_carriage *carr);
void			nclean(int count);
int				get_new_pos(int address);
void			print_carr_dead(int process, int cycles_dead,
int cycles_to_die);
void			print_winner(t_game *game);
int				get_current_live_checks(t_carriage **head);
void			check_alive_after_zero_cycles_to_die(t_game *game,
t_carriage **head);
void			check_alive_players(t_game *game, t_carriage **head);
void			draw_live_bar_for_each_champ(t_game *game, int which_lives);
void			draw_curr_lives(t_game *game);
void			draw_prev_lives(t_game *game);
void			draw_usage();
t_carriage		*get_end(t_carriage **head);
t_carriage		*get_last_carr(t_carriage **head);
void			check_alive_after_zero_cycles_to_die(t_game *game,
t_carriage **head);
void			check_alive_players(t_game *game, t_carriage **head);
void			process_keyboard(t_game *game, t_carriage *carr, char ch);
int				print_bright_live(t_game *game, int i);
int				print_bright_st(t_game *game, int i);
void			print_hyphen_prev(t_game *game, int *total_perc, int lives,
int i);
void			print_hyphen_curr(t_game *game, int *total_perc, int lives,
int i);
int				work_with_speed_when_paused(t_game *game, char ch);
void			draw_info_2(t_game *game, t_carriage *carr);
void			print_gc(int ac, char **av);
void			get_t_reg_value(t_game *game, t_oper *oper, int arg_num);
void			get_t_ind_value(t_game *game, t_oper *oper, int arg_num);
void			get_t_dir_value(t_game *game, t_oper *oper, int arg_num);
void			get_t_dir_short_value(t_game *game, t_oper *oper, int arg_num);
void			check_order(t_game *game);
void			sti_graphic(t_game *game, t_carriage *carr, int address);
void			st_graphic(t_game *game, t_carriage *carr, int address);
void			end_game(char ch);
void			free_champs(t_game *game);
void			free_carrs(t_carriage **head);
void			free_binary_presentation(t_binary_r *file);
void			free_game(t_game *game);

#endif
