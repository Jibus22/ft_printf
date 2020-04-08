/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jle-corr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/08 18:04:52 by jle-corr          #+#    #+#             */
/*   Updated: 2019/12/19 06:19:27 by jle-corr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int		tabcreator(char const *s, char c)
{
	int		i;
	int		tabnb;

	i = -1;
	tabnb = 0;
	while (s[++i])
		if (s[i] != c && tabnb++)
			while (s[i + 1] && s[i + 1] != c)
				i++;
	return (tabnb + 1);
}

static int		slenc(char const *s, char c)
{
	int	i;

	i = 0;
	while (s[i] && s[i] != c)
		i++;
	return (i);
}

static void		*freestr(char **strs, int tab)
{
	int		i;

	i = 0;
	while (strs[i] != NULL && i < tab)
		free(strs[i++]);
	free(strs);
	return (NULL);
}

char			**ft_split(char const *s, char c)
{
	char	**strs;
	int		tab;
	int		start;

	if (!s)
		return (NULL);
	if (!(strs = (char**)malloc(sizeof(char*) * tabcreator(s, c))))
		return (NULL);
	start = -1;
	tab = 0;
	while (s[++start])
	{
		if (s[start] && s[start] != c)
		{
			if (!(strs[tab++] = ft_substr(s, start, slenc((s + start), c))))
				return (freestr(strs, tab));
			start += slenc((s + start), c) - 1;
		}
	}
	strs[tab] = NULL;
	return (strs);
}
