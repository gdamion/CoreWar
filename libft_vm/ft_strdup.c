/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmann <tmann@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/08 15:59:16 by tmann             #+#    #+#             */
/*   Updated: 2019/07/08 16:04:54 by tmann            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

char	*ft_strdup(const char *s)
{
	char	*dupl;
	char	*tmp;
	int		len;

	len = ft_strlen(s);
	dupl = (char*)malloc(sizeof(char) * (len + 1));
	if (dupl == NULL)
		return (NULL);
	tmp = dupl;
	while (*s)
		*tmp++ = *s++;
	*tmp = '\0';
	return (dupl);
}
