/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   return_functions.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jle-corr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/08 15:39:37 by jle-corr          #+#    #+#             */
/*   Updated: 2020/04/08 15:39:39 by jle-corr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char		*ptf_msg_error(int a)
{
	char *str;

	str = NULL;
	if (a == 1)
		str = "\033[1;31mft_ptf err:\033[0m incomplete format specifier";
	else if (a == 2)
		str = "\033[1;31mft_ptf err:\033[0m invalid conversion specifier";
	else if (a == 3)
		str = "\033[1;31mft_ptf err:\033[0m f'0' is ignored when f'-'";
	else if (a == 4)
		str = "\033[1;31mft_ptf err:\033[0m Wrong %p flag bitch !";
	else if (a == 5)
		str = "\033[1;31mft_ptf err:\033[0m Wrong %c flag bitch !";
	if (str)
		write(2, str, ft_strlen(str));
	return (NULL);
}

char		*free_return(char *str)
{
	free(str);
	return (NULL);
}
