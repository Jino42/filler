/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   loop_filler.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ntoniolo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/02 17:34:50 by ntoniolo          #+#    #+#             */
/*   Updated: 2017/02/11 11:59:42 by ntoniolo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/filler.h"

/*
** 2 visual modes
** --------------
** 0 : draw_map en temps reel
** 1 : pause pour etudier les stratiegies, et autres
**
**	PS : Draw map[][] apres avoir trouve la solution
*/

static int	init_alteration(t_map *map, t_piece *piece, t_env *e)
{
	e->draw.check_past = 0;
	e->draw.check_sol = 1;
	e->draw.value = 0.55;
	e->draw.hue = 30;
	e->draw.saturation = 1;
	e->nb_solve = 0;
	map->map = NULL;
	map->size_x = 0;
	map->size_y = 0;
	piece->piece = NULL;
	piece->size_x = 0;
	piece->size_y = 0;
	piece->h = 0;
	piece->w = 0;
	piece->start_y = 0;
	piece->start_x = 0;
	return (1);
}

static int	first_f(t_env *e)
{
	int y;
	int x;

	y = 0;
	while (y < e->map.size_y)
	{
		x = 0;
		while (x < e->map.size_x)
		{
			if (e->map.map[y][x] == e->player_c)
			{
				if (y > e->map.size_y / 2)
					e->tic_y = 1;
				if (x > e->map.size_x / 2)
					e->tic_x = 1;
				x = e->map.size_x;
				y = e->map.size_y;
			}
			x++;
		}
		y++;
	}
	e->first_f = 0;
	return (1);
}

static void	one_turn(t_env *e)
{
	free_piece(e->piece.piece, e);
	e->nb++;
	if (e->lst)
		freelst(e);
	init_alteration(&e->map, &e->piece, e);
	if (parsing(&e->map, &e->piece, e) == 0)
		exit(-1);
	if (e->map_past)
		diff_map(&e->map, e);
	limit_piece(&e->piece);
	if (e->first_f)
		first_f(e);
	run_dastrat(e, &e->vs);
	if (solution(&e->map, e) == -2)
		exit(-1);
	mlxji_clear_img(e->img);
	visu(e);
	mlx_put_image_to_window(e->mlx, e->win, e->img->img, 0, 0);
	free_map(e->map_past, e);
	e->map_past = e->map.map;
}

int			loop_filler(t_env *e)
{
	if (e->w8 == 1)
	{
		mlxji_clear_img(e->img);
		visu(e);
		mlx_put_image_to_window(e->mlx, e->win, e->img->img, 0, 0);
		if (e->one_up)
			e->w8 = 0;
	}
	if (e->w8 == 0)
	{
		if (e->one_up)
		{
			e->w8 = 1;
			e->one_up = 0;
		}
		one_turn(e);
	}
	return (1);
}
