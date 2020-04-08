/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   data_process_nbr.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jle-corr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/08 15:38:42 by jle-corr          #+#    #+#             */
/*   Updated: 2020/04/08 19:08:57 by jle-corr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int			freeandnew(char **res, int c)
{
	free(*res);
	if (!(*res = ft_strnew(c)))
		return (0);
	return (1);
}

char		*pdata_process(t_ptf *data, va_list *va)
{
	char			*res;
	unsigned long	d;

	d = (unsigned long)va_arg(*va, void*);
	if (!(res = ft_ultox(d)))
		return (NULL);
	if ((data->fsign) || data->fpad == '0' || (data->prec))
		return (ptf_msg_error(4));
	if ((data->fprec) && data->prec == 0 && d == 0)
		if (!(freeandnew(&res, 0)))
			return (NULL);
	data->fsign = '#';
	if (!(res = add_sign(res, data)))
		return (NULL);
	if ((data->width) > (int)ft_strlen(res))
		if (!(res = add_pad(res, data, 'w')))
			return (NULL);
	return (res);
}

char		*uxdata_process(t_ptf *data, va_list *va)
{
	char			*res;
	unsigned int	u;

	u = (unsigned int)va_arg(*va, unsigned int);
	if (data->ftype != 'u')
		if (!(res = (data->ftype == 'x' ? ft_utox(u) : ft_utobx(u))))
			return (NULL);
	if (data->ftype == 'u')
		if (!(res = ft_utoa(u)))
			return (NULL);
	data->fpad = ((((data->fpad) == '0' && (data->fprec)) ? ' ' : data->fpad));
	if ((data->fprec) && (data->prec > (int)ft_strlen(res)))
		if (!(res = add_pad(res, data, 'p')))
			return (NULL);
	if ((data->fprec) && data->prec == 0 && u == 0)
		if (!(freeandnew(&res, 0)))
			return (NULL);
	if ((data->fsign))
		if (!(res = add_sign(res, data)))
			return (NULL);
	if ((data->width) > (int)ft_strlen(res))
		if (!(res = add_pad(res, data, 'w')))
			return (NULL);
	return (res);
}

char		*ddata_process(t_ptf *data, va_list *va)
{
	char			*res;
	int				d;

	if ((d = (int)va_arg(*va, int)) < 0)
		data->fsign = '-';
	if (!(res = ft_itoa(d)))
		return (NULL);
	data->fpad = ((((data->fpad) == '0' && (data->fprec)) ? ' ' : data->fpad));
	if ((data->fprec) && (data->prec > (int)ft_strlen(res)))
		if (!(res = add_pad(res, data, 'p')))
			return (NULL);
	if ((data->fsign) == '-' && (data->prec == (int)ft_strlen(res)))
		insert_sign(res, '0');
	if ((data->fprec) && data->prec == 0 && d == 0)
		if (!(freeandnew(&res, 0)))
			return (NULL);
	if ((data->fsign))
		if (!(res = add_sign(res, data)))
			return (NULL);
	if ((data->width) > (int)ft_strlen(res))
		if (!(res = add_pad(res, data, 'w')))
			return (NULL);
	if (*res == '0' && (data->fsign))
		insert_sign(res, data->fsign);
	return (res);
}
