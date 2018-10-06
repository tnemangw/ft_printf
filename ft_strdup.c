/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tnemangw <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/31 17:45:40 by tnemangw          #+#    #+#             */
/*   Updated: 2018/08/31 17:46:47 by tnemangw         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char		*ft_strdup(const char *src)
{
	size_t	n;
	char	*dst;

	n = ft_strlen(src);
	dst = (char*)malloc(sizeof(const char) * (n + 1));
	if (dst)
		ft_memcpy(dst, src, n + 1);
	return (dst);
}
