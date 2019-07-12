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

static void	get_string(t_data *data, char **line)
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
		error(ERR_READING, data->x, data->y, data);
	if (size == 0)
		error(ERR_READING, data->x, data->y, data);
	if (!len)
		error(ERR_READING, data->x, data->y, data);
	*line = str;
	token_add(data, STRING);
	data->token->content = ft_strsub(str, data->x, len);
}

static void		get_text(t_data *data, char *line, t_type type)
{
	int		temp;

	temp = data->x;
	token_add(data, type);
	while (line[data->x] && 
			ft_findchar(LABEL_CHARS, line[data->x]))
		data->x++;
	if ((data->x - temp) && line[data->x] == LABEL_CHAR)
		label_add(data, line, temp);
	else if ((data->x - temp) && DELIMITER(line[data->x]))
	{
		if (type == INDIRECT)
			data->token->type = (is_reg(line + temp, data->x - temp))
											? REGISTER : INSTRUCTION;
	}
	else
		error("GET_TEXT", data->x, data->y, data);
	data->token->content = ft_strsub(line, temp, data->x - temp);
	data->label->name = data->token->content;
}

static void		get_number(t_data *data, char *line, t_type type)
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
		data->x = temp;
		get_text(data, line, INDIRECT);
	}
	else
		error("GET_NUMBER", data->x, data->y, data);
}

static void		tokenizing(t_data *data, char *line)
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
			data->x = skip_whitespaces(line, data->x);
			data->x = skip_comment(line, data->x);
			if (line[data->x])
				tokenizing(data, line);
		}
		ft_strdel(&line);
	}
	if (size == -1)
		print_error(ERR_READING);
	token_add(data, END);
}