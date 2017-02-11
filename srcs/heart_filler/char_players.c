/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   char_players.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ntoniolo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/10 16:21:24 by ntoniolo          #+#    #+#             */
/*   Updated: 2017/02/11 11:54:32 by ntoniolo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/filler.h"

int			env_player_c(t_env *e, int y, int x)
{
	if (e->map.map[y][x] == e->player_c || e->map.map[y][x] == 'N')
		return (1);
	return (0);
}

int			env_vs_c(t_env *e, int y, int x)
{
	if (e->map.map[y][x] == e->vs_c || e->map.map[y][x] == e->vs_c - 32)
		return (1);
	return (0);
}
