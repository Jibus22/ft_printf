/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   extract_data.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jle-corr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/08 15:38:54 by jle-corr          #+#    #+#             */
/*   Updated: 2020/04/08 19:08:11 by jle-corr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char		*srchset(char *c, const char *search,
		const char *set, const char *bypass)
{
	while (*search && !(ft_strchr(set, *search)))
		if (!(ft_strchr(bypass, *search++)))
			return (NULL);
	*c = *search;
	return ((!(*search) ? NULL : (char*)search));
}

int			data_check(t_ptf *data, va_list *va)
{
	if ((data->fwildcardw) && (data->width))
		return ((int)ptf_msg_error(2));
	if ((data->fwildcardp) && (data->prec))
		return ((int)ptf_msg_error(2));
	if ((data->fwildcardw))
		if ((data->width = (int)va_arg(*va, int)) < 0)
		{
			data->fpad = '-';
			data->width *= -1;
		}
	if ((data->fwildcardp))
		if ((data->prec = (int)va_arg(*va, int)) < 0)
			data->fprec = 0;
	return (1);
}

char		*extract_data(const char *search, t_ptf *data, va_list *va)
{
	char	*adr1;
	char	*adr2;
	char	c;

	if (!*search)
		return (ptf_msg_error(1));
	if (!(adr1 = srchset(&(data->ftype), search, STRTYPES, "-0+ #.*"DIGITS"")))
		return (ptf_msg_error(2));
	if ((adr2 = srchset(&(data->fprec), search, ".", "-0 +#*"DIGITS""))
			&& (adr1 = adr2))
		if (!(data->prec = ft_atoi((adr2 + 1))) && *(adr2 + 1) != data->ftype)
			data->fwildcardp = (*(adr2 + 1) == '*' ? '*' : 0);
	if ((adr2 = srchset(&c, search, "123456789*", "+-0 #")) && adr2 < adr1)
		if (!(data->width = ft_atoi(adr2)))
			data->fwildcardw = (*(adr1 - 1) == '*' ? '*' : 0);
	adr1 = (char*)search;
	while ((adr2 = srchset(&(data->fpad), adr1++, "-0", "+ #")))
		if ((srchset(&c, adr1, "-0", "+ #")) && c != data->fpad)
			return (ptf_msg_error(3));
	while ((adr2 = srchset(&(data->fsign), search, "+ #", "-0")))
		if ((srchset(&c, search++, "+ #", "-0")) && c != data->fsign)
			return (ptf_msg_error(3));
	if (!(data_check(data, va)))
		return (NULL);
	return (ft_strchr(search, data->ftype) + 1);
}
