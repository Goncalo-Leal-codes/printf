# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: gleal <gleal@student.42lisboa.com>         +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/02/09 15:43:58 by gleal             #+#    #+#              #
#    Updated: 2021/02/26 17:47:50 by gleal            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = gcc
FLAGS = -Wall -Wextra -Werror
NAME = libftprintf.a
SRCS = ft_conversions.c ft_conversions2.c ft_print_convs.c ft_print_tools.c ft_printf.c \
	   ft_utils_printf.c ft_utils_printf2.c ft_utils_printf3.c ft_utils_printf4.c get_info.c
OBJS = $(SRCS:.c=.o)

all: $(NAME)

%.o : %.c
	$(CC) $(FLAGS) -c $< -o $@

$(NAME) : $(OBJS)
	ar -rc $(NAME) $(OBJS)

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all



.PHONY: all clean fclean re
