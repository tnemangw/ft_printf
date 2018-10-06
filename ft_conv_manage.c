/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_conv_manage.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tnemangw <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/15 15:43:48 by tnemangw          #+#    #+#             */
/*   Updated: 2018/09/03 17:26:05 by tnemangw         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int			ft_conv_manage(t_flist *last, va_list va)
{
	int		res;

	res = 0;
	if (last->spec == '%')
		res = (ft_percent_print(last, '%'));
	else if (last->spec == 'c' || last->spec == 'C')
		res = (ft_char_handling(last, va_arg(va, void *)));
	else if (last->spec == 's' || last->spec == 'S')
		res = (ft_string_handling(last, va_arg(va, void *)));
	else if (last->spec == 'd' || last->spec == 'i' || last->spec == 'D')
		res = (ft_digit_handling(last, va_arg(va, void *)));
	else if (last->spec == 'u' || last->spec == 'U')
		res = (ft_unsigned_digit_handling(last, va_arg(va, void *)));
	else if (last->spec == 'x' || last->spec == 'X')
		res = (ft_handling_hex(last, va_arg(va, void *)));
	else if (last->spec == 'o' || last->spec == 'O')
		res = (ft_oct_handling(last, va_arg(va, void *)));
	else if (last->spec == 'p')
		res = (ft_pointer_handling(last, va_arg(va, void *)));
	else
		res = (ft_char_handling(last, va_arg(va, void *)));
	ft_strdel(&(last->flags));
	return (res);
}
