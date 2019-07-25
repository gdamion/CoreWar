/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmann <tmann@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/08 15:59:16 by tmann             #+#    #+#             */
/*   Updated: 2019/07/08 16:08:10 by tmann            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <string.h>
#include "libft.h"

static	size_t	calculate_trim_len_start(char const *s)
{
	size_t	len;

	len = 0;
	while (s[len] == ' ' || s[len] == '\t' || s[len] == '\n')
		len++;
	return (len);
}

char			*ft_strtrim(char const *s)
{
	char	*new_str;
	size_t	i;
	size_t	len;
	size_t	j;

	i = 0;
	j = 0;
	if (!s)
		return (NULL);
	len = calculate_trim_len_start(s);
	i = ft_strlen(s) - 1;
	while ((s[i] == ' ' || s[i] == '\t' || s[i] == '\n') && i != 0)
		i--;
	if (s[0] == '\0')
		return (ft_strdup(""));
	new_str = (i > len) ? ft_strnew(i - len + 1) : ft_strnew(ft_strlen(s) + 1);
	if (new_str == NULL)
		return (NULL);
	while (len <= i)
	{
		new_str[j] = s[len];
		j++;
		len++;
	}
	return (new_str);
}
