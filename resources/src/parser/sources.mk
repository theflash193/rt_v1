MAIN	:=	parser.c check_tab_is_valid.c \
			ft_exit.c is_camera.c is_light.c is_object.c \
			msg_usage.c parser_light.c parser_camera.c parser_object.c \

OBJ	:= $(OBJ) $(MAIN:.c=.o)

$(DIROBJ)/%.o: $(DIRPARSER)/%.c $(HEAD)
	$(COMPIL)
