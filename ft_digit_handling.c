/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_digit_handling.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tnemangw <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/12 16:11:46 by tnemangw          #+#    #+#             */
/*   Updated: 2018/09/03 17:27:12 by tnemangw         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static char		ft_size_digit(intmax_t digit)
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

static char		ft_strlen_digit(t_flist *last, intmax_t digit)
{
	char	res;
	char	tmp;

	tmp = 0;
	res = ft_size_digit(digit);
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
	if ((digit < 0) || (((last->flags)[4] == '+' || (last->flags)[5] == ' ') &&
				digit >= 0))
		res++;
	return (res);
}

static char		ft_digit_print(intmax_t digit, t_flist *last)
{
	char	len;

	len = 0;
	if (digit == 0 && last->precision == -2)
		return (0);
	if (-10 < digit && digit < 10)
		len += ft_char_print(ABS(digit) + '0');
	else
	{
		len += ft_digit_print(digit / 10, last);
		len += ft_digit_print(digit % 10, last);
	}
	return (len);
}

static short	ft_hend_digit(t_flist *last, intmax_t digit, int *len)
{
	if ((last->flags)[2] == '0' && last->precision == -1)
		(last->flags)[0] = '0';
	last->size = ft_strlen_digit(last, digit);
	if (digit < 0 && last->flags[0] == '0')
		*len += ft_char_print('-');
	else if (digit >= 0 && last->flags[0] == '0' && last->flags[4] == '+')
		*len += ft_char_print('+');
	else if (last->flags[0] == '0' && last->flags[5] == ' ')
		*len += ft_char_print(' ');
	while ((last->flags)[3] != '-' && last->width > (last->size))
		(*len += ft_char_print((last->flags)[0])) && last->width--;
	if ((last->flags)[4] == '+' && digit >= 0 && last->flags[0] != '0')
		*len += ft_char_print('+');
	else if (digit < 0 && last->flags[0] == ' ' && last->flags[0] != '0')
		*len += ft_char_print('-');
	else if ((last->flags)[5] == ' ' && digit >= 0 && last->flags[0] != '0')
		*len += ft_char_print(' ');
	while (last->precision != -1 && last->precision > 0)
		(*len += ft_char_print('0')) && last->precision--;
	*len += ft_digit_print(digit, last);
	while (last->width > last->size && (last->flags)[3] == '-')
		(*len += ft_char_print(' ')) && last->width--;
	return (*len);
}

int				ft_digit_handling(t_flist *last, void *digit)
{
	int		len;

	len = 0;
	if (last->spec == 'D')
		(ft_hend_digit(last, (long)digit, &len));
	else if (last->j)
		(ft_hend_digit(last, (intmax_t)digit, &len));
	else if (last->ll)
		(ft_hend_digit(last, (long long)digit, &len));
	else if (last->z)
		(ft_hend_digit(last, (size_t)digit, &len));
	else if (last->l)
		(ft_hend_digit(last, (long)digit, &len));
	else if (last->h)
		(ft_hend_digit(last, (short)digit, &len));
	else if (last->hh)
		(ft_hend_digit(last, (char)digit, &len));
	else
		(ft_hend_digit(last, (int)digit, &len));
	return (len);
}
