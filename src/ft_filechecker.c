/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_filechecker.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asarig <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/16 18:02:17 by asarig            #+#    #+#             */
/*   Updated: 2018/01/21 14:26:54 by asarig           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void	e_m3(int *var)
{
	var[1] = 0;
	var[2] = 0;
	var[3]++;
}

void	e_m2(int *var)
{
	var[0] = 0;
	e_m3(var);
	var[3] = 0;
}

int		aux_fug(char *file, int *var)
{
	if (file[var[0]] == '\n' && var[2] == 0 && var[1] == 0)
		return (-3);
	else if (file[var[0]] == '\n' && ((var[2] + var[1]) % 4) == 0)
		var[0]++;
	else
		return (-1);
	if (file[var[0]] == '\n' || file[var[0]] == '\0')
	{
		if (var[3])
		{
			if (var[2] != 12 || var[1] != 4 || var[0] % 20 % var[3] != 0)
				return (-2);
		}
		else
		{
			if (var[2] != 12 || var[1] != 4 || var[0] % 20 != 0)
				return (-4);
		}
		e_m3(var);
		if (file[var[0]] == '\0')
			return (var[3]);
		else
			var[0]++;
	}
	return (var[3]);
}

int		ft_filechecker(char *file)
{
	int var[4];

	e_m2(var);
	while (file[var[0]] != '\0')
	{
		while (file[var[0]] != '\n')
		{
			if (file[var[0]] == '.')
				var[2]++;
			else if (file[var[0]] == '#')
				var[1]++;
			else
				return (-1);
			var[0]++;
		}
		if (aux_fug(file, var) < 0)
			return (-1);
	}
	return (var[3]);
}
