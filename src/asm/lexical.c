/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexical.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdamion- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/07 13:25:26 by gdamion-          #+#    #+#             */
/*   Updated: 2019/07/07 13:27:18 by gdamion-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "com.h"

static void	get_string(char **line)
{
	int		len;
	int		size;
	char	*str;
	char	*temp;

	len = 0;
	temp = 0;
	str = *line;
	while ((len = ft_findchar(str + g_data->x, '\"') >= 0)
		&& (size = get_next_line(g_data->fd, &temp)) && g_data->y++)
		ft_catpro(&str, temp);
	if (size || !len)
		errorr(ERR_READING, g_data->x, g_data->y);
	*line = str;
	token_add(STRING);
	g_data->token->content = ft_strsub(str, g_data->x, len);
}

static void	get_text(char *line, t_type type)
{
	int		temp;

	temp = g_data->x;
	token_add(type);
	while (line[g_data->x] && 
			ft_findchar(LABEL_CHARS, line[g_data->x]) >= 0)
		g_data->x++;
	g_data->token->content = ft_strsub(line, temp, g_data->x - temp);
	if ((g_data->x - temp) && line[g_data->x] == LABEL_CHAR)
		label_add();
	else if ((g_data->x - temp) && DELIMITER(line[g_data->x]))
	{
		if (type == INDIRECT)
			g_data->token->type = (is_reg(line + temp, g_data->x - temp))
												? REGISTER : INSTRUCTION;
	}
	else
		errorr("GET_TEXT", g_data->x, g_data->y);
}

static void	get_number(char *line, t_type type)
{
	int		temp;

	temp = g_data->x;
	if (line[g_data->x] == '-')
		g_data->x++;
	while (ft_isdigit(line[g_data->x]))
		g_data->x++;
	if ((g_data->x - temp) && type == DIRECT && DELIMITER(line[g_data->x]))
	{
		token_add(type);
		g_data->token->content = ft_strsub(line, temp, g_data->x - temp);
	}
	else if (type == INDIRECT)
	{
		g_data->x = temp;
		get_text(line, INDIRECT);
	}
	else
		errorr("GET_NUMBER", g_data->x, g_data->y);
}

static void	tokenizing(char *line)
{
	if (line[g_data->x] == SEPARATOR_CHAR && ++g_data->x)
		token_add(SEPARATOR);
	else if (line[g_data->x] == '\n' && ++g_data->x)
		token_add(NEW_LINE);
	else if (line[g_data->x] == '.' && ++g_data->x)
		get_text(line, COMMAND);
	else if (line[g_data->x] == DIRECT_CHAR && ++g_data->x)
	{
		if (line[g_data->x] == LABEL_CHAR && ++g_data->x)
			get_text(line, DIRECT_LABEL);
		else
			get_number(line, DIRECT);
	}
	else if (line[g_data->x] == '\"' && ++g_data->x)
		get_string(&line);
	else if (line[g_data->x] == LABEL_CHAR && ++g_data->x)
		get_text(line, INDIRECT_LABEL);
	else
		get_number(line, INDIRECT);
}

void		lexical_analyzer(void)
{
	int		size;
	char	*line;

	while ((size = get_next_line(g_data->fd, &line))
							&& !(g_data->x = 0)
							&& (++g_data->y))
	{
		ft_printf("{RED}%s{EOC}\n", line);
		while (line[g_data->x])
		{
			skip_whitespaces(line);
			skip_comment(line);
			ft_printf("==%s\n", &(line[g_data->x]));
			if (line[g_data->x])
				tokenizing(line);
		}
		ft_strdel(&line);
	}
	if (size == -1)
		print_error(ERR_READING);
	token_add(END);
}