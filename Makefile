# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: cjang <cjang@student.42seoul.kr>           +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/12/24 17:30:16 by cjang             #+#    #+#              #
#    Updated: 2021/03/15 15:13:13 by cjang            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = gcc
CFLAGS = -Wall -Wextra -Werror
NAME = libftprintf.a
SRCS =			ft_printf.c			printf_branch.c		printf_c.c			printf_d.c			\
				printf_n.c			printf_olo.c		printf_p.c			printf_s.c			\
				printf_u.c			printf_utils_1.c	printf_utils_2.c	printf_x.c			\
				printf_f.c			printf_utils_f_1.c	printf_utils_f_2.c	printf_utils_g_1.c	\
				printf_utils_g_2.c	printf_utils_e.c	printf_o.c

SRCS_BONUS =	ft_printf_bonus.c			printf_branch_bonus.c		printf_c_bonus.c			printf_d_bonus.c			\
				printf_n_bonus.c			printf_olo_bonus.c			printf_p_bonus.c			printf_s_bonus.c			\
				printf_u_bonus.c			printf_utils_1_bonus.c		printf_utils_2_bonus.c		printf_x_bonus.c			\
				printf_f_bonus.c			printf_utils_f_1_bonus.c	printf_utils_f_2_bonus.c	printf_utils_g_1_bonus.c	\
				printf_utils_g_2_bonus.c	printf_utils_e_bonus.c		printf_o_bonus.c

LIBFT = libft
OBJS = $(SRCS:.c=.o)
OBJS_BONUS = $(SRCS_BONUS:.c=.o)

all: $(NAME)

$(NAME): $(OBJS)
	make -C $(LIBFT)
	cp libft/libft.a ./$(NAME)
	ar rc $@ $^

bonus: $(OBJS_BONUS)
	make -C $(LIBFT)
	cp libft/libft.a ./$(NAME)
	ar rc $(NAME) $^

%.o: %.c
	$(CC) -c $(CFLAGS) -o $@ $<

clean:
	rm -f $(OBJS) $(OBJS_BONUS)
	make clean -C $(LIBFT)

fclean: clean
	rm -f $(NAME)
	make fclean -C $(LIBFT)

re: fclean all

.PHONY:
	all bonus clean fclean re
