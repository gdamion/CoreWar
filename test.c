#include "com.h"

int main()
{
	int		fd;
	char	*new_name;

	new_name = "test.cor";
	if (fd = open(new_name, O_TRUNC | O_WRONLY) == -1)
			ft_printf("ok? really???111\n");
	ft_printf("Writing output program to %s, fd = %d\n", new_name, fd);
//free(new_name);
	if (write(fd, "HOPHEY", 6) == -1)
	{
		close(fd);
		ft_printf("ok? really???222\n");
	}
	close(fd);
}

