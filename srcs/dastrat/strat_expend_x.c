/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   strat_expend_x.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ntoniolo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/09 22:09:30 by ntoniolo          #+#    #+#             */
/*   Updated: 2017/02/10 21:20:28 by ntoniolo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/filler.h"

/*
** Regarde si devant son expend (Up/Down), il n'y a pas de vs_c
** Prends la solution la plus optimise
** ->le plus expend possbile (Up/Down)
** ->le plus au millieu possible
** -------------------------------------------------------------
** Des que son expend est un peu dev
*/

static int	nothing_x(t_env *e, int x1, int x2, int y)
{
	while (x1 <= x2)
	{
		if (e->map.map[y][x1] == e->vs_c || e->map.map[y][x1] == e->vs_c - 32)
			return (0);
		x1++;
	}
	return (1);
}

static void	expend_left(t_env *e, t_expend *exp, t_list *lst, t_solve *solve)
{
	while (lst != NULL)
	{
		solve = lst->content;
		if (nothing_x(e, 0, solve->x + e->piece.start_x,
					solve->y + e->piece.start_y) == 1)
		{
			if (solve->x < exp->opti_min)
			{
				exp->opti_min = solve->x;
				exp->x = solve->x;
				exp->y = solve->y;
				exp->opti_other = ft_abs(solve->y - e->map.size_y / 2);
			}
			else if (solve->x == exp->opti_min &&
					ft_abs(solve->y - e->map.size_y / 2) < exp->opti_other)
			{
				exp->x = solve->x;
				exp->y = solve->y;
				exp->opti_other = ft_abs(solve->y - e->map.size_y / 2);
			}
		}
		lst = lst->next;
	}
	if (exp->x + (e->piece.start_x) == 0)
		e->colle_left = 1;
}

static void	expend_right(t_env *e, t_expend *exp, t_list *lst, t_solve *solve)
{
	while (lst != NULL)
	{
		solve = lst->content;
		if (nothing_x(e, solve->x + e->piece.start_x,
					e->map.size_x, solve->y + e->piece.start_y) == 1)
		{
			if (solve->x > exp->opti_max)
			{
				exp->opti_max = solve->x;
				exp->x = solve->x;
				exp->y = solve->y;
				exp->opti_other = ft_abs(solve->y - e->map.size_y / 2);
			}
			else if (solve->x == exp->opti_max &&
					ft_abs(solve->y - e->map.size_y / 2) < exp->opti_other)
			{
				exp->x = solve->x;
				exp->y = solve->y;
				exp->opti_other = ft_abs(solve->y - e->map.size_y / 2);
			}
		}
		lst = lst->next;
	}
	if (exp->x + e->piece.start_x + e->piece.w == e->map.size_x)
		e->colle_right = 1;
}

static int	init_expend(t_expend *exp)
{
	exp->opti_max = 0;
	exp->opti_min = 500;
	exp->opti_other = 450;
	exp->y = 500;
	exp->x = 500;
	return (1);
}

int			expend_x(t_env *e)
{
	t_list		*lst;
	t_solve		*solve;
	t_expend	exp;

	e->strat = EXPEND_X;
	solve = NULL;
	init_expend(&exp);
	lst = e->lst;
	if (e->tic_x == 1 && e->colle_left == 0)
	{
		expend_left(e, &exp, lst, solve);
		if (e->colle_right == 0 && exp.x < e->map.size_x / 4)
			e->tic_x = 0;
	}
	else if (e->tic_x == 0 && e->colle_right == 0)
	{
		expend_right(e, &exp, lst, solve);
		if (e->colle_left == 0 && exp.x > e->map.size_x / 4 + e->map.size_x / 2)
			e->tic_x = 1;
	}
	if (exp.y == 500 || exp.x == 500)
		expend_y(e);
	else
		put_result(e, exp.y, exp.x);
	return (1);
}
