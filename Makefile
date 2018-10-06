# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tnemangw <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/08/02 16:15:11 by tnemangw          #+#    #+#              #
#    Updated: 2018/09/03 16:21:17 by tnemangw         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

GCC = gcc

F = -Wall -Wextra -Werror

NAME = libftprintf.a

OBJECT = ./ft_printf.o \
	./ft_convertion_handling.o \
	./ft_char_print.o \
	./ft_strchr.o \
	./ft_strsub.o \
	./ft_strdup.o \
	./ft_atoi.o \
	./ft_string_print.o \
	./ft_wchar_print.o \
	./ft_wstr_print.o \
	./ft_conv_manage.o \
	./ft_strlen.o \
	./ft_memcpy.o \
	./ft_percent_print.o \
	./ft_char_handling.o \
	./ft_string_handling.o \
	./ft_digit_handling.o \
	./ft_unsigned_digit_handling.o \
	./ft_handling_hex.o \
	./ft_oct_handling.o \
	./ft_pointer_handling.o \
	./ft_strdel.o \

.PHONY: all clean fclean re

all: $(NAME)

$(NAME): $(OBJECT)
		ar rc $(NAME) $(OBJECT)
		ranlib $(NAME)

clean:
	rm -rf $(OBJECT)

fclean: clean
	rm -rf $(NAME)

re: fclean all

ft_printf.o: ft_printf.c
	$(GCC) $(F) -c  ft_printf.c

ft_char_print.o: ft_char_print.c
	$(GCC) $(F) -c  ft_char_print.c

ft_strchr.o: ft_strchr.c
	$(GCC) $(F) -c ft_strchr.c

ft_strsub.o: ft_strsub.c
	$(GCC) $(F) -c ft_strsub.c

ft_atoi.o: ft_atoi.c
	$(GCC) $(F) -c ft_atoi.c

ft_string_print.o: ft_string_print.c
	$(GCC) $(F) -c ft_string_print.c

ft_pointer_handling.o: ft_pointer_handling.c
	$(GCC) $(F) -c ft_pointer_handling.c

ft_wchar_print.o: ft_wchar_print.c
	$(GCC) $(F) -c ft_wchar_print.c

ft_wstr_print.o: ft_wstr_print.c
	$(GCC) $(F) -c ft_wstr_print.c

ft_conv_manage.o: ft_conv_manage.c
	$(GCC) $(F) -c ft_conv_manage.c

ft_convertion_handling.o: ft_convertion_handling.c
	$(GCC) $(F) -c ft_convertion_handling.c

ft_strdup.o: ft_strdup.c
	$(GCC) $(F) -c ft_strdup.c

ft_memcpy.o: ft_memcpy.c
	$(GCC) $(F) -c ft_memcpy.c

ft_strlen.o: ft_strlen.c
	$(GCC) $(F) -c ft_strlen.c

ft_atoi_f.o: ft_atoi.c
	$(GCC) $(F) -c ft_atoi.c

ft_percent_print.o: ft_percent_print.c
	$(GCC) $(F) -c ft_percent_print.c

ft_char_handling.o: ft_char_handling.c
	$(GCC) $(F) -c ft_char_handling.c

ft_string_handling.o: ft_string_handling.c
	$(GCC) $(F) -c ft_string_handling.c

ft_digit_handling.o: ft_digit_handling.c
	$(GCC) $(F) -c ft_digit_handling.c

ft_unsigned_digit_handling.o: ft_unsigned_digit_handling.c
	$(GCC) $(F) -c ft_unsigned_digit_handling.c

ft_handling_hex.o: ft_handling_hex.c
	$(GCC) $(F) -c ft_handling_hex.c

ft_oct_handling.o: ft_oct_handling.c
	$(GCC) $(F) -c ft_oct_handling.c

ft_strdel.o: ft_strdel.c
	$(GCC) $(F) -c ft_strdel.c
