/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jle-corr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/08 15:39:02 by jle-corr          #+#    #+#             */
/*   Updated: 2020/04/09 19:33:29 by jle-corr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int			ft_printf(const char *format, ...)
{
	char	*fmtcpy;
	char	*fmtres;
	t_ptf	data;
	va_list	va;

	va_start(va, format);
	if (!(fmtcpy = ft_strdup(format)))
		return (0);
	data.i = 0;
	data.nulchar = "N";
	if (!(fmtres = (fmt_process(fmtcpy, &data, &va))))
	{
		va_end(va);
		return ((int)free_return(fmtcpy));
	}
	va_end(va);
	free(fmtcpy);
	write(1, fmtres, data.i);
	free(fmtres);
	return (data.i);
}
