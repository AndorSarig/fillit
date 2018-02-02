/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_resolve.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asarig <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/16 18:20:44 by asarig            #+#    #+#             */
/*   Updated: 2018/01/16 18:48:49 by asarig           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int		ft_check_place(char **tetris, char *piece, int x, int y)
{
	int		dots;
	int		size;
	int		i;

	size = ft_measure(tetris);
	dots = ft_dot(piece);
	i = dots;
	while (piece[i] != '\0')
	{
		if (piece[i] != '.')
		{
			if ((y + (i / 4) - (dots / 4) >= size) ||
					(x + (i % 4) - (dots % 4) >= size) ||
					tetris[y + (i / 4) - (dots / 4)][x + (i % 4)
					- (dots % 4)] != '.')
				return (1);
		}
		i++;
	}
	return (0);
}

char	**ft_put_to_tetris(char **tetris, char *piece, int x, int y)
{
	int		i;
	int		dots;

	i = ft_dot(piece);
	dots = i;
	while (piece[i] != '\0')
	{
		if (piece[i] != '.')
			tetris[y + (i / 4) - (dots / 4)][x + (i % 4)
				- (dots % 4)] = piece[i];
		i++;
	}
	return (tetris);
}

int		ft_put_in_pieces(char **tetris, char **pieces, int i)
{
	int		x;
	int		y;
	char	*current;

	if (!pieces[i])
		return (1);
	y = -1;
	current = pieces[i];
	while (++y < ft_measure(tetris))
	{
		x = -1;
		while (++x < ft_measure(tetris))
		{
			if (ft_check_place(tetris, current, x, y) == 0)
			{
				tetris = ft_put_to_tetris(tetris, current, x, y);
				if (ft_put_in_pieces(tetris, pieces, i + 1) == 1)
					return (1);
				else
					ft_take_piece_off(tetris, current);
			}
		}
	}
	return (0);
}

char	**ft_resolve(char **tetriminos, int nrtetr)
{
	char	**solution;
	int		size;

	size = ft_size(nrtetr);
	solution = ft_new_square(size);
	while (ft_put_in_pieces(solution, tetriminos, 0) == 0)
	{
		size++;
		ft_free_matrix(solution);
		solution = ft_new_square(size);
	}
	return (solution);
}
