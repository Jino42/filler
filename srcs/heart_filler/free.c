/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ntoniolo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/02 17:36:08 by ntoniolo          #+#    #+#             */
/*   Updated: 2017/02/10 04:40:36 by ntoniolo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/filler.h"

void	freelst(t_env *e)
{
	t_list	*lst;
	t_list	*lst_past;
	t_solve	*solve;

	lst = e->lst;
	lst_past = NULL;
	while (lst != NULL)
	{
		if (lst_past)
			free(lst_past);
		solve = lst->content;
		if (solve)
			free(solve);
		lst_past = lst;
		lst = lst->next;
	}
	e->lst = NULL;
	if (lst_past)
		free(lst_past);
}

int		free_piece(char **tab, t_env *e)
{
	int y;

	y = 0;
	if (tab == NULL || *tab == NULL)
		return (0);
	while (y < e->piece.size_y)
	{
		ft_strdel(&tab[y]);
		y++;
	}
	free(tab);
	tab = NULL;
	return (1);
}

int		free_map(char **tab, t_env *e)
{
	int y;

	y = 0;
	if (tab == NULL || *tab == NULL)
		return (0);
	while (y < e->map.size_y)
	{
		ft_strdel(&tab[y]);
		y++;
	}
	free(tab);
	tab = NULL;
	return (1);
}
