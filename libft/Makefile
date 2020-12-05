# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: dpatrica <dpatrica@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/10/05 21:31:17 by dpatrica          #+#    #+#              #
#    Updated: 2020/11/08 17:15:18 by dpatrica         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS	=	ft_strlen.c ft_memset.c ft_bzero.c ft_memcpy.c ft_memccpy.c\
ft_memmove.c ft_memchr.c ft_memcmp.c ft_strlcpy.c ft_strlcat.c ft_strchr.c\
ft_strrchr.c ft_strnstr.c ft_strncmp.c ft_isalpha.c ft_isdigit.c ft_isalnum.c\
ft_isascii.c ft_isprint.c ft_toupper.c ft_tolower.c ft_atoi.c ft_calloc.c\
ft_strdup.c ft_substr.c ft_strjoin.c ft_strtrim.c ft_split.c ft_putchar_fd.c\
ft_putstr_fd.c ft_putendl_fd.c ft_putnbr_fd.c ft_strmapi.c ft_itoa.c\
ft_digitlen.c ft_mpldig.c ft_putnbr.c ft_ungitlen.c ft_putstr.c ft_dig16len.c\
ft_digplen.c

HEAD	=	libft.h
NAME	= 	libft.a
OBJS	=	$(SRCS:.c=.o)

GCC		= 	gcc
FLAG	=	-Wall -Wextra -Werror
RM		=	rm -f
C		=	-c
O		=	-o
AR		=	ar rc

.PHONY:		all clean fclean re

.c.o:
			$(GCC) $(FLAG) $(C) $< $(O) $(<:.c=.o)

$(NAME):	$(OBJS) $(HEAD)
			$(AR) $(NAME) $(OBJS)

all:		$(NAME)

clean:
			$(RM) $(OBJS)

fclean:		clean
			$(RM) $(NAME)

re:			fclean all