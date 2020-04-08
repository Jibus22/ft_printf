/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jle-corr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/08 15:39:48 by jle-corr          #+#    #+#             */
/*   Updated: 2020/04/08 19:31:47 by jle-corr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <stdlib.h>
# include <unistd.h>
# include "libft.h"

# define STRTYPES	"csdiuxXp%"
# define DIGITS	"1234567890"

typedef	struct	s_ptfdata
{
	char		fpad;
	char		fsign;
	char		fprec;
	char		ftype;
	char		fwildcardp;
	char		fwildcardw;
	int			width;
	int			prec;
	int			i;
	char		*nulchar;
}				t_ptf;

typedef char	*(*t_wformat)(t_ptf *, va_list *);

int				ft_printf(const char *format, ...);
char			*fmt_process(char *fmt, t_ptf *data, va_list *va);
char			*extract_data(const char *search, t_ptf *data, va_list *va);
char			*sdata_process(t_ptf *data, va_list *va);
char			*ddata_process(t_ptf *data, va_list *va);
char			*uxdata_process(t_ptf *data, va_list *va);
char			*pdata_process(t_ptf *data, va_list *va);
char			*cdata_process(t_ptf *data, va_list *va);
char			*add_pad(char *str, t_ptf *data, char c);
char			*add_sign(char *res, t_ptf *data);
int				insert_sign(char *res, char c);
char			*free_return(char *str);
char			*ptf_msg_error(int a);

#endif
