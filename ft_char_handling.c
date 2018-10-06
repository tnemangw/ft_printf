/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_char_handling.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tnemangw <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/11 11:11:25 by tnemangw          #+#    #+#             */
/*   Updated: 2018/09/03 17:25:21 by tnemangw         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_char_handling(t_flist *last, void *c)
{
	int		len;

	len = 0;
	if ((last->flags)[2] == '0')
		(last->flags)[0] = '0';
	if ((last->flags)[3] != '-' && last->width > 1)
		while (((last->width)-- - 1))
			len += ft_char_print((last->flags)[0]);
	if (last->spec == 'c' && !last->l)
		len += ft_char_print((int)c);
	else if (last->spec == 'C' || (last->spec == 'c' && last->l))
		len += ft_char_print((int)c);
	else
		len += ft_char_print(last->spec);
	if (last->width > 1 && (last->flags)[3] == '-')
		while ((last->width)-- - 1)
			len += ft_char_print(' ');
	return (len);
}
