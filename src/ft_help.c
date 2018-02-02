/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_help.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asarig <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/16 18:16:39 by asarig            #+#    #+#             */
/*   Updated: 2018/01/16 19:49:25 by asarig           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int		ft_size(int nrtetr)
{
	int		i;
	int		size;

	i = 2;
	size = nrtetr * 4;
	while (i * i < size)
		i++;
	return (i);
}

int		ft_measure(char **tetris)
{
	int		i;

	i = 0;
	while (tetris[i] != '\0')
	{
		i++;
	}
	return (i);
}

int		ft_dot(char *piece)
{
	int		i;

	i = 0;
	while (piece[i] == '.')
		i++;
	return (i);
}

char	**ft_take_piece_off(char **tetris, char *piece)
{
	int		i;
	int		j;
	char	c;

	i = 0;
	j = 0;
	c = piece[ft_dot(piece)];
	while (tetris[i] != '\0')
	{
		while (tetris[j] != '\0')
		{
			if (tetris[i][j] == c)
				tetris[i][j] = '.';
			j++;
		}
		j = 0;
		i++;
	}
	return (tetris);
}

void	error(void)
{
	ft_putendl("error");
	exit(EXIT_FAILURE);
}
