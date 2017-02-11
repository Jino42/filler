/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solution.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ntoniolo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/02 16:55:54 by ntoniolo          #+#    #+#             */
/*   Updated: 2017/02/11 00:23:22 by ntoniolo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/filler.h"

/*
** Parcour map[][]
** test chaque solution
** Si can_place() == 1;
** solution stocke dans une liste
*/

static int	init_solve(t_solve *solve)
{
	solve->nb = 0;
	solve->y = 0;
	solve->x = 0;
	solve->po = 0;
	return (1);
}

static int	stock_solution(t_env *e, int y, int x)
{
	t_solve	solve;

	init_solve(&solve);
	e->nb_solve++;
	solve.nb = e->nb_solve;
	solve.x = x;
	solve.y = y;
	ft_lstinsert(&e->lst, ft_lstnew(&solve, sizeof(solve)));
	return (1);
}

static int	loop_solution(t_env *e, t_map *map)
{
	int x;
	int y;
	int sortie;

	e->nb_solve = 0;
	sortie = 1;
	y = 0;
	while (y < map->size_y)
	{
		x = 0;
		while (x < map->size_x)
		{
			if (map->map[y][x] != e->vs_c || map->map[y][x] != e->vs_c - 32)
			{
				if (can_place(e, y, x) == 1)
				{
					sortie = 0;
					stock_solution(e, y, x);
				}
			}
			x++;
		}
		y++;
	}
	return (sortie);
}

int			solution(t_map *map, t_env *e)
{
	if (loop_solution(e, map) == 1)
	{
		put_result(e, 0, 0);
		return (-2);
	}
	if (e->strat == AGGRO)
		aggro(e);
	else if (e->strat == EXPEND_X)
		expend_x(e);
	else if (e->strat == EXPEND_Y)
		expend_y(e);
	else if (e->strat == ENVELOPE)
		envelop(e);
	return (1);
}
