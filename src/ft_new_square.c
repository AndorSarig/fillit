/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_new_square.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asarig <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/16 18:19:31 by asarig            #+#    #+#             */
/*   Updated: 2018/01/16 19:06:24 by asarig           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

char	**ft_new_square(int size)
{
	int		i;
	int		j;
	char	**sqr;

	i = 0;
	j = 0;
	if (!(sqr = (char**)malloc(sizeof(char*) * size + 1)))
		return (NULL);
	sqr[size] = NULL;
	while (i < size)
	{
		if (!(sqr[i] = (char*)malloc(sizeof(char) * size + 1)))
			return (NULL);
		sqr[i++][size] = '\0';
	}
	i = 0;
	while (i < size)
	{
		while (j < size)
			sqr[i][j++] = '.';
		sqr[i++][j] = '\0';
		j = 0;
	}
	return (sqr);
}
