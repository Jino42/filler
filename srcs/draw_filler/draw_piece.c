/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_piece.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ntoniolo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/07 13:24:24 by ntoniolo          #+#    #+#             */
/*   Updated: 2017/02/10 04:39:53 by ntoniolo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/filler.h"

static void	pxtopx_dir_piece(t_env *e, int y, int x, int size_seg)
{
	t_pxtopx	*pxtopx;
	t_px		*px;
	int			over_x;
	int			over_y;

	over_y = 100;
	over_x = 900;
	px = &e->draw.px;
	pxtopx = &e->draw.pxtopx;
	pxtopx->y1 = y * size_seg + over_y;
	pxtopx->y2 = (y + 1) * size_seg + over_y;
	pxtopx->x1 = x * (size_seg / 2) + over_x;
	pxtopx->x2 = (x + 1) * (size_seg / 2) + over_x;
	draw_case(e);
}

static int	loop_piece(t_env *e, t_px *px, int size_seg)
{
	int y;
	int x;

	mlxji_hsv_to_rgb(px, 300, 1, 0.8);
	y = 0;
	while (y < e->piece.size_y)
	{
		x = 0;
		while (x < e->piece.size_x)
		{
			if (e->piece.piece[y][x] == '*')
				pxtopx_dir_piece(e, y, x, size_seg);
			x++;
		}
		y++;
	}
	return (1);
}

int			draw_piece(t_env *e, t_px *px, int size_seg)
{
	loop_piece(e, px, size_seg);
	return (1);
}
