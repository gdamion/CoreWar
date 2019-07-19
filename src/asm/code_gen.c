/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   code_gen.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdamion- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/07 13:52:13 by gdamion-          #+#    #+#             */
/*   Updated: 2019/07/19 18:54:14 by gdamion-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "com.h"

void	just_write(char *hex, u_int32_t *place)
{
	int i;

	i = 0;
	if (hex[0] == '0' && hex[1] == 'x')
		i += 2;
	while (hex[i] != '\0')
	{
		if (*place >= FULL_SIZE)
		{
			ft_printf("err: max = %u | place = %d\n",FULL_SIZE - EXEC_START, *place - EXEC_START);
			errorr(ERR_BIGEX);
		}
		// ft_printf("max = %d | place = %d\n",FULL_SIZE- EXEC_START, *place- EXEC_START);
		g_buf[*place] = hex[i];
		(*place)++;
		hex[i]++;
	}
}

void	write_arg(int32_t arg, int byte_num, u_int32_t *place)
{
	int		len;
	char	*hex;
	int		zeros;

	ft_printf("wr arg = %d\n", arg);
	hex = num_to_hex(arg, byte_num);
	len = ft_strlen(hex);
	zeros = byte_num * 2 - len;
	while (zeros--)
		g_buf[(*place)++] = '0';
	ft_printf("wr arg2\n");
	just_write(hex, place);
	free(hex);
	ft_printf("wr arg3\n");
}

void	write_magic(char* hex, int place)
{
	int i;
	int add_zero;

	i = 0;
	if (hex[0] == '0' && hex[1] == 'x')
		i += 2;
	ft_printf("magic wrtie of %s\n", hex);
	add_zero = 8 - ft_strlen(&(hex[i]));
	while (hex[i] != '\0')
	{
		if (place >= FULL_SIZE - EXEC_START)
		{
			ft_printf("err magic: max = %d | place = %d\n", FULL_SIZE, place);
			errorr(ERR_BIGEX);
		}
		// ft_printf("magic: max = %d | place = %d\n", FULL_SIZE, place);
		if (add_zero > 0)
			g_buf[place++] = '0';
		else
			g_buf[place] = hex[i];
		place++;
		i++;
	}
}

char	*num_to_hex(int32_t dec, int dir_size)
{
	char		*hex;
	int			i;
	u_int8_t	temp;
	int			move;
	// uintmax_t a = INT32_MAX;

	ft_printf("num to hex, %d, dir size = %d\n", dec, dir_size);
	move = 0;
	i = dir_size * 2 - 1;
	if (!(hex = (char*)malloc(sizeof(char)*(dir_size * 2 + 1))))
		errorr(ERR_ALLOC);
	ft_printf("num to hex1\n");
	hex[dir_size * 2] = '\0';
	dir_size--;
	while (dir_size + 1)
	{
		// a =INT32_MAX;
		// while (a)
			// a--;
		ft_printf("num to hex2\n");
		temp = (u_int8_t)((dec >> move) & 0xFF);
		hex[i--] = temp % 16 + (temp % 16 > 9 ? 'a' - 10 : '0');
		hex[i--] = temp / 16 + (temp / 16 > 9 ? 'a' - 10 : '0');
		move += 8;
		dir_size--;
	}
	ft_printf("num to hex: from %d to %s\n", dec, hex);
	return(hex);
}
