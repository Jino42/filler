/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   strat_expend_y.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ntoniolo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/10 02:17:33 by ntoniolo          #+#    #+#             */
/*   Updated: 2017/02/10 23:41:11 by ntoniolo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/filler.h"

/*
** Regarde si devant son expend (Left/Right), il n'y a pas de vs_c
** Prends la solution la plus optimise
** ->le plus expend possbile (Left/Right)
** ->le plus au millieu possible
** -----------------------------------------------------------
** Des que son expend est un peu dev
*/

static int	nothing_y(t_env *e, int y1, int y2, int x)
{
	while (y1 < y2)
	{
		if (e->map.map[y1][x] == e->vs_c || e->map.map[y1][x] == e->vs_c - 32)
			return (0);
		y1++;
	}
	return (1);
}

static void	expend_up(t_env *e, t_expend *exp, t_list *lst, t_solve *solve)
{
	while (lst != NULL)
	{
		solve = lst->content;
		if (nothing_y(e, 0, solve->y + e->piece.start_y,
					solve->x + e->piece.start_x) == 1)
		{
			if (solve->y < exp->opti_min)
			{
				exp->opti_min = solve->y;
				exp->x = solve->x;
				exp->y = solve->y;
				exp->opti_other = ft_abs(solve->x - e->map.size_x / 2);
			}
			else if (solve->y == exp->opti_min &&
					ft_abs(solve->x - e->map.size_x / 2) < exp->opti_other)
			{
				exp->x = solve->x;
				exp->y = solve->y;
				exp->opti_other = ft_abs(solve->x - e->map.size_x / 2);
			}
		}
		lst = lst->next;
	}
	if (exp->y + (e->piece.start_y) == 0)
		e->colle_up = 1;
}

static void	expend_down(t_env *e, t_expend *exp, t_list *lst, t_solve *solve)
{
	while (lst != NULL)
	{
		solve = lst->content;
		if (nothing_y(e, solve->y + e->piece.start_y,
					e->map.size_y, solve->x + e->piece.start_x) == 1)
		{
			if (solve->y > exp->opti_max)
			{
				exp->opti_max = solve->y;
				exp->x = solve->x;
				exp->y = solve->y;
				exp->opti_other = ft_abs(solve->x - e->map.size_x / 2);
			}
			else if (solve->y == exp->opti_max &&
					ft_abs(solve->x - e->map.size_x / 2) < exp->opti_other)
			{
				exp->x = solve->x;
				exp->y = solve->y;
				exp->opti_other = ft_abs(solve->x - e->map.size_x / 2);
			}
		}
		lst = lst->next;
	}
	if (exp->y + e->piece.start_y + e->piece.h == e->map.size_y)
		e->colle_down = 1;
}

static int	init_expend(t_expend *exp)
{
	exp->opti_max = 0;
	exp->opti_min = 500;
	exp->opti_other = 500;
	exp->y = 500;
	exp->x = 500;
	return (1);
}

int			expend_y(t_env *e)
{
	t_list		*lst;
	t_solve		*solve;
	t_expend	exp;

	e->strat = EXPEND_Y;
	solve = NULL;
	init_expend(&exp);
	lst = e->lst;
	if (e->tic_y == 1 && e->colle_up == 0)
	{
		expend_up(e, &exp, lst, solve);
		if (e->colle_down == 0 && exp.y < e->map.size_y / 4)
			e->tic_y = 0;
	}
	else if (e->tic_y == 0 && e->colle_down == 0)
	{
		expend_down(e, &exp, lst, solve);
		if (e->colle_up == 0 && exp.y > e->map.size_y / 4)
			e->tic_y = 1;
	}
	if (exp.y == 500 || exp.x == 500)
		envelop(e);
	else
		put_result(e, exp.y, exp.x);
	return (1);
}
