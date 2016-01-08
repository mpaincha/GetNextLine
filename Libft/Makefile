# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mpaincha <mpaincha@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2015/11/25 12:19:31 by fsimmet           #+#    #+#              #
#    Updated: 2016/01/07 10:58:46 by mpaincha         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a
SRC = ft_bzero.c \
ft_atoi.c \
ft_count_words.c \
ft_isalnum.c \
ft_itoa.c \
ft_intlen.c \
ft_isascii.c \
ft_isdigit.c \
ft_isalpha.c \
ft_islower.c \
ft_isupper.c \
ft_isprint.c \
ft_tolower.c \
ft_toupper.c \
ft_strequ.c \
ft_strmap.c \
ft_strmapi.c \
ft_strsplit.c \
ft_strtrim.c \
ft_strnequ.c \
ft_strcmp.c \
ft_strrev.c \
ft_striter.c \
ft_striteri.c \
ft_strlcat.c \
ft_strjoin.c \
ft_strdel.c \
ft_strstr.c \
ft_strnstr.c \
ft_strnew.c \
ft_strclr.c \
ft_strncmp.c \
ft_strsub.c \
ft_memset.c \
ft_memchr.c \
ft_memcpy.c \
ft_memcmp.c \
ft_memccpy.c \
ft_memdel.c \
ft_memmove.c \
ft_memalloc.c \
ft_putchar.c \
ft_putchar_fd.c \
ft_putendl.c \
ft_putendl_fd.c \
ft_putnbr.c \
ft_putnbr_fd.c \
ft_putstr.c \
ft_putstr_fd.c \
ft_strcpy.c \
ft_strncpy.c \
ft_strdup.c \
ft_strchr.c \
ft_strrchr.c \
ft_strcat.c \
ft_strncat.c \
ft_strlen.c \
ft_lstnew.c \
ft_lstdelone.c \
ft_lstdel.c \
ft_lstiter.c \
ft_lstmap.c \
ft_lstadd.c \
ft_lstdbladd.c \
ft_lstdbldel.c \
ft_lstdblnew.c
SRCO = $(SRC:.c=.o)
HEADERS = includes
CC = gcc
CFLAGS = -Wall -Wextra -Werror

all: $(NAME)

re: fclean all

%.o: %.c
	$(CC) -o $@ -c $< $(CFLAGS) -I $(HEADERS)

$(NAME): $(SRCO)
	ar rc $@ $^
	ranlib $@

clean:
	rm -f $(SRCO)

fclean: clean
	rm -f $(NAME)

.PHONY: re clean fclean all
