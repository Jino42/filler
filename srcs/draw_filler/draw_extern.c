/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_extern.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ntoniolo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/30 21:09:04 by ntoniolo          #+#    #+#             */
/*   Updated: 2017/02/10 23:48:43 by ntoniolo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/filler.h"

static void	put_strat(t_env *e)
{
	if (e->strat == AGGRO)
		ft_putstr_fd("Aggro (Beta)", 2);
	if (e->strat == EXPEND_X)
		ft_putstr_fd("Expend_x", 2);
	if (e->strat == EXPEND_Y)
		ft_putstr_fd("Expend_y", 2);
	if (e->strat == ENVELOPE)
		ft_putstr_fd("Envlope\033[0m", 2);
}

static void	print_extern_info(t_env *e, t_solve *solve)
{
	t_draw	*draw;

	draw = &e->draw;
	ft_putstr_fd("\033[31m\033[1mSolution\033[0m\033[31m : \033[0m", 2);
	ft_putnbr_fd(draw->check_sol, 2);
	ft_putstr_fd("\033[31m/\033[0m", 2);
	ft_putnbr_fd(e->nb_solve, 2);
	ft_putstr_fd("\n", 2);
	ft_putstr_fd("\033[32m\033[1mRes\033[0m\033[32m      : [\033[0m", 2);
	ft_putnbr_fd(solve->y, 2);
	ft_putstr_fd("\033[32m] [\033[0m", 2);
	ft_putnbr_fd(solve->x, 2);
	ft_putstr_fd("\033[32m]\033[0m\n", 2);
	ft_putstr_fd("\033[33m\033[1mStrat\033[0m\033[33m    : \033[0m", 2);
	put_strat(e);
	ft_putstr_fd("\033[0m\n\n", 2);
}

void		extern_info(t_env *e)
{
	t_list	*lst;
	t_solve	*solve;

	lst = e->lst;
	while (lst != NULL)
	{
		solve = lst->content;
		if (solve->nb == e->draw.check_sol)
			break ;
		lst = lst->next;
	}
	print_extern_info(e, solve);
}
