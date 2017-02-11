/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   strat_envelop.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ntoniolo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/07 18:53:54 by ntoniolo          #+#    #+#             */
/*   Updated: 2017/02/11 00:04:58 by ntoniolo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/filler.h"

/*
** Compte le nombre de contact
** <>hb +=2
** diag +=1
*/

static int		verif_diag(t_env *e, t_solve *solve, int y, int x)
{
	int count;

	count = 0;
	if (solve->y + y + 1 < e->map.size_y && solve->x + x - 1 > 0)
	{
		if (env_vs_c(e, solve->y + y + 1, solve->x + x - 1) == 1)
			count += 1;
	}
	if (solve->y + y + 1 < e->map.size_y && solve->x + x + 1 <= e->map.size_x)
	{
		if (env_vs_c(e, solve->y + y + 1, solve->x + x + 1) == 1)
			count += 1;
	}
	if (solve->y + y - 1 > 0 && solve->x + x - 1 > 0)
	{
		if (env_vs_c(e, solve->y + y - 1, solve->x + x - 1) == 1)
			count += 1;
	}
	if (solve->y + y - 1 > 0 && solve->x + x + 1 <= e->map.size_x)
	{
		if (env_vs_c(e, solve->y + y - 1, solve->x + x + 1) == 1)
			count += 1;
	}
	return (count);
}

static int		verif_contact(t_env *e, t_solve *solve, int y, int x)
{
	int count;

	count = 0;
	if (solve->y + y + 1 < e->map.size_y - 1)
	{
		if (env_vs_c(e, solve->y + y + 1, solve->x + x) == 1)
			count += 2;
	}
	if (solve->y + y - 1 > 0)
	{
		if (env_vs_c(e, solve->y + y - 1, solve->x + x) == 1)
			count += 2;
	}
	if (solve->x + x + 1 < e->map.size_x - 1)
	{
		if (env_vs_c(e, solve->y + y, solve->x + x + 1) == 1)
			count += 2;
	}
	if (solve->x + x - 1 > 0)
	{
		if (env_vs_c(e, solve->y + y, solve->x + x - 1) == 1)
			count += 2;
	}
	count += verif_diag(e, solve, y, x);
	return (count);
}

static int		attache(t_env *e, t_solve *solve)
{
	int x;
	int y;
	int count;

	count = 0;
	y = 0;
	while (y < e->piece.size_y)
	{
		x = 0;
		while (x < e->piece.size_x)
		{
			if (e->piece.piece[y][x] == '*')
				count += verif_contact(e, solve, y, x);
			x++;
		}
		y++;
	}
	return (count);
}

static int		init_envel(t_envel *envel)
{
	envel->y = 500;
	envel->x = 500;
	envel->res = 0;
	envel->opti = 0;
	return (1);
}

int				envelop(t_env *e)
{
	t_list	*lst;
	t_solve *solve;
	t_envel	envel;

	init_envel(&envel);
	e->strat = ENVELOPE;
	lst = e->lst;
	while (lst != NULL)
	{
		envel.res = 0;
		solve = lst->content;
		envel.res = attache(e, solve);
		if (envel.res > envel.opti)
		{
			envel.opti = envel.res;
			envel.x = solve->x;
			envel.y = solve->y;
		}
		lst = lst->next;
	}
	if (envel.x == 500 || envel.y == 500)
		aggro(e);
	else
		put_result(e, envel.y, envel.x);
	return (1);
}
