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

# define A(c) (c == '\0')
# define B(c) (c == '\n')
# define C(c) (c == '\"')
# define D(c) (c == DIRECT_CHAR)
# define I(c) (c == SEPARATOR_CHAR)
# define F(c) (c == COMMENT_CHAR)
# define G(c) (SP(c))

# define DELIMITER(c) (A(c) || B(c) || C(c) || D(c) || I(c) || F(c))

void		skip_whitespaces(t_data *data, char *line)
{
	while(SP(line[data->x]))
		data->x++;
}

void		skip_comment(t_data *data, char *line)
{
	if (line[data->x] == COMMENT_CHAR)
		while(line[data->x] && line[data->x] != "\n")
			data->x++;
}

void		get_string(t_data *data, char **line)
{
	int		len;
	int		size;
	char	*str;
	char	*temp;

	len = 0;
	temp = 0;
	str = *line;
	while (!(len = ft_findchar(str + data->x, '\"'))
		&& (size = get_next_line(data->fd, &temp)) && data->y++)
		ft_catpro(&str, temp);
	if (size == -1)
		error(ERR_READING, data->x, data->y);
	if (size == 0)
		error(ERR_READING, data->x, data->y);
	if (!len)
		error(ERR_READING, data->x, data->y);
	*line = str;
	token_add(data, STRING);
	data->token->content = ft_strsub(str, data->x, len);
}

_Bool	is_reg(char *line, int len)
{
	int	i;

	i = 0;
	if (2 <= len && len <= 3 && line[i] == 'r')
	{
		while (ft_isdigit(line[++i]) && i < len)
			;
		return (i == len && ft_atoi(&line[1]) > 0);
	}
	return (FALSE);
}

void		get_text(t_data *data, char *line, t_type type)
{
	int		temp;

	temp = data->x;
	token_add(data, type);
	while (line[data->x] && 
			ft_findchar(LABEL_CHARS, line[data->x]))
		data->x++;
	if ((data->x - temp) && line[data->x] == LABEL_CHAR)
		data->token->type = LABEL;
	else if ((data->x - temp) && DELIMITER(line[data->x]))
	{
		if (type == INDIRECT)
			data->token->type = (is_reg(line + temp, data->x - temp))
											? REGISTER : INSTRUCTION;
	}
	else
		error("GET_TEXT", data->x, data->y);
	data->token->content = ft_strsub(line, temp, data->x - temp);
}

void		get_number(t_data *data, char *line, t_type type)
{
	int		temp;

	temp = data->x;
	if (line[data->x] == '-')
		data->x++;
	while (ft_isdigit(line[data->x]))
		data->x++;
	if ((data->x - temp) && type == DIRECT && DELIMITER(line[data->x]))
	{
		token_add(data, type);
		data->token->content = ft_strsub(line, temp, data->x - temp);
	}
	else if (type == INDIRECT)
	{
		data->x -= temp;
		get_text(data, line, INDIRECT);
	}
	else
		error("GET_NUMBER", data->x, data->y);
}

void		tokenizing(t_data *data, char *line)
{
	if (line[data->x] == SEPARATOR_CHAR && data->x++)
		token_add(data, SEPARATOR);
	else if (line[data->x] == "\n" && data->x++)
		token_add(data, NEW_LINE);
	else if (line[data->x] == '.' && data->x++)
		get_text(data, line, COMMAND);
	else if (line[data->x] == DIRECT_CHAR && data->x++)
	{
		if (line[data->x] == LABEL_CHAR && data->x++)
			get_text(data, line, DIRECT_LABEL);
		else
			get_number(data, line, DIRECT);
	}
	else if (line[data->x] == '\"' && data->x++)
		get_string(data, &line);
	else if (line[data->x] == LABEL_CHAR && data->x++)
		get_text(data, line, INDIRECT_LABEL);
	else
		get_number(data, line, INDIRECT);
}

void		lexical_analyzer(t_data *data)
{
	int		size;
	char	*line;

	while ((size = get_next_line(data->fd, &line))
							&& !(data->x = 0)
							&& (data->y++))
	{
		while (line[data->x])
		{
			if (size == -1)
				error(ERR_READING);
			skip_whitespaces(data, line);
			skip_comment(data, line);
			if (line[data->x])
				tokenizing(data, line);
		}
		ft_strdel(&line);
	}
	if (size == -1)
		error(ERR_READING);
	token_add(data, END);
}