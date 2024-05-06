/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: johmatos <johmatos@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/09 19:49:49 by johmatos          #+#    #+#             */
/*   Updated: 2023/11/09 20:11:55 by johmatos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt_bonus.h"
#include <pthread.h>

static void			*thread_routine(void *task);
static int			get_start_idx(int thread_number);
static int			get_end_idx(int thread_number);
static void			draw_pixel(t_task task, int idx);

void	render(t_world world)
{
	int			idx;
	pthread_t	worker[NUM_THREADS];
	t_task		task[NUM_THREADS];

	idx = 0;
	while (idx < NUM_THREADS)
	{
		task[idx] = (t_task){
			.id = idx + 1,
			.image = world.image,
			.camera = world.camera,
			.world = &world,
			.start_idx = get_start_idx(idx + 1),
			.end_idx = get_end_idx(idx + 1),
		};
		pthread_create(&worker[idx], NULL, thread_routine, &task[idx]);
		idx++;
	}
	idx = -1;
	while (++idx < NUM_THREADS)
		pthread_join(worker[idx], NULL);
}

static inline void	*thread_routine(void *task_ptr)
{
	t_task	task;
	int		idx;

	task = *(t_task *)task_ptr;
	idx = task.start_idx;
	while (idx < task.end_idx)
	{
		draw_pixel(task, idx);
		idx++;
	}
	return (NULL);
}

static inline void	draw_pixel(t_task task, int idx)
{
	const t_ray		ray = ray_for_pixel(task.camera, idx);
	const t_tuple	color = color_at(task.world, &ray);
	uint8_t			*pixelstart;

	pixelstart = &task.image->pixels[idx * sizeof(int32_t)];
	ft_mlx_draw_pixel(pixelstart, normalized_color_to_int(color));
}

static inline int	get_start_idx(int thread_number)
{
	uint	total_pixels;
	int		remainder;

	if (1 == thread_number)
		return (0);
	total_pixels = SIZEH * SIZEW;
	remainder = total_pixels % NUM_THREADS;
	return ((total_pixels / NUM_THREADS) * (thread_number - 1) + remainder);
}

static inline int	get_end_idx(int thread_number)
{
	uint	total_pixels;
	short	remainder;

	total_pixels = SIZEH * SIZEW;
	remainder = total_pixels % NUM_THREADS;
	return (((total_pixels / NUM_THREADS) * thread_number + remainder) - 1);
}
