/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pars.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ntoniolo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/22 15:25:09 by ntoniolo          #+#    #+#             */
/*   Updated: 2017/02/10 04:41:30 by ntoniolo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/filler.h"

static int	loop_pars_map(t_map *map, int i, char *line)
{
	int j;

	j = 0;
	if (get_next_line(0, &line) == -1)
		return (0);
	j = 0;
	while (ft_isdigit(line[j]) || line[j] == ' ')
		j++;
	map->map[i] = ft_strsub(line, j, ft_strlen(line) - j);
	ft_strdel(&line);
	return (1);
}

static int	pars_map(t_map *map, char *line)
{
	char	*chr;
	int		i;

	chr = ft_strchr(line, ' ');
	map->size_y += ft_atoi(&line[chr - line]);
	chr = ft_strrchr(line, ' ');
	map->size_x += ft_atoi(&line[chr - line]);
	map->map = (char**)malloc(sizeof(char*) * map->size_y);
	if (map->map == NULL)
		return (0);
	if (line)
		ft_strdel(&line);
	if (get_next_line(0, &line) == -1)
		return (0);
	if (line)
		ft_strdel(&line);
	i = 0;
	while (i < map->size_y)
	{
		if (loop_pars_map(map, i, line) == 0)
			return (0);
		i++;
	}
	return (1);
}

static int	pars_piece(t_piece *piece, char *line)
{
	char	*chr;
	int		i;

	chr = ft_strchr(line, ' ');
	piece->size_y += ft_atoi(&line[chr - line]);
	chr = ft_strrchr(line, ' ');
	piece->size_x += ft_atoi(&line[chr - line]);
	piece->piece = (char**)malloc(sizeof(char*) * piece->size_y);
	if (piece->piece == NULL)
		return (0);
	i = 0;
	if (line)
		ft_strdel(&line);
	while (i < piece->size_y)
	{
		if (get_next_line(0, &line) == -1)
			return (0);
		piece->piece[i] = line;
		i++;
	}
	return (1);
}

static int	player(t_env *e, char *line)
{
	e->player = ft_atoi(ft_strchr(line, 'p') + 1);
	if (e->player == 1)
	{
		e->player_c = 'O';
		e->vs_c = 'X';
	}
	else if (e->player == 2)
	{
		e->player_c = 'X';
		e->vs_c = 'O';
	}
	return (1);
}

int			parsing(t_map *map, t_piece *piece, t_env *e)
{
	char *line;

	line = NULL;
	if (get_next_line(0, &line) == -1)
		return (0);
	if (ft_strstr(line, "exec") != NULL)
	{
		player(e, line);
		ft_strdel(&line);
		get_next_line(0, &line);
	}
	if (pars_map(map, line) <= 0)
		return (0);
	get_next_line(0, &line);
	if (pars_piece(piece, line) <= 0)
		return (0);
	return (1);
}
