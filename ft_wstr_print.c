/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_wstr_print.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tnemangw <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/26 16:30:57 by tnemangw          #+#    #+#             */
/*   Updated: 2018/09/03 16:02:47 by tnemangw         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_wstr_print(wchar_t *wstr, int precision)
{
	int	res;

	res = 0;
	if (wstr == NULL)
		return (ft_string_print("(null)", precision));
	while (*wstr != '\0')
	{
		res += ft_wchar_print(*wstr);
		wstr++;
	}
	return (res);
}
