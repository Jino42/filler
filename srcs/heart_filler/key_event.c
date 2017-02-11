/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_event.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ntoniolo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/11 11:37:42 by ntoniolo          #+#    #+#             */
/*   Updated: 2017/02/11 11:51:26 by ntoniolo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/filler.h"

static int	key_manuel(int keycode, t_env *e)
{
	if (keycode == 76)
	{
		if (e->manuel == 0)
			e->manuel = 1;
		else if (e->manuel == 1)
			e->manuel = 0;
	}
	if (e->manuel == 1)
	{
		if (keycode == 83)
			e->strat = 1;
		if (keycode == 84)
			e->strat = 4;
		if (keycode == 86)
			e->strat = 2;
		if (keycode == 91)
			e->strat = 3;
	}
	return (1);
}

int			key_event_press(int keycode, t_env *e)
{
	if (keycode == 53)
		exit(0);
	if (keycode == 18)
		e->w8 = 1;
	if (keycode == 19)
		e->w8 = 0;
	key_manuel(keycode, e);
	if (keycode == 78)
		if (e->draw.check_sol < e->nb_solve)
			e->draw.check_sol++;
	if (keycode == 69)
		if (e->draw.check_sol > 1)
			e->draw.check_sol--;
	if (keycode == 49)
		e->one_up = 1;
	if (keycode)
		e->key[keycode] = 1;
	return (1);
}

int			key_event_take_off(int keycode, t_env *e)
{
	if (keycode)
		e->key[keycode] = 0;
	return (0);
}
