/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   place.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ntoniolo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/07 15:28:42 by ntoniolo          #+#    #+#             */
/*   Updated: 2017/02/10 21:34:47 by ntoniolo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** Data -> PLACE
** 			aggro_strat
*/

#include "../../includes/filler.h"

static void	find_place_x(t_env *e, t_vs *vs, t_map *map)
{
	int	y;
	int	x;

	x = 0;
	while (x < map->size_x)
	{
		y = 0;
		while (y < map->size_y)
		{
			if (map->map[y][x] == e->vs_c - 32)
			{
				vs->place_x = x;
				x = map->size_x;
				y = map->size_y;
			}
			y++;
		}
		x++;
	}
}

static void	find_place_y(t_env *e, t_vs *vs, t_map *map)
{
	int	y;
	int	x;

	y = 0;
	while (y < map->size_y)
	{
		x = 0;
		while (x < map->size_x)
		{
			if (map->map[y][x] == e->vs_c - 32)
			{
				vs->place_y = y;
				x = map->size_x;
				y = map->size_y;
			}
			x++;
		}
		y++;
	}
}

int			data_place(t_env *e, t_vs *vs)
{
	find_place_y(e, vs, &e->map);
	find_place_x(e, vs, &e->map);
	return (1);
}
