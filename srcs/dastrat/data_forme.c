/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   data_forme.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ntoniolo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/07 15:43:54 by ntoniolo          #+#    #+#             */
/*   Updated: 2017/02/10 19:15:04 by ntoniolo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/filler.h"

/*
** run_map
** -------> check pour voir si il ce develope plus en axe X ou Y ou le contrer
*/

static void	forme_x(t_env *e, t_map *map, t_vs *vs)
{
	int y;
	int x;

	x = 0;
	while (x < map->size_x)
	{
		y = 0;
		while (y < map->size_y)
		{
			if (map->map[y][x] == e->vs_c || map->map[y][x] == e->vs_c - 32)
			{
				vs->forme_x++;
				y = e->map.size_y;
			}
			y++;
		}
		x++;
	}
}

static void	forme_y(t_env *e, t_map *map, t_vs *vs)
{
	int y;
	int x;

	y = 0;
	while (y < map->size_y)
	{
		x = 0;
		while (x < map->size_x)
		{
			if (map->map[y][x] == e->vs_c || map->map[y][x] == e->vs_c - 32)
			{
				vs->forme_y++;
				x = e->map.size_x;
			}
			x++;
		}
		y++;
	}
}

int			data_forme(t_env *e)
{
	forme_y(e, &e->map, &e->vs);
	forme_x(e, &e->map, &e->vs);
	return (1);
}
