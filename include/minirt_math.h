/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minirt_math.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vcedraz- <vcedraz-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/19 19:08:39 by vcedraz-          #+#    #+#             */
/*   Updated: 2023/12/19 19:14:24 by vcedraz-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINIRT_MATH_H
# define MINIRT_MATH_H
# include "minirt_structs.h"

typedef t_intersection	(*t_intersect_function)(t_shape **, t_tuple, t_ray);
typedef void			(*t_normal_at_function)(const t_shape *, const t_tuple,
				t_tuple);

void					create_point(t_tuple tuple);
void					create_vector(t_tuple tuple);
t_bool					floats_eq(float a, float b);
void					add_tuples(const t_tuple a, const t_tuple b,
							t_tuple result);
void					subtract_tuples(const t_tuple a, const t_tuple b,
							t_tuple result);
void					negate_tuple(const t_tuple a, t_tuple result);
void					multiply_tuple_by_scalar(const t_tuple a, const float s,
							t_tuple r);
void					multiply_tuple_by_matrix(const t_tuple row, t_matrix m,
							t_tuple res);
void					multiply_colors(const t_tuple c1, const t_tuple c2,
							t_tuple result);
t_bool					floats_eq(float a, float b);
float					magnitude(const t_tuple vec);
short					normalize(const t_tuple vec, t_tuple result);
short					cross(const t_tuple a, const t_tuple b,
							t_tuple cross_product);
t_canvas				create_canvas(unsigned short height,
							unsigned short width);
void					write_pixel(t_canvas *canvas, int y, int x,
							const t_tuple pixel);
char					*canvas_to_ppm(const t_canvas *canvas);
void					destroy_canvas(const t_canvas *canvas);
t_matrix				mult_matrices(t_matrix a, t_matrix b);
t_bool					matrices_eq(t_matrix a, t_matrix b);
float					dot(const t_tuple a, const t_tuple b);
t_matrix				mult_by_identity(t_matrix a);
t_matrix				transpose_matrix(t_matrix a);
float					_2x2determinant(const t_2x2matrix m);
t_2x2matrix				_3x3submatrix(const t_3x3matrix m, int not_row,
							int col_to_delete);
t_bool					tuples_neq(const float *result, const float *expected,
							int len);
t_bool					_3x3matrices_eq(t_3x3matrix a, t_3x3matrix b);
t_bool					_2x2matrices_eq(t_2x2matrix a, t_2x2matrix b);
t_3x3matrix				_4x4submatrix(const t_matrix m, int not_row,
							int not_col);
float					_3x3minor(const t_3x3matrix m, int row, int col);
float					_3x3cofactor(const t_3x3matrix m, int row, int col);
float					_3x3determinant(const t_3x3matrix m);
float					_4x4determinant(const t_matrix m);
float					_3x3minor(const t_3x3matrix m, int row, int col);
float					_4x4minor(const t_matrix m, int row, int col);
float					_3x3cofactor(const t_3x3matrix m, int row, int col);
float					_4x4cofactor(const t_matrix m, int row, int col);
t_bool					is_invertible(const t_matrix m);
t_matrix				invert_matrix(const t_matrix m);
t_matrix				create_4x4_matrix(t_matrix *m);
t_3x3matrix				create_3x3_matrix(t_3x3matrix *m);
t_2x2matrix				create_2x2_matrix(t_2x2matrix *m);
t_matrix				create_translation_matrix(t_tuple point);
t_matrix				create_matrix_of_cofactors(const t_matrix m);
t_matrix				create_x_rotation_matrix(float r);
t_matrix				create_y_rotation_matrix(float r);
t_matrix				create_z_rotation_matrix(float r);
t_matrix				create_scaling_matrix(const float x, const float y,
							const float z);
t_matrix				create_shearing_matrix(t_shearer shearer);
t_matrix				chain_transformations(t_matrix *matrices[]);
void					translate_coordinate(t_tuple point, t_canvas *canvas,
							t_tuple res);
void					get_position(t_ray ray, float distance,
							t_tuple _result);
t_ray					create_ray(t_tuple origin, t_tuple direction);
t_sphere				create_sphere(void);
t_bool					tuples_eq(const t_tuple result, const t_tuple expected);
t_intersection			create_intersection(void *shape, t_ray r);
t_intersection			link_intersection_nodes(t_node *arr[]);
t_node					get_hit(t_intersection i);
t_matrix				create_identity_matrix(void);
t_ray					transform_ray(t_ray ray, t_matrix matrix);
void					set_transform(t_shape *s, t_matrix t);
void					sphere_normal_at(const t_shape *sphere, const t_tuple p,
							t_tuple res);
void					plane_normal_at(const t_shape *sphere, const t_tuple p,
							t_tuple res);
void					cylinder_normal_at(const t_shape *cyl, const t_tuple p,
							t_tuple res);
void					reflect(t_tuple vector, t_tuple normal,
							t_tuple _return);
t_material				create_material(void);
void					calculate_lighting(t_lighting *obj, t_tuple result);
t_constr				make_aslib_test(void);
t_world					create_world(void);
t_world					default_world(void);
void					set_material(t_tuple reflections, t_tuple color,
							t_material *m);
t_intersection			intersect_world_with_ray(t_world *w, t_ray *r);
t_prep_comps			prepare_computations(t_node *intersection, t_ray ray);
void					shade_hit(t_world *world, t_prep_comps *comps,
							t_tuple result);
void					init_tuple(const t_tuple tuple, t_tuple res);
void					color_at(t_world *world, t_ray *ray, t_tuple color);
t_matrix				view_transform(t_tuple from, t_tuple forward,
							t_tuple up);
t_camera				create_camera(int hsize, int vsize,
							float field_of_view);
t_ray					ray_for_pixel(t_camera c, int x, int y);
t_canvas				render(t_camera camera, t_world world);
t_intersection			intersect_sphere(t_shape **obj, t_tuple dist, t_ray r);
t_intersection			intersect_plane(t_shape **obj, t_tuple dist, t_ray r);
t_intersection			intersect_cylinder(t_shape **obj,
							t_tuple obj_dist_to_ray, t_ray r);
t_plane					create_plane(void);
t_cylinder				create_cylinder(void);
float					discriminant(t_tuple obj_dist_ray, t_ray ray,
							t_baskara *bask);
void					set_cyl_min_max(t_cylinder *cyl, float min, float max);
void					intersect_caps(const t_cylinder *cyl, const t_ray r,
							t_node **head);
void					quick_render(t_world *w);
t_node					*intersection(float point, t_shape **obj);
void					add_three_tuples(t_tuple ambient, t_tuple diffuse,
							t_tuple specular, t_tuple result);
t_bool					is_shadowed(t_world *w, t_tuple p);
void					add_object(t_world *w, t_shape *new_obj, int index);
#endif
