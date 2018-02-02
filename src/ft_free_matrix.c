/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free_matrix.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asarig <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/16 18:19:21 by asarig            #+#    #+#             */
/*   Updated: 2018/01/16 18:19:25 by asarig           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void	ft_free_matrix(char **tetris)
{
	int i;
	int j;

	j = 0;
	i = ft_measure(tetris);
	while (j < i)
	{
		free(tetris[j]);
		j++;
	}
	free(tetris);
}
