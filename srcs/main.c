/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ntoniolo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/19 14:10:25 by ntoniolo          #+#    #+#             */
/*   Updated: 2017/02/11 13:39:36 by ntoniolo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/filler.h"

void		put_result(t_env *e, int y, int x)
{
	e->res_y = y;
	e->res_x = x;
	ft_putnbr(y);
	ft_putstr(" ");
	ft_putnbr(x);
	ft_putstr("\n");
}

static void	init_heart(t_env *e)
{
	e->draw.dir_value = 0.05;
	e->draw.check_sol = 0;
	e->w8 = 0;
	e->lst = NULL;
	e->lst_past = NULL;
	e->map_past = NULL;
	e->piece.piece = NULL;
	e->piece_past = NULL;
	e->nb = 0;
	e->strat = 0;
	e->first_f = 1;
	e->one_up = 0;
	e->colle_left = 0;
	e->colle_right = 0;
	e->colle_up = 0;
	e->colle_down = 0;
	e->size_seg_x = 0;
	e->size_seg_y = 0;
	e->tic_x = 0;
	e->tic_y = 0;
}

int			main(void)
{
	t_env	e;

	init_heart(&e);
	e.mlx = mlx_init();
	e.img = mlxji_new_img(&e, WIN_W, WIN_H);
	e.win = mlx_new_window(e.mlx, WIN_W, WIN_H, "Filler");
	if (mlx_loop_hook(e.mlx, &loop_filler, &e) == -2)
	{
		exit(-1);
		return (0);
	}
	mlx_key_hook(e.win, &key_event_take_off, &e);
	mlx_hook(e.win, 2, 0, &key_event_press, &e);
	mlx_loop(e.mlx);
	return (0);
}
