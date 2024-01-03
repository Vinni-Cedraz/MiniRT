/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minirt_structs.h                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vcedraz- <vcedraz-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/19 19:11:28 by vcedraz-          #+#    #+#             */
/*   Updated: 2023/12/19 19:17:30 by vcedraz-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINIRT_STRUCTS_H
# define MINIRT_STRUCTS_H
# include "../libs/libft_bonus.h"

typedef float			t_tuple[4];
typedef float			t_3x3_row[3];
typedef float			t_2x2_row[2];
typedef _Bool			t_bool;
typedef unsigned short	t_short;
typedef struct s_parsectx 	t_parsectx;
typedef void (*t_func_apply)(char *, t_parsectx *);

typedef enum e_num
{
	SPHERE,
	PLANE,
	CYLINDER,
}						t_enum;

typedef struct s_canvas
{
	unsigned short		width;
	unsigned short		height;
	unsigned short		size;
	t_tuple				**pixels;
}						t_canvas;

typedef struct s_matrix
{
	t_tuple				row_1;
	t_tuple				row_2;
	t_tuple				row_3;
	t_tuple				row_4;
	float				*rows[4];
}						t_matrix;

typedef struct s_2x2matrix
{
	t_2x2_row			row_1;
	t_2x2_row			row_2;
	float				*rows[2];
}						t_2x2matrix;

typedef struct s_3x3matrix
{
	t_3x3_row			row_1;
	t_3x3_row			row_2;
	t_3x3_row			row_3;
	float				*rows[3];
}						t_3x3matrix;

typedef struct s_hearer
{
	float				x_to_y;
	float				x_to_z;
	float				y_to_x;
	float				y_to_z;
	float				z_to_x;
	float				z_to_y;
}						t_shearer;

typedef struct s_ray
{
	t_tuple				origin;
	t_tuple				direction;
}						t_ray;

typedef struct s_point_light
{
	t_tuple				position;
	t_tuple				intensity;
}						t_point_light;

typedef struct s_material
{
	float				ambient;
	float				diffuse;
	float				specular;
	float				shininess;
	t_tuple				color;
}						t_material;

typedef struct s_colors
{
	t_tuple				diffuse;
	t_tuple				reflectv;
	t_tuple				true_colr;
	t_tuple				lightv;
	t_tuple				ambient;
	t_tuple				specular;
}						t_colors;

typedef struct s_lighting
{
	t_material			material;
	t_point_light		light;
	t_tuple				position;
	t_tuple				eye_vec;
	t_tuple				normal_vec;
	t_bool				in_shadow;
}						t_lighting;

typedef struct s_intersect
{
	t_node				*head;
	t_short				count;
}						t_intersection;

typedef struct s_shape
{
	unsigned short		id;
	int					type;
	t_tuple				origin;
	t_matrix			_t;
	t_matrix			inverse_t;
	t_matrix			transposed_inverse_t;
	t_material			material;
	float				min;
	float				max;
	t_bool				closed;
}						t_shape;

typedef struct s_phere
{
	unsigned short		id;
	int					type;
	t_tuple				origin;
	t_matrix			_t;
	t_matrix			inverse_t;
	t_matrix			transposed_inverse_t;
	t_material			material;
	float				min;
	float				max;
	t_bool				closed;
}						t_sphere;

typedef struct s_plane
{
	unsigned short		id;
	int					type;
	t_tuple				origin;
	t_matrix			_t;
	t_matrix			inverse_t;
	t_matrix			transposed_inverse_t;
	t_material			material;
	float				min;
	float				max;
	t_bool				closed;
}						t_plane;

typedef struct s_cylinder
{
	unsigned short		id;
	int					type;
	t_tuple				origin;
	t_matrix			_t;
	t_matrix			inverse_t;
	t_matrix			transposed_inverse_t;
	t_material			material;
	float				min;
	float				max;
	t_bool				closed;
}						t_cylinder;

typedef struct s_world
{
	t_shape				*objs;
	t_point_light		*light;
	int					count;
}						t_world;

typedef struct s_baskara
{
	float				a;
	float				b;
	float				c;
	float				t0;
	float				t1;
}						t_baskara;

typedef struct s_comp
{
	float				t;
	t_shape				*object;
	t_tuple				over_point;
	t_tuple				point;
	t_tuple				eyev;
	t_tuple				normalv;
	t_bool				inside;
}						t_prep_comps;

typedef struct s_camera
{
	float				hsize;
	float				vsize;
	float				half_width;
	float				half_height;
	float				field_of_view;
	t_matrix			transform;
	float				pixel_size;
	float				xoffset;
	float				yoffset;
	float				world_x;
	float				world_y;
}						t_camera;

typedef struct s_parsectx
{
	int					line;
	int					column;
	int					err;
	t_shape				*shape_list;
}						t_parsectx;

typedef struct s_idtable
{
	char				id[3];
	t_func_apply 		apply;
}						t_idtable;
#endif
