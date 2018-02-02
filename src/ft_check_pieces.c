/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_pieces.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asarig <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/16 18:20:08 by asarig            #+#    #+#             */
/*   Updated: 2018/01/22 19:48:12 by rbudai           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int	ft_isok2(char *piece, int i)
{
	if (*(piece + 2) == '#' && *(piece + 3) == '#'
			&& *(piece + 4) == '#' && i >= 2)
		return (0);
	else if (*(piece + 3) == '#' && *(piece + 4) == '#')
	{
		if ((*(piece + 5) == '#' || *(piece + 7) == '#' ||
				*(piece + 8) == '#') && i >= 1)
			return (0);
	}
	else if (*(piece + 4) == '#' && *(piece + 5) == '#')
	{
		if (*(piece + 6) == '#' || *(piece + 8) == '#' ||
				*(piece + 9) == '#')
			return (0);
	}
	else if (*(piece + 4) == '#')
	{
		if (*(piece + 7) == '#' && *(piece + 8) == '#' && i >= 1)
			return (0);
		else if (*(piece + 8) == '#' && (*(piece + 9) == '#' ||
					*(piece + 12) == '#'))
			return (0);
	}
	return (1);
}

int	ft_isok(char *piece, int i)
{
	if (*(piece + 1) == '#')
	{
		if (*(piece + 2) == '#')
		{
			if (*(piece + 3) == '#' || *(piece + 4) == '#' ||
					*(piece + 5) == '#' || *(piece + 6) == '#')
				return (0);
		}
		else if (*(piece + 3) == '#' && *(piece + 4) == '#' && i >= 1)
			return (0);
		else if (*(piece + 4) == '#' && (*(piece + 5) == '#' ||
					*(piece + 8) == '#'))
			return (0);
		else if (*(piece + 5) == '#' && (*(piece + 6) == '#' ||
					*(piece + 9) == '#'))
			return (0);
	}
	if (ft_isok2(piece, i) == 0)
		return (0);
	return (1);
}

int	ft_start_current(char *piece)
{
	int i;

	i = 0;
	while (piece[i] != '#')
		i++;
	if (ft_isok(piece + i, i) == 0)
		return (0);
	else
		return (1);
}

int	ft_check_pieces(char **array, int nr)
{
	int i;

	i = 0;
	while (i < nr)
	{
		if (ft_start_current(array[i]) == 1)
			return (1);
		i++;
	}
	return (0);
}
