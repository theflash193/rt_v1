# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: grass-kw <grass-kw@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/04/10 05:28:51 by grass-kw          #+#    #+#              #
#    Updated: 2016/07/09 15:20:38 by grass-kw         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME 			= rt_v1

DEBUG 			= no
HEADER			= rt_v1
### DIRECTORIES ###
DIRRSC			:= resources
DIRSRC			:= $(DIRRSC)/src
DIROBJ			:= $(DIRRSC)/obj
DIRINC			:= $(DIRRSC)/includes
DIRFT			:= $(DIRRSC)/libft
DIRX			:= $(DIRRSC)/libx

DIRMAIN 		:= $(DIRSRC)/main
DIRCOREUTILS 	:= $(DIRSRC)/coreutils
DIRMLX 			:= $(DIRSRC)/mlx
DIRRT 			:= $(DIRSRC)/raytracer
DIRPARSER		:= $(DIRSRC)/parser
DIROBJECTS		:= $(DIRSRC)/objects

### FILES ###
HEAD	:= $(DIRINC)/$(HEADER).h

include $(DIRMAIN)/sources.mk
include $(DIRCOREUTILS)/sources.mk
include $(DIRMLX)/sources.mk
include $(DIRRT)/sources.mk
include $(DIRPARSER)/sources.mk
include $(DIROBJECTS)/sources.mk

POBJ	:= $(addprefix $(DIROBJ)/, $(OBJ))


### COMPILATION VARIABLES ###
CC	:= gcc
ifeq ($(DEBUG),yes)
	C_FLAG	:= -Wall -Werror -Wextra -g
else
	C_FLAG	:= -Wall -Werror -Wextra
endif

C_INC	:= -I $(DIRINC) -I $(DIRX) -I $(DIRFT)/includes
L_FLAG	:= -L $(DIRFT) -lft -L $(DIRX) -framework OpenGL -framework AppKit -lmlx


COMPIL	= $(CC) -o $@ -c $< $(C_INC)
LINK	= @$(CC) -o $@ $^ $(L_FLAG) $(C_FLAG)

### RULES ###
.PHONY: all clean fclean re lldb
.SILENT:

all: $(NAME)
ifeq ($(DEBUG),yes)
	@echo "Generated in DEBUG mode"
else
	@echo "Generated in RELEASE mode"
endif

$(POBJ): |$(DIROBJ)

$(DIROBJ):
	mkdir $(DIROBJ)

$(NAME): $(POBJ)
	make -C $(DIRFT)
	$(LINK)
### LIBS ###

### MICS ###
clean:
	@rm -rf $(DIROBJ)

fclean: clean
	@rm -f $(NAME)
	make -C $(DIRFT) fclean

re: fclean all

lldb: $(NAME)
	lldb $(NAME)

norme:
	@norminette $(SRCS)
	@norminette $(INC_PATH)
	@echo "[->] Total errors (May include object files) :" $(shell norminette $(NORM) | grep -v "Norme" | wc -l)
git:
	git add .
	echo "Please, enter your commit : "
	read root_path ; git commit -m "$$root_path"
	git push

main: all
	./a.out
