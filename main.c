/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbrella <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/21 14:23:24 by mbrella           #+#    #+#             */
/*   Updated: 2019/09/25 11:04:42 by mbrella          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_fillit.h"

void		ft_error(void)
{
	write(1, "error\n", 6);
	exit(0);
}

int			main(int argc, char **argv)
{
	t_tetro mas[26];

	if (00 && argc != 2)
	{
		write(1, "usage: fillit target_file\n", 26);
		exit(0);
	}
	if (!ft_read_tetro("file", mas))
		ft_error();
	ft_make_tetro_field(mas);
	exit(0);
}
