/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   data_process_char.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jle-corr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/08 15:38:30 by jle-corr          #+#    #+#             */
/*   Updated: 2020/04/08 19:08:28 by jle-corr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char		*cdata_process(t_ptf *data, va_list *va)
{
	char	*res;
	char	c;

	if ((c = (data->ftype == '%' ? '%' : (unsigned char)va_arg(*va, int))) == 0)
		data->nulchar = "0";
	if (data->ftype == 'c' && ((data->fsign) ||
				data->fpad == '0' || (data->prec)))
		return (ptf_msg_error(4));
	if (!(res = ft_strnew(1)))
		return (NULL);
	*res = (*(data->nulchar) == '0' ? '0' : c);
	if ((data->width) > 1)
		if (!(res = add_pad(res, data, 'w')))
			return (NULL);
	return (res);
}

char		*sdata_process(t_ptf *data, va_list *va)
{
	char	*res;
	char	*tmp;

	if (!(res = (char*)va_arg(*va, char *)))
		res = "(null)";
	if (!(res = ft_strdup(res)))
		return (NULL);
	if ((data->fprec) && (data->prec) < (int)ft_strlen(res))
	{
		if (!(tmp = ft_substr(res, 0, data->prec)))
			return (NULL);
		free(res);
		res = tmp;
	}
	if ((data->width) > (int)ft_strlen(res))
		if (!(res = add_pad(res, data, 'w')))
			return (NULL);
	return (res);
}
