/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fillit.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbrella <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/21 14:27:24 by mbrella           #+#    #+#             */
/*   Updated: 2019/09/25 09:40:02 by mbrella          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_FILLIT_H
# define FT_FILLIT_H

# include <stdio.h>
# include <fcntl.h>
# include <stdlib.h>
# include <zconf.h>
# include "libft/libft.h"
# define BUFF_SIZE 8000000
# define MAXTETROS 26
# define TETROSIZE 20

typedef	struct	s_tetro
{
	char		isactive;
	char		isplaced;
	char		letter;
	int			x[4];
	int			y[4];
}				t_tetro;

int				ft_abs(int x);
void			ft_dop_mas(t_tetro *mas, int cn, int x, int y);
int				ft_possible_sqr(int n);
int				ft_read_tetro();
int				ft_remove_tetro(t_tetro *mas, char *field, int point, int sq);
int				ft_check_tetro(char *tet, int num, t_tetro *mas);
int				ft_make_tetro(char *tet, t_tetro *mas);
void			ft_error(void);
void			ft_make_tetro_field(t_tetro *mas);
int				ft_solve_tetro(t_tetro *mas, int sq, char *field);
int				ft_place_tetro(t_tetro *mas, char *field, int point, int sq);
int				ft_check_sell(t_tetro *mas);
void			ft_display_tetro(char *field, int sq);
int				ft_check_tetro(char *tet, int num, t_tetro *mas);
int				ft_check_sq(char *field);
int				ft_dop_make_tetro(t_tetro *mas, int *n,
						char *tet, int *cn);
int				ft_read_tetro(char *file, t_tetro *mas);

#endif
