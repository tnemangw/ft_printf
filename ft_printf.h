/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tnemangw <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/26 16:32:46 by tnemangw          #+#    #+#             */
/*   Updated: 2018/09/04 15:12:24 by tnemangw         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include <stdarg.h>
# include <unistd.h>
# include <stdlib.h>
# include <wchar.h>

# define ABS(x) ((x < 0) ? -(x) : (x))

typedef struct		s_flist
{
	char			*flags;
	short			width;
	short			precision;
	char			hh;
	char			h;
	char			l;
	char			z;
	char			ll;
	char			j;
	char			spec;
	short			size;

}					t_flist;

int					ft_char_handling(t_flist *lst, void *c);
int					ft_string_handling(t_flist *lst, void *str);
int					ft_digit_handling(t_flist *lst, void *digit);
int					ft_unsigned_digit_handling(t_flist *lst, void *digit);
int					ft_handling_hex(t_flist *lst, void *digit);
int					ft_oct_handling(t_flist *lst, void *digit);
int					ft_pointer_handling(t_flist *lst, void *digit);
int					ft_char_print(int c);
int					ft_string_print(char *str, int precision);
char				ft_wchar_print(wchar_t wc);
int					ft_wstr_print(wchar_t *wstr, int precision);
int					ft_conv_manage(t_flist *list, va_list va);
int					ft_convertion_handling(char **format, va_list va);
char				ft_strchr(char *s, int c);
char				*ft_strsub(char const *s, unsigned int start, size_t len);
char				*ft_strdup(const char *src);
int					ft_atoi(char **str);
void				*ft_memcpy(void *dst, const void *src, size_t n);
int					ft_strlen(const char *s);
int					ft_percent_print(t_flist *lst, char c);
void				ft_strdel(char **as);
int					ft_printf(char *format, ...);

#endif
