#include "com.h"

void		data_init(t_data **data, int fd)
{
	t_data	*temp;

	if (INIT_DATA)
		error(ERR_ALLOC);
	ft_bzero(temp, sizeof(temp));
	temp->fd = fd;
	*data = temp;
}

void		token_add(t_data *data, t_type type)
{
	t_token	*new;

	if (INIT_TOKEN)
		error(ERR_ALLOC);
	ft_bzero(new, sizeof(new));
	new->type = type;
	if (data->token)
		data->token->prev = new;
	new->next = data->token;
	data->token = new;
}
