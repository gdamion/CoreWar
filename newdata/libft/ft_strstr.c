/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmann <tmann@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/08 15:59:16 by tmann             #+#    #+#             */
/*   Updated: 2019/07/22 19:29:15 by tmann            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strstr(const char *haystack, const char *needle)
{
	char	*hs_ptr;
	char	*ndl_ptr;
	int		i;

	hs_ptr = (char*)haystack;
	ndl_ptr = (char*)needle;
	while (*hs_ptr)
	{
		i = 0;
		while (*hs_ptr && *ndl_ptr && (*hs_ptr == *ndl_ptr))
		{
			hs_ptr++;
			ndl_ptr++;
			i++;
		}
		if (!*ndl_ptr)
			return (hs_ptr - ft_strlen(needle));
		else
		{
			hs_ptr -= i;
			ndl_ptr = (char*)needle;
		}
		hs_ptr++;
	}
	return (needle[0] == '\0' ? hs_ptr : NULL);
}
