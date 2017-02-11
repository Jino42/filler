/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   limit_piece.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ntoniolo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/30 20:29:43 by ntoniolo          #+#    #+#             */
/*   Updated: 2017/02/10 04:41:21 by ntoniolo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/filler.h"

static void	run_horizon(t_piece *piece)
{
	int y;
	int x;
	int sortie;

	sortie = 0;
	y = 0;
	while (y < piece->size_y)
	{
		x = 0;
		while (x < piece->size_x)
		{
			if (piece->piece[y][x] == '*' && sortie == 0)
			{
				piece->start_x = x;
				sortie = 1;
			}
			if (piece->piece[y][x] == '*')
			{
				piece->h++;
				x = piece->size_x;
			}
			x++;
		}
		y++;
	}
}

static void	run_vertical(t_piece *piece)
{
	int y;
	int x;
	int sortie;

	x = 0;
	sortie = 0;
	while (x < piece->size_x)
	{
		y = 0;
		while (y < piece->size_y)
		{
			if (piece->piece[y][x] == '*' && sortie == 0)
			{
				piece->start_y = y;
				sortie = 1;
			}
			if (piece->piece[y][x] == '*')
			{
				piece->w++;
				y = piece->size_y;
			}
			y++;
		}
		x++;
	}
}

int			limit_piece(t_piece *piece)
{
	run_horizon(piece);
	run_vertical(piece);
	return (1);
}
