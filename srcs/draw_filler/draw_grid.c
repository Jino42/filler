/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_grid.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ntoniolo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/30 21:03:43 by ntoniolo          #+#    #+#             */
/*   Updated: 2017/02/10 18:57:41 by ntoniolo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/filler.h"

static void	draw_grid_horizon(t_env *e)
{
	int			x;
	t_px		*px;
	t_pxtopx	*to;

	to = &e->draw.pxtopx;
	px = &e->draw.px;
	px->r = 30;
	px->g = 30;
	px->b = 30;
	x = 0;
	while (x < e->map.size_x + 1)
	{
		to->x1 = x * (e->size_seg_x);
		to->y1 = 0;
		to->x2 = x * (e->size_seg_x);
		to->y2 = e->map.size_y * e->size_seg_y;
		mlxji_draw_line(e->img, px, to);
		x++;
	}
}

static void	draw_grid_vertical(t_env *e)
{
	int			y;
	t_px		*px;
	t_pxtopx	*to;

	to = &e->draw.pxtopx;
	px = &e->draw.px;
	px->r = 30;
	px->g = 30;
	px->b = 30;
	y = 0;
	while (y < e->map.size_y)
	{
		to->x1 = 0;
		to->y1 = y * e->size_seg_y;
		to->x2 = e->map.size_x * (e->size_seg_x);
		to->y2 = y * e->size_seg_y;
		mlxji_draw_line(e->img, px, to);
		y++;
	}
}

void		draw_grid(t_env *e)
{
	draw_grid_vertical(e);
	draw_grid_horizon(e);
}
