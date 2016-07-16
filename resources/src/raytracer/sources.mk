MAIN	:= raytracer.c shade.c rotation.c resolve.c \
		closest_obj_inter.c intersection.c \
		diffuse_color.c specular_color.c ambient_color.c shadow.c\

OBJ	:= $(OBJ) $(MAIN:.c=.o)

$(DIROBJ)/%.o: $(DIRRT)/%.c $(HEAD)
	$(COMPIL)
