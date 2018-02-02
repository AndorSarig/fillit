/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_put_to_array.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asarig <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/16 18:23:42 by asarig            #+#    #+#             */
/*   Updated: 2018/01/16 19:05:25 by asarig           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int		e_m(int *var)
{
	var[0] = 0;
	var[1] = 0;
	var[2] = 0;
	var[3] = 0;
	return (1);
}

char	**ft_put_to_array(char *f, int nrtetr)
{
	char	**pieces;
	int		var[4];

	if (!(pieces = (char**)malloc(sizeof(char*) * nrtetr + 1)) || e_m(var) != 1)
		return (NULL);
	pieces[nrtetr] = NULL;
	while (var[0] < nrtetr)
	{
		if (!(pieces[var[0]++] = (char*)malloc(sizeof(char) * 16 + 1)))
			return (NULL);
		pieces[var[0] - 1][16] = '\0';
	}
	while (f[var[2]] != '\0')
	{
		if (f[var[2]] == '\n')
			var[2]++;
		if (f[var[2]] == '\n' && f[var[2] - 1] == '\n')
		{
			var[2]++;
			var[3]++;
			var[1] = 0;
		}
		pieces[var[3]][var[1]++] = f[var[2]++];
	}
	return (pieces);
}
