#include "com.h"

void		skip_whitespaces(t_data *data, char *line)
{
	while(SP(line[data->cursor]))
		data->cursor++;
}

void		skip_comment(t_data *data, char *line)
{
	if (line[data->cursor] == COMMENT_CHAR)
		while(line[data->cursor] && line[data->cursor] != "\n")
			data->cursor++;
}

void		get_str(t_data *data, char *line)
{
	int		i;
	char	*temp;

	i = 0;
	temp = 0;
	while (line[data->cursor] != '\"')
		data->cursor++;
	while (!ft_findchar(line + data->cursor, '\"')
			&& get_next_line(data->fd, &temp))
		ft_catpro(line, temp);
	if ((i = ft_findchar(line + data->cursor, '\"')) > PROG_NAME_LENGTH)
		error(ERR_CHNAME_LEN, {str}, {col}); //add str and col
	token_add(data, STRING);
	data->token->content = ft_strsub(line, data->cursor, i);
}

void		get_cmd(t_data *data, char *line)
{
	token_add(data, COMMAND);
	if (!ft_strcmp(NAME_CMD_STRING, line))
		data->token->content = NAME_CMD_STRING;
}

/*
	while (ft_findchar(LABEL_CHARS, *(line + data->cursor)))
		data->cursor++;
*/

void		tokenizing(t_data *data, char *line)
{
	if (line[data->cursor] == '.')
		get_cmd(data, line);
	else if (line[data->cursor] == '\"' && data->cursor++)
		get_str(data, line);
}

void		syntax_analyzer(t_data *data)
{
	int		size;
	char	*line;

	while ((size = get_next_line(data->fd, &line))
							&& !(data->cursor = 0))
	{
		if (size == -1)
			error(ERR_READING);
		skip_whitespaces(data, line);
		skip_comment(data, line);
		if (line[data->cursor])
			tokenizing(data, line);
		ft_strdel(&line);
	}
	if (size == -1)
		error(ERR_READING);
}

void	ch_fname(char *fname)
{
	while(*fname != '\0')
	{
		if (*fname == '.')
			break;
		fname++;
	}
	ft_strcmp(fname, ".s") ? error(ERR_FNAME) : 1;
}

void		read_file(char *filename)
{
	int		fd;
	t_data	*data;

	check_fname(filename); // is name of file correct?
	((fd = open(filename, O_RDONLY)) == -1) ? \
		error(ERR_FOPEN, 0, 0) : data_init(&data, fd);
	syntax_analyzer(data);
}
