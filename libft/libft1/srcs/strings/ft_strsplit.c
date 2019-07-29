/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmaron-g <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/29 19:12:17 by lmaron-g          #+#    #+#             */
/*   Updated: 2018/11/29 19:12:21 by lmaron-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char			**ft_wordsnew(size_t size)
{
	char		**area;

	if (size == SIZE_T_MAX)
		size--;
	if (!(area = (char**)malloc(sizeof(char*) * (size + 1))))
		return (0);
	ft_memset(area, (int)'\0', (size + 1) * sizeof(char*));
	return (area);
}

void			free_words(char ***words)
{
	int			i;

	i = 0;
	if (!(words && *words))
		return ;
	while ((*words)[i])
	{
		ft_strdel(&(*words)[i]);
		(*words)[i++] = 0;
	}
	free(*words);
	(*words) = 0;
}

size_t			count_words(char const *str, char c)
{
	int			i;
	size_t		cw;

	i = 0;
	cw = 0;
	if (str[0] == '\0')
		return (cw);
	if (str[0] != c)
	{
		cw++;
		i++;
	}
	i--;
	while (str[++i + 1] != '\0')
		if (str[i] == c && str[i + 1] != c)
			cw++;
	return (cw);
}

static char		*ft_subword(char const *s, int start, char c)
{
	int			i;
	size_t		len;
	char		*fresh;

	i = 0;
	len = 0;
	if (!s || (start > (int)ft_strlen(s)))
		return (0);
	while (s[start + len] != '\0' && s[start + len] != c)
		len++;
	if (!(fresh = ft_strnew(len)))
		return (0);
	while (s[start] != '\0' && s[start] != c)
		fresh[i++] = (char)s[start++];
	fresh[i] = '\0';
	return (fresh);
}

char			**ft_strsplit(char const *s, char c)
{
	int			i;
	int			j;
	char		**words;

	i = 0;
	j = 0;
	if (!s || !(words = ft_wordsnew(count_words(s, c))))
		return (0);
	if (s[i] != c && count_words(s, c))
		if (!(words[j++] = ft_subword(s, i++, c)))
		{
			free_words(&words);
			return (0);
		}
	i--;
	while (s[++i + 1] && count_words(s, c))
		if (s[i] == c && s[i + 1] != c)
			if (!(words[j++] = ft_subword(s, i + 1, c)))
			{
				free_words(&words);
				return (0);
			}
	return (words);
}
