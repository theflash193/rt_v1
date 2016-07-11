MAIN	:=	utils.c ft_lstlen.c valid_rgb.c add_vector.c \
			sub_vector.c norme.c reverse_vector.c normalize.c dot_product.c \
			utils2.c ft_capitalize.c ft_strequ_uci.c clean_env.c clean_elem.c \
			add_rgb.c \

OBJ	:= $(OBJ) $(MAIN:.c=.o)

$(DIROBJ)/%.o: $(DIRCOREUTILS)/%.c $(HEAD)
	$(COMPIL)
