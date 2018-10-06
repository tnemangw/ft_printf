/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_unsigned_digit_handling.c                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tnemangw <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/17 17:01:56 by tnemangw          #+#    #+#             */
/*   Updated: 2018/09/03 15:52:34 by tnemangw         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static char	ft_size_uns_digit(uintmax_t digit)
{
	char	res;

	res = 1;
	digit /= 10;
	while (digit)
	{
		digit /= 10;
		res++;
	}
	return (res);
}

static char	ft_strlen_uns_digit(t_flist *last, intmax_t digit)
{
	char	res;
	char	tmp;

	tmp = 0;
	res = ft_size_uns_digit(digit);
	if (last->precision != -1 && last->precision > res)
	{
		tmp = (last->precision - res);
		res = last->precision;
	}
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

static char	ft_print_uns_digit(uintmax_t digit, t_flist *last)
{
	char	len;

	len = 0;
	if (digit == 0 && last->precision == -2)
		return (0);
	if (digit >= 10)
	{
		len += ft_print_uns_digit(digit / 10, last);
		len += ft_char_print((digit % 10) + '0');
	}
	else
		len += ft_char_print(digit + '0');
	return (len);
}

static char	ft_hend_uns_digit(t_flist *last, uintmax_t digit)
{
	short	len;

	len = 0;
	if ((last->flags)[2] == '0' && last->precision == -1)
		(last->flags)[0] = '0';
	last->size = ft_strlen_uns_digit(last, digit);
	while ((last->flags)[3] != '-' && last->width > (last->size))
		(len += ft_char_print((last->flags)[0])) && last->width--;
	while (last->precision != -1 && last->precision > 0)
		(len += ft_char_print('0')) && last->precision--;
	len += ft_print_uns_digit(digit, last);
	while (last->width > last->size && (last->flags)[3] == '-')
		(len += ft_char_print(' ')) && last->width--;
	return (len);
}

int			ft_unsigned_digit_handling(t_flist *last, void *digit)
{
	if (last->spec == 'U')
		return (ft_hend_uns_digit(last, (unsigned long)digit));
	else if (last->j)
		return (ft_hend_uns_digit(last, (uintmax_t)digit));
	else if (last->ll)
		return (ft_hend_uns_digit(last, (unsigned long long)digit));
	else if (last->z)
		return (ft_hend_uns_digit(last, (size_t)digit));
	else if (last->l)
		return (ft_hend_uns_digit(last, (unsigned long)digit));
	else if (last->h)
		return (ft_hend_uns_digit(last, (unsigned short)digit));
	else if (last->hh)
		return (ft_hend_uns_digit(last, (unsigned char)digit));
	else
		return (ft_hend_uns_digit(last, (unsigned int)digit));
}
