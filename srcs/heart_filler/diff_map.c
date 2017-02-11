/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   diff_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ntoniolo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/23 16:06:40 by ntoniolo          #+#    #+#             */
/*   Updated: 2017/02/10 18:51:08 by ntoniolo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/filler.h"

/*
**Change data of map[][] for make strat or visual
*/

int			diff_map(t_map *map, t_env *e)
{
	int x;
	int y;

	y = 0;
	while (y < map->size_y)
	{
		x = 0;
		while (x < map->size_x)
		{
			if ((map->map[y][x] == e->vs_c || map->map[y][x] == e->vs_c - 32)
					&& e->map_past[y][x] == '.')
				map->map[y][x] = e->vs_c - 32;
			if (map->map[y][x] == e->player_c && e->map_past[y][x] == '.')
				map->map[y][x] = 'N';
			x++;
		}
		y++;
	}
	return (1);
}
