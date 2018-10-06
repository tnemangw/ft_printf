/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pointer_handling.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tnemangw <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/14 16:12:20 by tnemangw          #+#    #+#             */
/*   Updated: 2018/09/03 16:05:45 by tnemangw         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static char		ft_size_ptr_digit(intmax_t digit)
{
	char	res;

	res = 1;
	digit /= 16;
	while (digit)
	{
		digit /= 16;
		res++;
	}
	return (res);
}

static char		ft_strlen_ptr(t_flist *last, intmax_t digit)
{
	char	res;
	char	tmp;

	res = ft_size_ptr_digit(digit);
	tmp = 0;
	if (last->precision != -1 && last->precision > res)
	{
		tmp = (last->precision - res);
		res = last->precision;
	}
	if (digit != 0)
		res += 2;
	if (tmp > 0)
		last->precision = tmp;
	else if (digit == 0 && last->precision == 0)
	{
		last->precision = -2;
		res = 2;
	}
	else
		last->precision = -1;
	return (res);
}

static char		ft_pointer_print(uintmax_t digit, t_flist *last, char *base)
{
	char	len;

	len = 0;
	if (digit == 0 && last->precision == -2)
		return (0);
	if (digit >= 16)
	{
		len += ft_pointer_print(digit / 16, last, base);
		len += ft_char_print(base[digit % 16]);
	}
	else
		len += ft_char_print(base[digit % 16]);
	return (len);
}

static short	ft_hend_ptr(t_flist *last, uintmax_t digit)
{
	short	len;

	len = 0;
	if ((last->flags)[2] == '0' && last->precision == -1)
		(last->flags)[0] = '0';
	last->size = ft_strlen_ptr(last, digit);
	if (last->flags[0] == '0')
		len += ft_string_print("0x", -1);
	while ((last->flags)[3] != '-' && last->width > (last->size))
		(len += ft_char_print((last->flags)[0])) && last->width--;
	if (last->flags[0] == ' ')
		len += ft_string_print("0x", -1);
	while (last->precision != -1 && last->precision > 0)
		(len += ft_char_print('0')) && last->precision--;
	len += ft_pointer_print(digit, last, "0123456789abcdef");
	while (last->width > last->size && (last->flags)[3] == '-')
		(len += ft_char_print(' ')) && last->width--;
	return (len);
}

int				ft_pointer_handling(t_flist *last, void *digit)
{
	return (ft_hend_ptr(last, (uintmax_t)digit));
}
