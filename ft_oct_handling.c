/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_oct_handling.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tnemangw <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/31 15:51:31 by tnemangw          #+#    #+#             */
/*   Updated: 2018/09/03 17:23:32 by tnemangw         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static char		ft_size_oct_digit(intmax_t digit)
{
	char	res;

	res = 1;
	digit /= 8;
	while (digit)
	{
		digit /= 8;
		res++;
	}
	return (res);
}

static char		ft_strlen_oct_digit(t_flist *last, intmax_t digit)
{
	char	res;
	char	tmp;

	tmp = 0;
	res = ft_size_oct_digit(digit);
	if (last->precision != -1 && last->precision > res)
	{
		tmp = (last->precision - res);
		res = last->precision;
	}
	if (last->flags[1] == '#' && digit != 0)
		res += 1;
	if (tmp > 0)
		last->precision = tmp;
	else if (digit == 0 && last->precision == 0 && last->flags[1] != '#')
	{
		last->precision = -2;
		res = 0;
	}
	else
		last->precision = -1;
	return (res);
}

static char		ft_print_oct_digit(uintmax_t digit, t_flist *last, char *base)
{
	char	len;

	len = 0;
	if (digit == 0 && last->precision == -2)
		return (0);
	if (digit >= 8)
	{
		len += ft_print_oct_digit(digit / 8, last, base);
		len += ft_char_print(base[digit % 8]);
	}
	else
		len += ft_char_print(base[digit % 8]);
	return (len);
}

static short	ft_hend_oct_digit(t_flist *last, uintmax_t digit)
{
	short	len;

	len = 0;
	if ((last->flags)[2] == '0' && last->precision == -1)
		(last->flags)[0] = '0';
	last->size = ft_strlen_oct_digit(last, digit);
	if (last->flags[0] == '0' && last->flags[1] == '#' && digit != 0)
		len += ft_char_print('0');
	while ((last->flags)[3] != '-' && last->width > (last->size))
		if (last->flags[0] == ' ' && last->flags[1] == '#' && digit != 0)
			len += ft_char_print('0');
	while (last->precision != -1 && last->precision > 0)
		(len += ft_char_print('0')) && last->precision--;
	len += ft_print_oct_digit(digit, last, "01234567");
	while (last->width > last->size && (last->flags)[3] == '-')
		(len += ft_char_print(' ')) && last->width--;
	return (len);
}

int				ft_oct_handling(t_flist *last, void *digit)
{
	if (last->spec == 'O')
		return (ft_hend_oct_digit(last, (unsigned long)digit));
	else if (last->j)
		return (ft_hend_oct_digit(last, (uintmax_t)digit));
	else if (last->ll)
		return (ft_hend_oct_digit(last, (unsigned long long)digit));
	else if (last->z)
		return (ft_hend_oct_digit(last, (size_t)digit));
	else if (last->l)
		return (ft_hend_oct_digit(last, (unsigned long)digit));
	else if (last->h)
		return (ft_hend_oct_digit(last, (unsigned short)digit));
	else if (last->hh)
		return (ft_hend_oct_digit(last, (unsigned char)digit));
	else
		return (ft_hend_oct_digit(last, (unsigned int)digit));
}
