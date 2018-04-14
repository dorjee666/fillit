/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dphuntso <dphuntso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/09 21:45:13 by dphuntso          #+#    #+#             */
/*   Updated: 2018/03/25 15:21:59 by dphuntso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLIT_H
# define FILLIT_H

# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>

typedef	struct			s_tetris
{
	int					flag;
	int					pnt1[2];
	int					pnt2[2];
	int					pnt3[2];
	int					pnt4[2];
	char				ch;
	struct s_tetris		*next;
}						t_tetris;

int						hash(char ch);

char					*read_file(int fd);

size_t					ft_strlen(char *str);

int						count_hash(char *str);

void					print_map(char **map);

int						final_valid(char *str);

char					*valid_input(char *str);

void					print_square(char	*the_square);

int						four(char ch1, char ch2, char ch3, char ch4);

t_tetris				*guard_int(t_tetris *t);

int						tetris_left(t_tetris *tet);

t_tetris				*get_a_tetris(t_tetris *tet);

t_tetris				*get_tetris(t_tetris *tet, char *str);

char					**solve_square(t_tetris *tet);

int						solve_board(char **map, t_tetris *tet, int n);

char					**reverse_board(char **old, t_tetris *tet, int n);

void					clear_board(char **baord, int n);

int						board_size(t_tetris *tet);

void					rel_pos(t_tetris *t, int pnt[2], int x, int y);

int						check(char **board, int x, int y, t_tetris *tet);

#endif
