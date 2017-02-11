/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_solve.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ntoniolo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/30 21:16:05 by ntoniolo          #+#    #+#             */
/*   Updated: 2017/02/10 19:11:59 by ntoniolo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/filler.h"

/*
** Color_visu     : select solution
** Color_all_visu : voir toutes les solutions
** e->dir incr toutes les pieces;
*/

static void		color_solve_ponp(t_env *e, int x, int y)
{
	t_pxtopx	*pxtopx;
	t_px		*px;
	t_draw		*draw;

	draw = &e->draw;
	px = &draw->px;
	pxtopx = &draw->pxtopx;
	pxtopx->y1 = y * e->size_seg_y;
	pxtopx->y2 = (y + 1) * e->size_seg_y;
	pxtopx->x1 = x * (e->size_seg_x);
	pxtopx->x2 = (x + 1) * (e->size_seg_x);
	if (draw->value >= 0.95)
		draw->dir_value = -0.0050;
	else if (draw->value <= 0.4)
		draw->dir_value = 0.0150;
	draw->value += draw->dir_value;
	if (e->map.map[y][x] == e->player_c)
		mlxji_hsv_to_rgb(px, 160 + 15, draw->saturation, draw->value);
	else
		mlxji_hsv_to_rgb(px, 160, draw->saturation, draw->value);
	draw_case(e);
}

static void		color_solve(t_env *e, int x, int y)
{
	t_pxtopx	*pxtopx;
	t_px		*px;
	t_draw		*draw;

	draw = &e->draw;
	px = &draw->px;
	pxtopx = &draw->pxtopx;
	pxtopx->y1 = y * e->size_seg_y;
	pxtopx->y2 = (y + 1) * e->size_seg_y;
	pxtopx->x1 = x * (e->size_seg_x);
	pxtopx->x2 = (x + 1) * (e->size_seg_x);
	if (draw->value >= 0.95)
		draw->dir_value = -0.0050;
	else if (draw->value <= 0.4)
		draw->dir_value = 0.0150;
	draw->value += draw->dir_value;
	if (e->map.map[y][x] == e->player_c)
		mlxji_hsv_to_rgb(px, draw->hue + 15, draw->saturation, draw->value);
	else
		mlxji_hsv_to_rgb(px, draw->hue, draw->saturation, draw->value);
	draw_case(e);
}

void			visu_solve(t_env *e, t_piece *piece)
{
	int		x;
	int		y;
	t_list	*lst;
	t_solve	*solve;

	lst = e->lst;
	while (lst != NULL)
	{
		solve = lst->content;
		if (solve->nb == e->draw.check_sol)
			break ;
		lst = lst->next;
	}
	y = 0;
	while (y < piece->size_y)
	{
		x = 0;
		while (x < piece->size_x)
		{
			if (piece->piece[y][x] == '*')
				color_solve(e, x + solve->x, y + solve->y);
			x++;
		}
		y++;
	}
}

static void		color_visu_all(t_env *e, t_solve *solve, int piece_on_piece)
{
	int x;
	int y;

	y = 0;
	while (y < e->piece.size_y)
	{
		x = 0;
		while (x < e->piece.size_x)
		{
			if (e->piece.piece[y][x] == '*' && piece_on_piece == 0)
				color_solve(e, x + solve->x, y + solve->y);
			if (e->piece.piece[y][x] == '*' && piece_on_piece == 1)
				color_solve_ponp(e, x + solve->x, y + solve->y);
			x++;
		}
		y++;
	}
}

void			visu_all(t_env *e, t_piece *piece)
{
	t_list	*lst;
	t_solve	*solve;
	t_solve	*save;

	if (piece)
		;
	save = NULL;
	lst = e->lst;
	while (lst != NULL)
	{
		solve = lst->content;
		if (solve->nb == e->draw.check_sol)
			save = lst->content;
		else
			color_visu_all(e, solve, 0);
		lst = lst->next;
	}
	if (save)
		color_visu_all(e, save, 1);
}
