/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   visu.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ntoniolo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/23 17:01:20 by ntoniolo          #+#    #+#             */
/*   Updated: 2017/02/10 18:58:41 by ntoniolo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/filler.h"

/*
**Set case and color
*/

static void	pxtopx_dir(int x, int y, t_env *e)
{
	t_pxtopx	*pxtopx;
	t_px		*px;

	px = &e->draw.px;
	pxtopx = &e->draw.pxtopx;
	pxtopx->y1 = y * e->size_seg_y;
	pxtopx->y2 = (y + 1) * e->size_seg_y;
	pxtopx->x1 = x * (e->size_seg_x);
	pxtopx->x2 = (x + 1) * (e->size_seg_x);
	draw_case(e);
}

static void	color_dir(t_env *e, t_px *px, int y, int x)
{
	if (e->map.map[y][x] == e->vs_c)
		mlxji_hsv_to_rgb(px, 300, 1, 0.8);
	if (e->map.map[y][x] == e->vs_c - 32)
		mlxji_hsv_to_rgb(px, 75, 1, 0.6);
	if (e->map.map[y][x] == 'N')
		mlxji_hsv_to_rgb(px, 150, 1, 0.8);
	if (e->map.map[y][x] == e->player_c)
		mlxji_hsv_to_rgb(px, 270, 1, 0.8);
}

static void	loop_search_color(t_env *e, t_px *px)
{
	int			x;
	int			y;

	y = 0;
	while (y < e->map.size_y)
	{
		x = 0;
		while (x < e->map.size_x)
		{
			if (e->map.map[y][x] != '.')
			{
				color_dir(e, px, y, x);
				pxtopx_dir(x, y, e);
			}
			x++;
		}
		y++;
	}
}

int			visu(t_env *e)
{
	t_px		*px;

	px = &e->draw.px;
	if (e->map.size_x > e->map.size_y)
	{
		e->size_seg_x = (WIN_W / (e->map.size_x));
		e->size_seg_y = (WIN_H / (e->map.size_y));
	}
	else
	{
		e->size_seg_x = ((WIN_W) / (e->map.size_x));
		e->size_seg_y = ((WIN_H) / (e->map.size_y));
	}
	loop_search_color(e, px);
	if (e->draw.check_sol > 0 && e->w8 == 1)
		visu_solve(e, &e->piece);
	if (e->key[48])
		visu_all(e, &e->piece);
	draw_grid(e);
	if (e->draw.check_sol != e->draw.check_past)
	{
		e->draw.check_past = e->draw.check_sol;
		extern_info(e);
	}
	return (1);
}
