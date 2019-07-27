/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmann <tmann@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/08 15:59:16 by tmann             #+#    #+#             */
/*   Updated: 2019/07/08 16:03:17 by tmann            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdlib.h>
# include <stdarg.h>
# include <unistd.h>
# include "libft.h"
# include <inttypes.h>

# define H 1
# define HH 2
# define L 3
# define LL 4
# define J 5
# define Z 6
# define HASH 1
# define PLUS 2
# define MINUS 3
# define ZERO 4
# define SPACE 5

typedef struct	s_fmt
{
	int			fd;
	int			total_len;
	int			i;
	short		hash;
	short		plus;
	short		minus;
	short		zero;
	short		space;
	short		adjust;
	int			field_width;
	int			len_modif;
	int			precision;
	short		pmf;
	short		have_prec;
	short		mode;
	short		fl_sign;
	int			is_pl;
	int			was_m;
	int			j;
}				t_fmt;

char			*double_to_str(long double num, int k_prec, int rem);
void			move_str_right(char **str);
void			round_prec_zero(t_fmt *f, char **str, int flag);
void			round_prec_all(t_fmt *f, char **str, int flag);
void			round_nine(t_fmt *f, char **str);
void			set_jz_modif(const char *fmt, t_fmt *f);
int				l_strlen(char *str);
void			set_width(const char *fmt, t_fmt *f);
int				ft_printf(const char *fmt, ...);
void			print_rounded(t_fmt *f, char **str);
char			*long_double_to_str(long double num, int k_prec);
void			print_str(t_fmt *f, va_list ap);
void			print_ptr(t_fmt *f, va_list ap);
void			print_floating_point(t_fmt *f, va_list ap);
void			print_char(t_fmt *f, va_list ap);
void			print_octal(t_fmt *f, va_list ap);
void			print_hex(short mode, t_fmt *f, va_list ap);
void			print_unsigned_decimal(t_fmt *f, va_list ap);
void			print_decimal(t_fmt *f, va_list ap);
long			calc_len(long n, long count);
int				ft_parse_args(const char *fmt, t_fmt *f, va_list ap);
void			reset_format(t_fmt *f);
void			print(const char *fmt, t_fmt *f, va_list ap);

#endif
