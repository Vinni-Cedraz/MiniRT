/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minirt.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vcedraz- <vcedraz-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/22 16:09:38 by vcedraz-          #+#    #+#             */
/*   Updated: 2023/12/26 17:28:52 by vcedraz-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINIRT_H
# define MINIRT_H

# include "../MLX42/include/MLX42/MLX42.h"
# include "../libs/libft.h"
# include "../libs/libft_bonus.h"
# include "./minirt_defines.h"
# include "./minirt_math.h"
# include <math.h>
# include <stdint.h>
# include <stdio.h>

void					load_objs_into_world(mlx_image_t *image,
							t_camera camera, t_world *world);
mlx_image_t				**get_image_to_render(mlx_t *mlx);
void					render_a_default_world(mlx_t *mlx);
int						endwith(char *str, char *end);
void					parse_sphere(char *str, t_parsectx *ctx);
t_world					*parse_file(char *file);
void					parse_plane(char *str, t_parsectx *ctx);
void					parse_light(char *str, t_parsectx *ctx);
void					parse_cylinder(char *str, t_parsectx *ctx);
void					parse_ambient_lightning(char *str, t_parsectx *ctx);
int						ft_strcmp(const char *s1, const char *s2);
void					parse_camera(char *str, t_parsectx *ctx);
const 					t_idtable *get_parser_table(void);
int						ft_strcmp(const char *s1, const char *s2);
#endif
