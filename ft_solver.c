/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_solver.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbrella <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/23 14:45:00 by mbrella           #+#    #+#             */
/*   Updated: 2019/09/23 14:45:02 by mbrella          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_fillit.h"

int		ft_place_tetro(t_tetro *mas, char *field, int point, int sq)
{
	int		i;

	i = 0;
	while (i < 4)
	{
		if ((point % sq + mas->x[i]) >= sq  || (mas->y[i] * sq) >= (sq * sq) ||
			(point % sq + mas->x[i]) < 0 || (mas->y[i] * sq) < 0)
			return (0);
		if (field[point + mas->x[i] + (mas->y[i] * sq)] != '.')
			return (0);
		i++;
	}
	i = 0;
	while (i < 4)
	{
		if (field[point + mas->x[i] + (mas->y[i] * sq)] == '.')
			field[point + mas->x[i] + (mas->y[i] * sq)] = mas->letter;
		else
			return (0);
		i++;
	}
	if (i < 4)
		return (0);
	mas->isplaced = '\n';
	return (1);
}

int		ft_remove_tetro(t_tetro *mas, char *field, int point, int sq)
{
	int		i;

	i = 0;
	if (point + mas->x[3] + (mas->y[3] * sq) > (sq * sq))
		return (0);
	while (i < 4)
	{
		field[point + mas->x[i] + (mas->y[i] * sq)] = '.';
		i++;
	}
	if (i < 3)
		return (0);
	mas->isplaced = '\0';
	return (1);
}

int		ft_solve_tetro(t_tetro *mas, int sq, char *field)
{
	int		num;
	int		i;

	i = 0;
	num = 0;
	while (mas[num].isplaced == '\n' && mas[num].isactive == '\n')
		num++;
	if (mas[num].isactive != '\n')
		return (1);
	while (i < (int)ft_strlen(field))
	{
		if (ft_place_tetro(&mas[num], field, i, sq))
		{
			if (ft_solve_tetro(mas, sq, field))
				return (1);
			else
				ft_remove_tetro(&mas[num], field, i, sq);
		}
		i++;
	}
	return (0);
}

void	ft_make_tetro_field(t_tetro *mas)
{
	char	*field;
	int		num;
	int		i;
	int		sq;

	num = 0;
	while (mas[num].isactive == '\n')
		num++;
	sq = ft_possible_sqr(num * 4);
	field = (char *)malloc(sizeof(char) * (sq * sq));
	while (sq < 15)
	{
		i = 0;
		ft_strdel(&field);
		field = (char *)malloc(sizeof(char) * (sq * sq));
		while (i < (sq * sq))
		{
			field[i] = '.';
			i++;
		}
		if (ft_solve_tetro(mas, sq, field))
			break ;
		sq++;
	}
	ft_display_tetro(field, sq);
}

void	ft_display_tetro(char *field, int sq)
{
	int		x;

	x = 0;
	while (x < sq)
	{
		write(1, field, sq);
		write(1, "\n", 1);
		field += sq;
		x++;
	}
}
