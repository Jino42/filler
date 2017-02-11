/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_case.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ntoniolo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/30 21:19:18 by ntoniolo          #+#    #+#             */
/*   Updated: 2017/02/10 04:38:53 by ntoniolo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/filler.h"

void	draw_case(t_env *e)
{
	t_pxtopx	*pxtopx;
	t_px		*px;
	int			save_x1;

	px = &e->draw.px;
	pxtopx = &e->draw.pxtopx;
	save_x1 = pxtopx->x1;
	while (pxtopx->y1 < pxtopx->y2)
	{
		pxtopx->x1 = save_x1;
		while (pxtopx->x1 < pxtopx->x2)
		{
			mlxji_put_pixel(e->img, pxtopx->x1, pxtopx->y1, px);
			pxtopx->x1++;
		}
		pxtopx->y1++;
	}
}
