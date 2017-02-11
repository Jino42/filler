/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   run_map.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ntoniolo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/22 16:53:55 by ntoniolo          #+#    #+#             */
/*   Updated: 2017/02/11 13:40:02 by ntoniolo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/filler.h"

static int		init_vs(t_vs *vs)
{
	vs->place_x = 0;
	vs->place_y = 0;
	vs->forme_x = 0;
	vs->forme_y = 0;
	return (1);
}

static void		vs_dev_y(t_env *e)
{
	if (((e->colle_right == 0 || e->colle_left == 0)) && (e->piece.w > 1))
		e->strat = EXPEND_X;
	else if (((e->colle_down == 0 || e->colle_up == 0)) && (e->piece.h > 1))
		e->strat = EXPEND_Y;
	else if (e->colle_down == 1 && e->colle_up == 1
			&& e->colle_right == 1 && e->colle_left == 1)
		e->strat = ENVELOPE;
	else
		e->strat = ENVELOPE;
}

static void		vs_dev_x(t_env *e)
{
	if (((e->colle_down == 0 || e->colle_up == 0)) && (e->piece.h > 1))
		e->strat = EXPEND_Y;
	else if (((e->colle_right == 0 || e->colle_left == 0)) && (e->piece.w > 1))
		e->strat = EXPEND_X;
	else if (e->colle_down == 1 && e->colle_up == 1
			&& e->colle_right == 1 && e->colle_left == 1)
		e->strat = ENVELOPE;
	else
		e->strat = ENVELOPE;
}

int				run_dastrat(t_env *e, t_vs *vs)
{
	init_vs(vs);
	data_place(e, vs);
	data_forme(e);
	if (e->manuel == 0)
	{
		if (e->vs.forme_x < e->vs.forme_y * 1.2)
			vs_dev_y(e);
		else
			vs_dev_x(e);
	}
	return (1);
}
