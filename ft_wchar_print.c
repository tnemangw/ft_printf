/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_wchar_print.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tnemangw <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/31 17:09:35 by tnemangw          #+#    #+#             */
/*   Updated: 2018/09/03 15:48:56 by tnemangw         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static char	size_wchar(unsigned int wc)
{
	if (wc <= 127)
		return (1);
	else if (wc >= 128 && wc <= 2047)
		return (2);
	else if (wc >= 2048 && wc <= 65535)
		return (3);
	else if (wc >= 65536 && wc <= 2097151)
		return (4);
	else
		return (0);
}

char		ft_wchar_print(wchar_t wc)
{
	char			res;
	char			size;
	unsigned char	curr_byte;

	res = 0;
	size = size_wchar(wc);
	if (size == 1)
		return (ft_char_print(wc));
	curr_byte = (240 << (4 - size)) | (wc >> ((size - 1) * 6));
	res += ft_char_print(curr_byte);
	size--;
	while (size--)
	{
		curr_byte = ((wc >> ((size) * 6)) & 63) | 128;
		res += ft_char_print(curr_byte);
	}
	return (res);
}
