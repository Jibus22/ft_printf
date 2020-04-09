/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ptfstr.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jle-corr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/08 15:39:30 by jle-corr          #+#    #+#             */
/*   Updated: 2020/04/09 18:56:01 by jle-corr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int			cleant_ptf(t_ptf *data)
{
	data->fpad = ' ';
	data->fsign = 0;
	data->fprec = 0;
	data->ftype = 0;
	data->fwildcardp = 0;
	data->fwildcardw = 0;
	data->width = 0;
	data->prec = 0;
	return (1);
}

t_wformat	whatformat(char c)
{
	if (c == 's')
		return (sdata_process);
	else if (c == 'd' || c == 'i')
		return (ddata_process);
	else if (c == 'x' || c == 'X' || c == 'u')
		return (uxdata_process);
	else if (c == 'p')
		return (pdata_process);
	else if (c == 'c' || c == '%')
		return (cdata_process);
	return (NULL);
}

int			join_newfmtstr(char **str, char *src, t_ptf *data)
{
	char	*tmp;
	int		len;
	int		i;

	len = data->i + ft_strlen(src);
	if (!(tmp = ft_strnew(len)))
		return (0);
	i = -1;
	while (++i < data->i)
		tmp[i] = (*str)[i];
	if (*(data->nulchar) == '0')
	{
		*(ft_strchr(src, '0')) = 0;
		data->nulchar = "N";
	}
	while (i < len)
		tmp[i++] = *src++;
	free(*str);
	*str = tmp;
	data->i = len;
	return (1);
}

/*
** extract_data parse after % and return the ending adress
** whatformat dataprocess uses data, args and return a string
*/

char		*fmt_process(char *fmt, t_ptf *data, va_list *va)
{
	char	*adr;
	char	*fmtres;

	if (!(fmtres = ft_strnew(0)))
		return (NULL);
	while ((adr = ft_strchr(fmt, '%')))
	{
		*adr = 0;
		if (!(cleant_ptf(data)) || !(join_newfmtstr(&fmtres, fmt, data)))
			return (free_return(fmtres));
		if (!(fmt = (extract_data((adr + 1), data, va))))
			return (free_return(fmtres));
		if (!(adr = whatformat(data->ftype)(data, va)))
			return (free_return(fmtres));
		if (!(join_newfmtstr(&fmtres, adr, data)))
			return (free_return(fmtres));
		ft_strdel(&adr);
	}
	if (!(join_newfmtstr(&fmtres, fmt, data)))
		return (free_return(fmtres));
	return (fmtres);
}
