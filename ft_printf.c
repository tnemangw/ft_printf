/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tnemangw <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/10 14:32:17 by tnemangw          #+#    #+#             */
/*   Updated: 2018/09/03 15:35:34 by tnemangw         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_printf(char *format, ...)
{
	int		length;
	va_list	va;

	length = 0;
	va_start(va, format);
	while (*format != '\0')
	{
		if (*format != '%')
			length += ft_char_print(*format);
		else
		{
			format++;
			length += ft_convertion_handling(&(format), va);
		}
		format++;
	}
	va_end(va);
	return (length);
}
