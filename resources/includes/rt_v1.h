/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rt_v1.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: grass-kw <grass-kw@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/10 06:21:56 by grass-kw          #+#    #+#             */
/*   Updated: 2016/07/09 14:50:52 by grass-kw         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RT_V1_H
# define RT_V1_H
# include "libft.h"
# include "mlx.h"
# include "ft_keycode.h"
# include <stdio.h>
# include <stdlib.h>
# include <math.h>
# include <time.h>
# include <fcntl.h>
# define LENGHT 720
# define WIDTH 680
# define CAMERA 1
# define SPHERE 2
# define PLAN 3
# define CYLINDRE 4
# define CONE 5
# define SPOT 6
# define ZERO 0.00001
# define SPECULAR e->obj_inter->material.specular

typedef struct			s_color
{
	int					r;
	int					g;
	int					b;
}						t_color;

typedef	struct			s_vector3d
{
	double				x;
	double				y;
	double				z;
}						t_vector3d;

typedef struct			s_material
{
	double				shine;
	double				ka;
	double				kd;
	double				ks;
	int					pow_spec;
	double				specular;
}						t_material;

typedef struct			s_obj
{
	int					type;
	t_vector3d			origin;
	t_color				color;
	t_vector3d			angle;
	double				size;
	t_vector3d			l;
	t_material			material;
}						t_obj;

typedef	struct			s_env
{
	void				*mlx;
	void				*win;
	void				*img;
	char				*data;
	int					bits_per_pixel;
	int					size_line;
	int					endian;
	t_vector3d			ray;
	t_obj				start;
	char				intersection : 1;
	double				k;
	t_list				*list_obj;
	t_list				*list_spot;
	t_obj				*obj_inter;
	t_vector3d			inter;
	t_vector3d			n;
	double				norme;
	t_vector3d			dot_product;
	int					nb_spots;
	int					start_width;
	int					start_lenght;
	int					max_width;
	int					max_lenght;
}						t_env;

/*
** coreutils
*/
t_vector3d				new_vector(double x, double y, double z);
t_color					set_rgb(int r, int g, int b);
void					valid_rgb(t_color *color);
t_vector3d				add_vector(t_vector3d a, t_vector3d b);
t_vector3d				reverse_vector(t_vector3d a);
t_vector3d				sub_vector(t_vector3d a, t_vector3d b);
double					norme(t_vector3d a);
t_vector3d				normalize(t_vector3d a);
double					dot_product(t_vector3d a, t_vector3d b);
double					max(double a, double b);
char					*ft_capitalize(char *s);
int						ft_strequ_uci(char const *s1, char const *s2);
void					clean_elem(void *content, size_t content_size);
void					clean_env(t_env *e);
t_color					add_rgb(t_color a, t_color b);

/*
** mlx
*/
int						expose(t_env *e);
int						key(int key, t_env *e);
void					env_setup(t_env *e);
void					set_pixel(t_env *e, int color, int x, int y);
int						new_color(t_color rgb);
void					draw(t_env *e);

/*
*** raytracer
*/
t_color					raytracer(t_env *e, t_vector3d start, t_vector3d ray);
void					rotation_inverse(t_vector3d *a, t_vector3d angle);
void					rotation(t_vector3d *a, t_vector3d angle);
double					sphere(t_obj obj, t_vector3d origin, t_vector3d v);
double					plan(t_obj obj, t_vector3d origin, t_vector3d v);
double					cylindre(t_obj obj, t_vector3d origin, t_vector3d v);
double					cone(t_obj obj, t_vector3d origin, t_vector3d v);
double					resolve(double delta, double a, double b);
double					inter(t_obj *obj, t_vector3d *start, t_vector3d *ray);
t_obj					*closest_obj_inter(t_env *e, t_vector3d start,
	t_vector3d ray);
t_color					shade(t_env *e, t_obj *object, t_vector3d *inter,
	t_vector3d ray);
int						shadow(t_env *e, t_vector3d inter);
t_color					brightness(t_env *e, t_color color);

t_color					assign_rgb(t_color new_color, t_env *e);
double					vecdot(t_vector3d a, t_vector3d b);
t_vector3d				normalize_obj(t_env *e);
double					bright(double color, double cosa, t_obj *obj);
double					shine(t_obj *object, double color, double norme);
double					ambient_light(double color, t_obj obj);
double					diffuse_light(t_vector3d a, t_vector3d b);
double					specular_light(t_vector3d e, t_vector3d r,
	t_obj *obj);
t_color					assign_rgb(t_color new_color, t_env *e);
t_color					direct_light(t_env *e, t_color color_final);
t_color					specular_color(t_obj *light, t_vector3d n,
	t_obj *object, t_vector3d ray);
t_color					diffuse_color(t_obj *light, t_vector3d n,
	t_obj *object);
t_color					ambient_color(t_obj *object);

/*
** parser
*/
void					parser(t_env *e, char *argument);
int						check_valid_line(char **line);
void					parser_light(char **line, t_env *e);
void					parser_object(char **line, t_env *e);
void					parser_camera(char **line, t_env *e);
int						is_float(char *s);
int						is_object(char *s);
int						is_light(char *s);
int						is_camera(char *s);
void					msg_usage(void);
void					create_window(char *argument);
int						check_tab_is_valid(char **tab);
void					ft_exit(char *message, t_env *e);

#endif
