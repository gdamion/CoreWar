/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   code_gen.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdamion- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/07 13:52:13 by gdamion-          #+#    #+#             */
/*   Updated: 2019/07/15 19:58:36 by gdamion-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "com.h"

void	just_write(char *hex, int *place)
{
	int i;

	i = 0;
	if (hex[0] == '0' && hex[1] == 'x')
		i += 2;
	while (hex[i] != '\0')
	{
		if (*place > FULL_SIZE)
			errorr(ERR_BIGEX, 0, 0);
		g_buf[*place] = hex[i];
		(*place)++;
		hex[i]++;
	}
}

char					*num_to_hex(int32_t dec, int dir_size)
{
	char		*hex;
	int			i;
	u_int8_t	temp;
	int			move;

	move = 0;
	i = dir_size * 2 - 1;
	if (!(hex = (char*)malloc(sizeof(char)*(dir_size * 2 + 1))))
		errorr(ERR_ALLOC, 0, 0);
	hex[dir_size] = '\0';
	dir_size--;
	while (dir_size + 1)
	{
		temp = (u_int8_t)((dec >> move) & 0xFF);
		hex[i--] = temp % 16 + (temp % 16 > 9 ? 'a' - 10 : '0');
		hex[i--] = temp / 16 + (temp / 16 > 9 ? 'a' - 10 : '0');
		move += 8;
		dir_size--;
	}
	return(hex);
}

void	write_arg(int32_t arg, int byte_num, int *place)
{
	int		len;
	char	*hex;
	int		zeros;

	hex = num_to_hex(arg, byte_num);
	len = ft_strlen(hex);
	zeros = byte_num * 2 - len;
	while (zeros--)
		g_buf[(*place)++] = '0';
	just_write(hex, place);
	free(hex);
}

void	write_name_or_comm(char *chname, int place, _Bool type)
{
	char	*hex;
	int		len;
	int		i;
	int		max;

	i = 0;
	hex = str_to_code(chname);
	len = ft_strlen(hex);
	max = (type ? PROG_NAME_LENGTH : COMMENT_LENGTH ) * 2;
	if (type)
		(len > max) ? errorr(ERR_CHNAME_LEN, 0, 0) : 1;
	else
		(len > max) ? errorr(ERR_CHCOMM_LEN, 0, 0) : 1;
	while (i < max)
	{
		if (len > 0)
		{
			g_buf[place] = hex[i];
			len--;
		}
		else
			g_buf[place++] = '0';
		i++;
	}
	free(hex);
}

char	*str_to_code(char *str)
{
	char	*res;
	int		len;
	int		i;
	int		buf;

	i = 0;
	len = ft_strlen(str) * 2;
	!(res = (char*)malloc(len + 1)) ? \
		errorr(ERR_ALLOC, 0, 0) : (res[len + 1] = '\0');
	while (i < len)
	{
		res[i] = (buf = *str / 16) < 10 ? \
			('0' + buf) : ('A' + buf - 10);
		res[i + 1] = (buf = *str % 16) < 10 ? \
			('0' + buf) : ('A' + buf - 10);
		str++;
		i += 2;
	}
	return (res);
}

void	write_magic(char* hex, int place)
{
	int i;
	int add_zero;

	i = 0;
	if (hex[0] == '0' && hex[1] == 'x')
		i += 2;
	add_zero = 8 - ft_strlen(&(hex[i]));
	while (hex[i] != '\0')
	{
		if (place > FULL_SIZE)
			errorr(ERR_BIGEX, 0, 0);
		if (add_zero > 0)
			g_buf[place++] = '0';
		else
			g_buf[place] = hex[i];
		place++;
		i++;
	}
	free(hex);
}

void	valid_champion_info(t_token **temp)
{
	int i;
	int name;
	int comm;

	name = 1;
	comm = 1;
	i = 2;
	while (i)
	{
		if (strcmp((*temp)->content, "comment"))
		{
			if ((*temp)->next->type == STRING)
			{
				write_name_or_comm((*temp)->next->content, 8, 0);
				comm--;
				*temp = (*temp)->next->next;
			}
			else
				errorr(ERR_NO_CHCOMM, 0, 0);
		}
		else if (strcmp((*temp)->content, "name"))
		{
			if ((*temp)->next->type == STRING)
			{
				ft_printf("SOS\n");
				write_name_or_comm((*temp)->next->content, 8 + PROG_NAME_LENGTH * 2 + 8 * 2, 1);
				name--;
				*temp = (*temp)->next->next;
			}
			else
				errorr(ERR_NO_CHNAME, 0, 0);
		}
	}
	(name != 0 || comm != 0) ? errorr(ERR_NAMECOM, 0, 0) : 1;
}