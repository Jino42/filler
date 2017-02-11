/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putwstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ntoniolo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/15 17:26:47 by ntoniolo          #+#    #+#             */
/*   Updated: 2017/01/15 17:27:14 by ntoniolo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/printf_fun.h"

void	ft_putwstr(wchar_t *str)
{
	int i;

	i = 0;
	while (str[i] != '\0')
	{
		ft_putwchar(str[i]);
		i++;
	}
}