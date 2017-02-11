/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   can_place.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ntoniolo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/02 17:10:25 by ntoniolo          #+#    #+#             */
/*   Updated: 2017/02/10 16:40:03 by ntoniolo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/filler.h"

/*
** Run piece on map[y][x]
**							Can try over map.size_x & map.size_y
**							Cannot try under cause : bug exploit of vm_filler
**			| NO |
**		_	------ _
**			|    |
**		N	|    | Y
**		O	|    | E
**			|    | S
**		_	------ _
**			|YES |
*/

static int	can_try(int y, int x, t_env *e, int *count)
{
	int cur_x;
	int cur_y;

	if (y + e->piece.start_y + e->piece.h > e->map.size_y ||
			x + e->piece.start_x + e->piece.w > e->map.size_x)
		return (0);
	cur_y = 0;
	while (cur_y < e->piece.size_y)
	{
		cur_x = 0;
		while (cur_x < e->piece.size_x)
		{
			if (e->piece.piece[cur_y][cur_x] == '*')
			{
				if (env_player_c(e, y + cur_y, x + cur_x))
					*count += 1;
				else if (e->map.map[y + cur_y][x + cur_x] &&
						e->map.map[y + cur_y][x + cur_x] != '.')
					return (0);
			}
			cur_x++;
		}
		cur_y++;
	}
	return (1);
}

int			can_place(t_env *e, int y, int x)
{
	int count;

	count = 0;
	if (can_try(y, x, e, &count) == 0)
		return (0);
	if (count == 0 || count > 1)
		return (0);
	return (1);
}
