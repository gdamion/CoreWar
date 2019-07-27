/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmann <tmann@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/08 15:59:16 by tmann             #+#    #+#             */
/*   Updated: 2019/07/08 16:07:45 by tmann            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t	hs_pos;
	size_t	nd_pos;
	size_t	find_pos;

	nd_pos = 0;
	hs_pos = 0;
	while (haystack[hs_pos] && hs_pos < len)
	{
		find_pos = hs_pos;
		while (haystack[find_pos] == needle[nd_pos] && find_pos < len)
		{
			nd_pos++;
			find_pos++;
			if (needle[nd_pos] == '\0')
				return ((char*)(haystack + hs_pos));
		}
		find_pos = 0;
		nd_pos = 0;
		hs_pos++;
	}
	if (needle[nd_pos] == '\0')
		return ((char*)haystack);
	return (NULL);
}
