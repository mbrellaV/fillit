/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbrella <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/21 14:32:16 by mbrella           #+#    #+#             */
/*   Updated: 2019/09/21 14:32:18 by mbrella          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_fillit.h"

int		ft_check_tetro(char *tet, int num, t_tetro *mas)
{
	if (ft_strlen(tet) == TETROSIZE || ft_strlen(tet) == TETROSIZE - 1)
	{
		ft_make_tetro(tet, mas);
		mas->x[0] = 0;
		mas->y[0] = 0;
		mas->letter = num + 'A';
		mas->isactive = '\n';
		return (1);
	}
	ft_error();
	return (0);
}

int		ft_check_sq(char *field)
{
	int count;
	int i;

	count = 0;
	i = 0;
	while (i < 20)
	{
		if (field[i] == '#')
		{
			if ((i + 1) < 20 && field[i + 1] == '#')
				count++;
			if ((i - 1) >= 0 && field[i - 1] == '#')
				count++;
			if ((i + 5) < 20 && field[i + 5] == '#')
				count++;
			if ((i - 5) >= 0 && field[i - 5] == '#')
				count++;
		}
		i++;
	}
	return (count == 6 || count == 8);
}

int		ft_dop_make_tetro(t_tetro *mas, int *n,
				char *tet, int *cn)
{
	int i;

	i = 0;
	while (tet[i])
	{
		if ((i == (*n * 5) - 1) && tet[i] == '\n')
		{
			(*n)++;
			i++;
			if (i == TETROSIZE)
				break ;
		}
		else if ((i == ((*n * 5) - 1)) && tet[i] != '\n')
			ft_error();
		if (tet[i] != '#' && tet[i] != '.' && tet[i] != '\n')
			ft_error();
		if (tet[i] == '#' && *cn == 0)
			ft_dop_mas(mas, (*cn)++, i % 5, i / 5);
		else if (tet[i] == '#' && *cn > 0)
			ft_dop_mas(mas, (*cn)++, (i % 5) - mas->x[0], (i / 5) - mas->y[0]);
		i++;
	}
	return (i);
}

int		ft_make_tetro(char *tet, t_tetro *mas)
{
	int				n;
	int				cn;
	int				i;

	n = 1;
	cn = 0;
	i = ft_dop_make_tetro(mas, &n, tet, &cn);
	if (!ft_check_sq(tet))
		ft_error();
	if ((i < 19 || i > 20) || (n < 4 || n > 5) || cn != 4)
		ft_error();
	return (1);
}

int		ft_read_tetro(char *file, t_tetro *mas)
{
	int		fd;
	char	line[BUFF_SIZE];
	int		size;
	int		num;
	int		index;

	index = 0;
	fd = open(file, 'r');
	size = read(fd, line, BUFF_SIZE);
	printf("size: %d", (int)size);
	num = 0;
	line[size] = '\0';
	while (num < MAXTETROS)
	{
		if (line[index] == '\0' && index != 0)
			break ;
		if (line[index] != '\n' && index != 0)
			ft_error();
		if (index != 0)
			index++;
		ft_check_tetro(ft_strsub(line, index, TETROSIZE), num, &mas[num]);
		index += TETROSIZE;
		num++;
	}
	return (1);
}
