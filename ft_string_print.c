/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_string_print.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tnemangw <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/03 15:43:12 by tnemangw          #+#    #+#             */
/*   Updated: 2018/09/03 15:44:02 by tnemangw         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_string_print(char *str, int precision)
{
	int	len;

	len = 0;
	if (str == NULL)
		return (ft_string_print("(null)", precision));
	while (*str != '\0' && precision--)
	{
		len += ft_char_print(*str);
		str++;
	}
	return (len);
}
