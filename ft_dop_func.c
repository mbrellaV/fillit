/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dop_func.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbrella <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/25 08:50:11 by mbrella           #+#    #+#             */
/*   Updated: 2019/09/25 08:50:15 by mbrella          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_fillit.h"

int		ft_possible_sqr(int n)
{
	int i;

	i = 0;
	while ((i * i) < n)
	{
		i++;
	}
	return (i);
}

int		ft_abs(int x)
{
	if (x < 0)
		return (-x);
	return (x);
}

void	ft_dop_mas(t_tetro *mas, int cn, int x, int y)
{
	mas->x[cn] = x;
	mas->y[cn] = y;
}
