MAIN	:= sphere.c plan.c cone.c cylindre.c cone.c

OBJ	:= $(OBJ) $(MAIN:.c=.o)

$(DIROBJ)/%.o: $(DIROBJECTS)/%.c $(HEAD)
	$(COMPIL)
