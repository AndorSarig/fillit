/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_hash_to_alpha.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asarig <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/16 18:18:07 by asarig            #+#    #+#             */
/*   Updated: 2018/01/16 18:18:11 by asarig           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

char	**ft_hash_to_alph(char **tetri, int nrtetr)
{
	int i;
	int j;

	i = 0;
	j = 0;
	while (i < nrtetr)
	{
		while (j < 16)
		{
			if (tetri[i][j] != '.')
				tetri[i][j] = 'A' + i;
			j++;
		}
		j = 0;
		i++;
	}
	return (tetri);
}
