##
## Makefile for Rush1 in /Rush1/step_1
##
## Made by Antoine Baché
## Login   <bache_a@epitech.net>
##
## Started on  Fri Jan  8 20:09:51 2016 Antoine Baché
## Last update Sun Jan 10 12:33:54 2016 Antoine Baché
##

DEBUG=		yes

SRC=		src/main.c			\
		src/check_args.c		\
		src/options.c			\
		src/my_archive/main.c		\
		src/my_archive/debug_tools.c	\
		src/my_archive/parse.c		\
		src/my_archive/free_all.c	\
		src/my_archive/create_file.c	\
		src/my_archive/header.c		\
		src/my_archive/select_file.c	\
		src/my_archive/recursive.c	\
		src/my_archive/errors.c		\
		src/my_unarchive/chksum.c	\
		src/my_unarchive/tools.c	\
		src/my_unarchive/debug_tools.c	\
		src/my_unarchive/unarchive.c

NAME=		my_tar

HEAD=		-Iinclude

ifeq ($(DEBUG), yes)
		CFLAGS=		$(HEAD) -W -Wall -Wextra -ansi -pedantic -g -D DEBUG
else
		CFLAGS=		$(HEAD) -W -Wall -Wextra -Werror -ansi -pedantic
endif

CC=		gcc

RM=		rm -f

OBJ=		$(SRC:.c=.o)

$(NAME):	$(OBJ)
ifeq ($(DEBUG), yes)
	@tput setaf 1; tput bold
	@echo "  ____  _____ ____  _   _  ____   __  __  ___  ____  _____ ";
	@echo " |  _ \| ____| __ )| | | |/ ___| |  \/  |/ _ \|  _ \| ____|";
	@echo " | | | |  _| |  _ \| | | | |  _  | |\/| | | | | | | |  _|  ";
	@echo " | |_| | |___| |_) | |_| | |_| | | |  | | |_| | |_| | |___ ";
	@echo " |____/|_____|____/ \___/ \____| |_|  |_|\___/|____/|_____|";
	@echo "                                                           ";
	@tput sgr0
endif
	@echo -n "Compiling ..." $(NAME)
	@$(CC) $(OBJ) -o $(NAME)
	@tput setaf 2; tput bold; echo "			OK"
	@tput sgr0

%.o: %.c
	@$(CC) -o $@ -c $< $(CFLAGS)

all:	$(NAME)

clean:
	@echo -n "Removing OBJ files ..."
	@$(RM) $(OBJ)
	@tput setaf 2; tput bold; echo "			OK"
	@tput sgr0

fclean:	clean
	@echo -n "Deleting" $(NAME) "..."
	@$(RM) $(NAME)
	@tput setaf 2; tput bold; echo "			OK"
	@tput sgr0

re:	fclean all

.PHONY:	all clean fclean re
