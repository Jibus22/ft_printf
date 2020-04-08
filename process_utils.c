/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   process_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jle-corr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/08 15:39:23 by jle-corr          #+#    #+#             */
/*   Updated: 2020/04/08 19:23:57 by jle-corr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char		*add_pad(char *s, t_ptf *d, char c)
{
	char	*pad;
	char	*res;
	int		l;

	l = (c == 'w' ? d->width : d->prec) - (d->ftype == 'c' ? 1 : ft_strlen(s));
	if (!(pad = ft_strnew(l)))
		return (NULL);
	if (c == 'w')
		ft_memset(pad, (d->fpad == '0' ? '0' : ' '), l);
	else
		ft_memset(pad, '0', l);
	if (d->fpad == '-' && c == 'w')
	{
		if (!(res = ft_strjoin(s, pad)))
			return (NULL);
	}
	else
	{
		if (!(res = ft_strjoin(pad, s)))
			return (NULL);
	}
	free(pad);
	free(s);
	return (res);
}

char		*add_sign(char *s, t_ptf *d)
{
	char	*signe;
	char	*adr;

	if (d->fsign == '-' && *s == '0' && (adr = ft_strchr(s, '-')))
		*adr = '0';
	if ((d->fsign == '+' || d->fsign == ' ' || (d->fsign == '-' && *s == '0')))
	{
		if (!(signe = ft_strnew(ft_strlen(s) + 1)))
			return (NULL);
		*signe = d->fsign;
		ft_memcpy(signe + 1, s, ft_strlen(s));
		free(s);
	}
	else if (d->fsign == '#')
	{
		if (!(signe = ft_strnew(ft_strlen(s) + 2)))
			return (NULL);
		*signe = '0';
		*(signe + 1) = 'x';
		ft_memcpy(signe + 2, s, ft_strlen(s));
		free(s);
	}
	else
		signe = s;
	return (signe);
}

int			insert_sign(char *res, char c)
{
	char *adr;

	if ((adr = ft_strchr(res, '-')))
		*adr = '0';
	*res = c;
	return (1);
}
