# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: thberrid <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/10/01 22:59:58 by thberrid          #+#    #+#              #
#    Updated: 2020/10/01 23:00:12 by thberrid         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

#nasm -f elf64 test.s
#ld -dynamic-linker /lib64/ld-linux-x86-64.so.2 -m elf_x86_64 test.o -lc

SHELL	= /bin/sh
NAME	= libasm.a
AR 		= ar rc
DIR_C 	= sources
DIR_O	= obj
DIR_H	= includes
NAME_C	= test.s
NAME_O	= $(NAME_C:.c=.o)
NAME_H	= libasm.h
FILES_C	= $(addprefix $(DIR_C)/, $(NAME_C))
FILES_O	= $(addprefix $(DIR_O)/, $(NAME_O))
FILES_H	= $(addprefix $(DIR_H)/, $(NAME_H))
LIBFT	= ./libft/libft.a
FLAGS_NASM	= -f elf64
FLAGS_LD	= -dynamic-linker /lib64/ld-linux-x86-64.so.2 -lc
FLAGS_C	= -Wall -Wextra -Werror -g3


.PHONY: all
all : $(NAME)

$(NAME) : $(FILES_O)
	$(AR) $@ $^
	ranlib $@
 
$(DIR_O)/%.o : $(DIR_C)/%.s $(FILES_H)
	@ mkdir -p $(DIR_O)
	nasm $(NASM_FLAGS) -o $@ $<
	ld -o $@ $< $(FLAGS_LD)

test : $(name)


.PHONY : clean
clean :
	rm -f $(FILES_O)

.PHONY : fclean
fclean : clean
	rm -f $(NAME) test

.PHONY : re
re : fclean all
