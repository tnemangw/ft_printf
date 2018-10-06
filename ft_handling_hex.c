/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_handling_hex.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tnemangw <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/09 16:37:24 by tnemangw          #+#    #+#             */
/*   Updated: 2018/09/03 17:33:33 by tnemangw         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static char		ft_size_hex_digit(intmax_t digit)
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

static char		ft_strlen_hex_digit(t_flist *last, intmax_t digit)
{
	char	res;
	char	tmp;

	tmp = 0;
	res = ft_size_hex_digit(digit);
	if (last->precision != -1 && last->precision > res)
	{
		tmp = (last->precision - res);
		res = last->precision;
	}
	if (last->flags[1] == '#' && digit != 0)
		res += 2;
	if (tmp > 0)
		last->precision = tmp;
	else if (digit == 0 && last->precision == 0)
	{
		last->precision = -2;
		res = 0;
	}
	else
		last->precision = -1;
	return (res);
}

static char		ft_print_hex(uintmax_t digit, t_flist *last, char *base)
{
	char	len;

	len = 0;
	if (digit == 0 && last->precision == -2)
		return (0);
	if (digit >= 16)
	{
		len += ft_print_hex(digit / 16, last, base);
		len += ft_char_print(base[digit % 16]);
	}
	else
		len += ft_char_print(base[digit % 16]);
	return (len);
}

static short	ft_hand_hex_digit(t_flist *last, uintmax_t digit)
{
	short	len;

	len = 0;
	if ((last->flags)[2] == '0' && last->precision == -1)
		(last->flags)[0] = '0';
	last->size = ft_strlen_hex_digit(last, digit);
	if (last->flags[0] == '0' && last->flags[1] == '#' && digit != 0)
		len += (last->spec == 'X') ? (ft_string_print("0X", -1)) :
			(ft_string_print("0x", -1));
	while ((last->flags)[3] != '-' && last->width > (last->size))
		(len += ft_char_print((last->flags)[0])) && last->width--;
	if ((last->flags[0] == ' ' && last->flags[1] == '#' && digit != 0))
		len += (last->spec == 'X') ? (ft_string_print("0X", -1)) :
			(ft_string_print("0x", -1));
	while (last->precision != -1 && last->precision > 0)
		(len += ft_char_print('0')) && last->precision--;
	len += (last->spec == 'X') ? ft_print_hex(digit, last, "0123456789ABCDEF") :
		ft_print_hex(digit, last, "0123456789abcdef");
	while (last->width > last->size && (last->flags)[3] == '-')
		(len += ft_char_print(' ')) && last->width--;
	return (len);
}

int				ft_handling_hex(t_flist *last, void *digit)
{
	if (last->j)
		return (ft_hand_hex_digit(last, (uintmax_t)digit));
	else if (last->ll)
		return (ft_hand_hex_digit(last, (unsigned long long)digit));
	else if (last->z)
		return (ft_hand_hex_digit(last, (size_t)digit));
	else if (last->l)
		return (ft_hand_hex_digit(last, (unsigned long)digit));
	else if (last->h)
		return (ft_hand_hex_digit(last, (unsigned short)digit));
	else if (last->hh)
		return (ft_hand_hex_digit(last, (unsigned char)digit));
	else
		return (ft_hand_hex_digit(last, (unsigned int)digit));
}
