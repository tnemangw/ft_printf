/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_string_handling.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tnemangw <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/26 16:12:55 by tnemangw          #+#    #+#             */
/*   Updated: 2018/09/03 15:46:18 by tnemangw         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_string_handling(t_flist *last, void *str)
{
	int	len;

	last->size = (str != NULL) ? ft_strlen((char *)str) : 6;
	len = 0;
	last->size = !last->precision ? last->width : last->size;
	if ((last->flags)[2] == '0')
		(last->flags)[0] = '0';
	while ((last->flags)[3] != '-' && last->width > last->size)
		(len += ft_char_print((last->flags)[0])) && (last->width)--;
	while ((last->flags)[3] != '-' && last->width > last->precision &&
			last->precision != -1 && (last->size > last->precision))
		len += ft_char_print((last->flags)[0]) && last->width--;
	if (last->spec == 's' && !last->l)
		len += ft_string_print((char *)str, last->precision);
	else if (last->spec == 'S' || (last->spec == 's' && last->l))
		len += ft_wstr_print((wchar_t *)str, last->precision);
	while ((last->flags)[3] == '-' && last->width > last->size)
		len += ft_char_print(' ') && last->width--;
	while ((last->flags)[3] == '-' && last->width > last->precision &&
			last->precision != -1 && (last->size-- - last->precision))
		len += ft_char_print(' ');
	return (len);
}
