/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   strat_aggro.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ntoniolo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/10 21:16:58 by ntoniolo          #+#    #+#             */
/*   Updated: 2017/02/11 00:04:40 by ntoniolo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/filler.h"

static int	init_aggr(t_env *e, t_aggr *ar)
{
	e->strat = AGGRO;
	ar->opti = 50000;
	ar->res = 0;
	ar->mid = (e->map.size_y * e->map.size_x) / 2;
	ar->x = 500;
	ar->y = 500;
	return (1);
}

int			aggro(t_env *e)
{
	t_list	*lst;
	t_solve	*solve;
	t_aggr	ar;

	init_aggr(e, &ar);
	lst = e->lst;
	while (lst != NULL)
	{
		solve = lst->content;
		ar.res = ft_abs(((solve->y + (e->piece.size_y - e->piece.h)) *
		e->map.size_x) + (solve->x + (e->piece.size_x - e->piece.w)) - ar.mid);
		if (ar.res < ar.opti)
		{
			ar.opti = ar.res;
			ar.x = solve->x;
			ar.y = solve->y;
		}
		lst = lst->next;
	}
	if (ar.x == 500 || ar.y == 500)
		put_result(e, 0, 0);
	else
		put_result(e, ar.y, ar.x);
	return (1);
}
